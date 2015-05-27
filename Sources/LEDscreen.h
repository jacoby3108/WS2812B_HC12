//
//  LEDscreen.h
//  Interface
//
//  Created by Sergio N. Deligiannis on 27/4/15.
//  Copyright (c) 2015 Sergio N. Deligiannis. All rights reserved.
//

#ifndef __Interface__LEDscreen__
#define __Interface__LEDscreen__



#define LED_SCREEN_DIM_MATRIX 8  // Filas y columnas de un bloque de LEDs
#define LED_SCREEN_N_BLOCKS 4    // Cantidad de bloques de LEDs   0,1,2,...,N
// Cantidad de LEDs: 8x8 + 8X8 + 8x8 + 8x8
#define LED_SCREEN_MAX_CHARACTERS 200  // Para el mensaje


void LEDscreen_setMSJ(const char *newMSJ);
void LEDscreen_ShiftMSJ(void);
void LEDscreen_update(void);




#endif /* defined(__Interface__LEDscreen__) */
