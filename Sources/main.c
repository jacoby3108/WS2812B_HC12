#include "mc9s12xdp512.h"



#include <stdio.h>
#include "sci.h"

#include "rti.h"
#include "pll_asm.h"

#include "LEDscreen.h"
#include "ws2812b.h"

#define _putchar            (void)putchar
#define _printf            (void)printf


// ===================================================================
//8 *32 Pixel WS2812B WS2812 Digital Color Flexible Led Panel Display
// ===================================================================

  
// LED Internal Structure 
   
/*
typedef struct// es GRB

{
  unsigned char Green;
  unsigned char Red ;
  unsigned char Blue;
  
}LEDSTR; 

*/




#define TEST_COLS 32
#define TEST_ROWS 8 


        

LEDSTR LedScreen1 [TEST_ROWS][TEST_COLS]={
{{0x01,0x02,0x03},{0x04,0x05,0x06},{0x07,0x08,0x09}},    // first 3 elem of first row (rest are zero)
{{0x10,0x20,0x30},{0x40,0x50,0x60},{0x70,0x80,0x90}},    // first 3 elem of second row (rest are zero)
{{0x11,0x12,0x13},{0x14,0x15,0x16},{0x17,0x18,0x19}},
{{0x21,0x22,0x23},{0x24,0x25,0x26},{0x27,0x28,0x29}},
};



//int i,j;



static void system_init(void);
/////void init_display(void);


void WS2812B_Test(void);
void LEDtest(void);
void LEDtest1(void);
void LEDtest2(void);
void Scitest(void);


void test_delay(unsigned int dly); 


void Matrix2Vector(LEDSTR *);
void Set_Intensity(LEDSTR  );

LEDSTR DestLedScreen [TEST_ROWS*TEST_COLS];  // The data stored is sent directly to the RGB Led Display      

void PrintMatrix(LEDSTR * p2Matrix);

void Test_Transfer(void);
 LEDSTR intensidad={0x30,0x30,0x30};

                       
void main(void) {                  
                                   
                                  
  
 
 
 
 system_init();
 
 _asm cli;
 
//  for (;;)
//  Scitest();
 
 Test_Transfer();
  
 // LEDtest2();   // NO ANDA

 // LEDtest1();  
  
  
  

  
// WS2812B_Test();                     


   
 
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


void Test_Transfer(void)
{

 int c;

 LEDSTR *p2Matrix=NULL;  
    
   

 _printf("Start .. \n\n ") ;
 
 _asm sei; //para que no moleste el monitor on getchar()
 
 LEDscreen_setMSJ("HOLA MUNDO");
 c=0;
 
 
 while (1) {
  
 
  while ((c=getchar())!='q');
  putchar(c);          
 
  c=0;                             

 
   
  p2Matrix=LEDscreen_getScreenAddress();  
   
  PrintMatrix(p2Matrix);
 
  Matrix2Vector(p2Matrix);  
 
  Set_Intensity(intensidad);      
    
  WS2812B_Init();
    
  WS2812B_Set_Data_pointer((unsigned char *)DestLedScreen);
    
  WS2812B_Set_Data_Length(32*8*sizeof(LEDSTR));
        
  WS2812B_Send_data();
   
  LEDscreen_ShiftMSJ();
 
 // test_delay(1000);

 }


  



}




#include "testpat.h"

void WS2812B_Test(void) {
  
 WS2812B_Init();
 WS2812B_Set_Data_pointer(temp);
 WS2812B_Set_Data_Length(sizeof(temp)/sizeof(temp[0]));
 WS2812B_Send_data();
 for (;;) ;   // stop for test
}




/* Prueba de Matrix2Vector function */

void LEDtest1(void)
{

   LEDSTR * p2M;
   p2M= (LEDSTR *)LedScreen1;
   Matrix2Vector(p2M);

}






/* This test sends data generated by LEDscreen.c 
   to screen   (NO ANDA)
 */
 
  LEDSTR *p2MatrixDeB; 
 

void LEDtest2(void) {
  
//  int k;

    LEDSTR *p2Matrix=NULL;  
    
   
        
    LEDscreen_setMSJ("HOLA MUNDO");  
    
    for (;;) {    
    
   p2Matrix=LEDscreen_getScreenAddress();
        
    p2MatrixDeB=   p2Matrix;  
        
        
   //for (k=0;k<9;k++)     
    LEDscreen_ShiftMSJ();                                                    
    
    Matrix2Vector(p2Matrix);  
    Set_Intensity(intensidad);      
    
    WS2812B_Init();
    
    WS2812B_Set_Data_pointer((unsigned char *)DestLedScreen);
    
    WS2812B_Set_Data_Length(32*8*sizeof(LEDSTR));
        
    WS2812B_Send_data();
    
    
    test_delay(1000);        
    
    
  
    }
    
    
     
    
}     


void test_delay(unsigned int dly)  {


unsigned int x,y,a; 


for (x=0;x<dly;x++)
    for (y=0;y<1000;y++)
      //for (z=0;z<1000;z++)
            a+=1;



}





/* This test evaluates how much time 
takes the LEDscreen_setMSJ to update
the screen */

void LEDtest(void) {
  
  LEDscreen_setMSJ("HOLA mundo");
    //programa principal                 
    for(;;) {
       
         PORTA |= 0x01;
        
       // LEDSTR *LEDscreen_getScreenData()
       // ws2812B();
        LEDscreen_ShiftMSJ();
         PORTA &= 0xFE;
        
       _asm nop;
       _asm nop;   
       _asm nop;
       _asm nop;
    }
   
  
}     


void Scitest(void) {
  
///////char c;
  
//   c=Sci1_Gechar();
//    Sci1_Putchar(c+1);



    //_putchar(0xA5);       // SCI 0
    //putchar(0xA5);         // SCI 0
    //putchar(0xA5);          // SCI 0
    //putchar(0xA5);           // SCI 0
    
    //_printf("  1234   ");         // SCI 0
   
   while (Sci1_GetQueueSatus()==EMPTY);           // SCI 1
   
   Sci1_Putchar(Sci1_GetQueueData()+2);
     
    
  
  
}



                            








unsigned char RowIndex[]={0,1,2,3,4,5,6,7,7,6,5,4,3,2,1,0};
unsigned char ColUpdat[]={0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1};



unsigned char col_index=0;
unsigned char src_index=0;
unsigned char dest_index=0;
unsigned int n_pixels=0; 


#define INTENSITY {0x30,0x30,0x30)


void Set_Intensity(LEDSTR grb_gain ) {

      n_pixels=TEST_ROWS*TEST_COLS;
      while (n_pixels--) {
      
      
        DestLedScreen[dest_index].Green &=grb_gain.Green;
        DestLedScreen[dest_index].Red   &=grb_gain.Red ;
        DestLedScreen[dest_index].Blue  &=grb_gain.Blue ;
      
        dest_index++;
      }
        


}



void Matrix2Vector(LEDSTR* p2Matrix)      // 600 us ???  
{
     // LEDSTR (*p2p)[32]=(LEDSTR (*)[32])p2Matrix;
      
      src_index=0;            
      dest_index=0;
      n_pixels=TEST_ROWS*TEST_COLS;
      
      // copies all matrix pixels to Send Array
      while (n_pixels--) {
        
       DestLedScreen[dest_index++]=((LEDSTR(*)[32])p2Matrix)[RowIndex[src_index]][col_index];
    
    
     
     //  DestLedScreen[dest_index++]=p2p[RowIndex[src_index]][col_index];
     //  DestLedScreen[dest_index++]=LedScreen1[RowIndex[src_index]][col_index]; // for test
     	
     	
     	  col_index+=ColUpdat[src_index++];		// Update colum index
			  src_index&=0x0F;				            // modulo arithmetic for Row indexing
      }
  
}



void PrintMatrix(LEDSTR * p2Matrix)

{
  int i,j ;
  //unsigned char x;
  
      for(i=0;i<8;i++) 
      {
        
            for(j=0;j<32;j++)
            
            {
            
               if(((LEDSTR(*)[32])p2Matrix)[i][j].Green==0xFF)
               _printf("%c",'*') ;
               else 
               _printf("%c",'-') ;
            
            
            }
            
        _printf("\n");
          
      }
}
 
