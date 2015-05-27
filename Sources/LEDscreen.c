//
//  LEDscreen.c
//  Interface
//
//  Created by Sergio N. Deligiannis on 27/4/15.
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

unsigned char screen[DIM_MATRIX][N_BLOCKS * DIM_MATRIX];


/////////////////////////////////////////


void LEDscreen_setMSJ(const char *newMSJ)
{
    msjSize = 0;
    
    while(newMSJ[msjSize] != '\0')
    {
        msj[msjSize] = newMSJ[msjSize];
        msjSize++;
    }
    msj[msjSize] = '\0';
    
}

void LEDscreen_update(void)
{

    // hay que usar unsigned char screen[8][32];
    
}

void LEDscreen_ShiftEnded(void)
{
    LEDscreen_setMSJ("HOLA");
}


const unsigned char* LEDscreen_decode_MSJ(const char data)
{
    int pos=0;
    const unsigned char* retAddr = 0;
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
    
    const unsigned char* symbolAddrFirst = 0;
    const unsigned char* symbolAddrSecond = 0;
    char data[DIM_MATRIX];
    int  i=0, j=0,k=0,iBlock=0;
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
                screen[j][k+iBlock*DIM_MATRIX] = ((data[j] & (0x80>>k))>0);
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

