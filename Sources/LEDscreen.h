//
//  LEDscreen.h
//  Interface
//
//  Created by Sergio N. Deligiannis on 29/5/15.
//  Copyright (c) 2015 Sergio N. Deligiannis. All rights reserved.
//

#ifndef __Interface__LEDscreen__
#define __Interface__LEDscreen__

#include <stdio.h>


#define LED_SCREEN_DIM_MATRIX 8  // Filas y columnas de un bloque de LEDs
#define LED_SCREEN_N_BLOCKS 4    // Cantidad de bloques de LEDs   0,1,2,...,N
// Cantidad de LEDs: 8x8 + 8X8 + 8x8 + 8x8
#define LED_SCREEN_MAX_CHARACTERS 200  // Para el mensaje


typedef struct
{
    unsigned char Green;
    unsigned char Red;
    unsigned char Blue;
}LEDSTR;


// Callback
void LEDscreen_setUserData(void *userData);
void LEDscreen_setShiftEnded_Callback(void (*userCallback)(void *userData));
void LEDscreen_setShiftEnded_voidCallback(void (*userVoidCallback)(void));
//
unsigned char LEDscreen_isBufferFree(void);
void LEDscreen_setMSJ(const  char *newMSJ);  
void LEDscreen_setLEDcolorON(LEDSTR color);
void LEDscreen_ShiftMSJ(void);
void LEDscreen_update(void);


LEDSTR *LEDscreen_getScreenAddress(void);
unsigned int LEDscreen_getScreenBytes(void);          


unsigned int Get_End_Of_Shift_Status(void);

#endif /* defined(__Interface__LEDscreen__) */
