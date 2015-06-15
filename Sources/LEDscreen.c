//
//  LEDscreen.c
//  Interface
//
//  Created by Sergio N. Deligiannis on 29/5/15.
//  Copyright (c) 2015 Sergio N. Deligiannis. All rights reserved.
//  

#include "LEDscreen.h"
#include "characters8x8.h"


//#define DIM_MATRIX 8  // Filas y columnas de un bloque de LEDs
//#define N_BLOCKS 4    // Cantidad de bloques de LEDs   0,1,2,...,N
// Cantidad de LEDs: 8x8 + 8X8 + 8x8 + 8x8

//#define MAX_CHARACTERS 200


#define DIM_MATRIX LED_SCREEN_DIM_MATRIX
#define N_BLOCKS LED_SCREEN_N_BLOCKS

#define MAX_CHARACTERS LED_SCREEN_MAX_CHARACTERS


const unsigned char* LEDscreen_decode_MSJ(const char data);
void LEDscreen_ShiftEnded(void);

char msj[MAX_CHARACTERS] = "ITBA";
int msjSize = 4;
char nextMsj[MAX_CHARACTERS] = "ITBA";
int nextMsjSize = 4;

LEDSTR colorLEDsON = {0xff,0xff,0xff};
LEDSTR colorLEDsOFF = {0x00,0x00,0x00};


static LEDSTR LedScreen[LED_SCREEN_DIM_MATRIX][LED_SCREEN_N_BLOCKS * LED_SCREEN_DIM_MATRIX];


/////////////////////////////////////////

LEDSTR *LEDscreen_getScreenData(void)
{
    return (LEDSTR *)LedScreen;
}

unsigned int LEDscreen_getScreenBytes(void)
{
    return sizeof(LEDSTR) * LED_SCREEN_DIM_MATRIX * LED_SCREEN_N_BLOCKS * LED_SCREEN_DIM_MATRIX; // 3 por las estructura de LEDs
}

void LEDscreen_setMSJ(const char *newMSJ)
{
    nextMsjSize = 0;
    
    while(newMSJ[nextMsjSize] != '\0')
    {
        nextMsj[nextMsjSize] = newMSJ[nextMsjSize];
        nextMsjSize++;
    }
    nextMsj[nextMsjSize] = '\0';
    
}

void LEDscreen_setLEDcolorON(LEDSTR color)
{
    colorLEDsON = color;
}

void LEDscreen_update(void)
{

    
    // hay que usar: LEDSTR LedScreen[LED_SCREEN_DIM_MATRIX][LED_SCREEN_N_BLOCKS * LED_SCREEN_DIM_MATRIX];
    
}

void LEDscreen_ShiftEnded(void)
{
    msjSize = 0;
    
    while(nextMsj[msjSize] != '\0')
    {
        msj[msjSize] = nextMsj[msjSize];
        msjSize++;
    }
    msj[msjSize] = '\0';
    
    /*
    static int i=0;
    if(i==0)
    {
        colorLEDsON.Green = 0xff;
        colorLEDsON.Blue = 0x00;
        colorLEDsON.Red = 0x00;
    }
    else if(i==1)
    {
        colorLEDsON.Green = 0x00;
        colorLEDsON.Blue = 0xff;
        colorLEDsON.Red = 0x00;
    }
    else if(i==2)
    {
        colorLEDsON.Green = 0x00;
        colorLEDsON.Blue = 0x00;
        colorLEDsON.Red = 0xff;
    }
    else if(i==3)
    {
        colorLEDsON.Green = 0xff;
        colorLEDsON.Blue = 0xff;
        colorLEDsON.Red = 0xff;
    }

    i++;
    if(i>=4)
        i=0;
    */
}




const unsigned char* LEDscreen_decode_MSJ(const char data)
{
    int pos=0;
    const unsigned char* retAddr = NULL;
    if(data >= 'a' && data <= 'z')
    {
        pos = data - 'a';
        retAddr = LetrasMay[pos];
    }
    else if(data >= 'A' && data <= 'Z')
    {
        pos = data - 'A';
        retAddr = LetrasMay[pos];
    }
    
    else if(data >= '0' && data <= '9')
    {
        pos = data - '0';
    }
    else if(data == ' ')
        retAddr = Space;
    else if(data == '!')
        retAddr = Exclamacion;
    else if(data == '.')
        retAddr = Dot;              
                                      
    
    return retAddr;
    
    
}

/////////////////////////////////////////

void LEDscreen_ShiftMSJ(void)
{
    static int iShift=0;
    
    const unsigned char* symbolAddrFirst = NULL;
    const unsigned char* symbolAddrSecond = NULL;
    unsigned char data[DIM_MATRIX],k=0;
    int  i=0, j=0,iBlock=0;
    int Shift=0;
    
   
    
    for(iBlock=0 ; iBlock < N_BLOCKS ; iBlock++)
    {
        i = (iShift-(N_BLOCKS-iBlock)*DIM_MATRIX)/DIM_MATRIX;
        Shift = (iShift-(N_BLOCKS-iBlock)*DIM_MATRIX)%DIM_MATRIX;
        if(i>=0 && i<=msjSize)
        {

        
        if(iShift < (DIM_MATRIX*(1+N_BLOCKS-iBlock)))  // Primera letra Aparece
        {
            symbolAddrFirst = LEDscreen_decode_MSJ(msj[i]);
            for(j=0 ; j < DIM_MATRIX ; j++)
                data[j] = (symbolAddrFirst[j])>>(DIM_MATRIX-1-Shift);
            
        }
        else if(((msjSize+(N_BLOCKS-iBlock))*(DIM_MATRIX)) <= iShift) // Ultima letra desaparece
        {
            i--; // Porque es el ultimo i == msjSize
            symbolAddrSecond = LEDscreen_decode_MSJ(msj[i]);
            for(j=0 ; j < DIM_MATRIX ; j++)
                data[j] = (symbolAddrSecond[j])<<(Shift+1);
            
        }
        else
        {
            symbolAddrFirst = LEDscreen_decode_MSJ(msj[i-1]);
            symbolAddrSecond = LEDscreen_decode_MSJ(msj[i]);
            for(j=0 ; j < DIM_MATRIX ; j++)
            {
                data[j] = (symbolAddrFirst[j])<<(Shift+1);
                data[j] |= (symbolAddrSecond[j])>>(DIM_MATRIX-1-Shift);
            }
            
        }
        }
        else
        {
            for(j=0 ; j < DIM_MATRIX  ; j++)
                    data[j] = 0;
        }
        
        
    
        for(j=0 ; j < DIM_MATRIX  ; j++)
        {
            for(k=0 ; k < DIM_MATRIX  ; k++)
            {
                if(((data[j] & (0x80>>k))>0))
                    LedScreen[j][k+iBlock*DIM_MATRIX] = colorLEDsON;
                else
                    LedScreen[j][k+iBlock*DIM_MATRIX] = colorLEDsOFF;
                    
            }
        }
    }
    
    iShift++;
    if(iShift >= ((msjSize+1+N_BLOCKS)*DIM_MATRIX))
    {
        LEDscreen_ShiftEnded();
        iShift=0;
    }
    
    
}

