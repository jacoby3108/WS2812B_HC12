#include "mc9s12xdp512.h"



#include <stdio.h>
#include "sci.h"

#include "rti.h"
#include "pll_asm.h"

#include "LEDscreen.h"
#include "ws2812b.h"

#define _putchar            (void)putchar
#define _printf            (void)printf


// This array is for testing WS2812B DIN on osciloscope

unsigned char temp[]={0xA5,0x5A};

   
   
/*
typedef struct// es GRB

{
  unsigned char Green;
  unsigned char Red ;
  unsigned char Blue;
  
}LEDSTR; 

*/

LEDSTR LedScreen [8][5]={
{{1,2,3},{4,5,6},{7,8,9}},             // first 3 elem of first row (rest are zero)
{{0x10,0x20,0x30},{0x40,0x50,0x60},{0x70,0x80,0x90}}    // first 3 elem of second row (rest are zero)
};

unsigned char *p2led=NULL;
LEDSTR *p2led2=NULL;
int i,j;



static void system_init(void);
void init_display(void);
void LEDtest(void);
void Scitest(void);
void pointerAccessTest(void);







                       
void main(void) {                  
                                   



  
 
 system_init();
 
 _asm cli;
 
// for (;;)
///  Scitest();
 
 
 WS2812B_Init();
    
 WS2812B_Set_Data_pointer(temp);
 WS2812B_Set_Data_Length(2);
 WS2812B_Send_data();
 for (;;) ;   // stop for test
 
 
   
 
}




static void system_init(void) 
{


  #ifdef FLASH     

    pll_init();	  // solo para flash  (ver config.h)

  #endif				     
    
    Sci_Init();


    PORTA = 0x00;
    DDRA = 0xFF;
    
//    rti_init();
}



//*************** TEST AREA ***************//

/* This test evaluates how much time 
takes the LEDscreen_setMSJ to update
the screen */

void LEDtest(void) {
  
  LEDscreen_setMSJ("HOLA mundo");
    //programa principal                 
    for(;;) {
       
         PORTA |= 0x01;
        
       
        LEDscreen_ShiftMSJ();
         PORTA &= 0xFE;
        
       _asm nop;
       _asm nop;   
       _asm nop;
       _asm nop;
    }




  
   
  
}     


void Scitest(void) {
  
char c;
  
//   c=Sci1_Gechar();
//    Sci1_Putchar(c+1);



    //_putchar(0xA5);       // SCI 0
    //putchar(0xA5);         // SCI 0
    //putchar(0xA5);          // SCI 0
    //putchar(0xA5);           // SCI 0
    
    //_printf("  1234   ");         // SCI 0
   
   while (Sci1_GetQueueSatus()==EMPTY);           // SCI 1
   
   Sci1_Putchar(Sci1_GetQueueData());
     
    
  
  
}



void pointerAccessTest(void)
{
  
  p2led=(unsigned char *)LedScreen;  // This pointer will access array bytes
  p2led2 =(LEDSTR *) LedScreen;    // This pointer will access array elements
   
  p2led2->Blue=255;
  p2led2++;
  p2led2->Red=255;
  p2led2++;
  p2led2->Green=255;

  for(i=0;i<24;i++){
    
      *p2led=0x33;
      p2led++;
  }


}