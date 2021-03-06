#include "mc9s12xdp512.h"




#include <stdio.h>

#include "cqueue.h"
#include <stdlib.h>
#include <stdarg.h>


#include "cqueue.h"
#include "sci.h"
#include "spi.h"
#include "adc.h"



#include "rti.h"
#include "pll_asm.h"

#include "LEDscreen.h"                    
#include "ws2812b.h"

#include "sci.h"

#define _putchar           (void)putchar
#define _printf            (void)printf

#define OK 0

//===========CMD Parser================================//

typedef struct

{
	unsigned char command;
	void (* exec)(void);

	
	
} CMD_STR;

unsigned char command_parser(CMD_STR *p2cmd);	
void Cmd_Set_Text(void);	
void Cmd_Set_Color(void);

void Cmd_Set_Speed(void);

void Cmd_Rd_Battery(void);
void Cmd_Set_Intensity(void);
void Cmd_Set_Party(void);

void Cmd_No_more_msj(void);	
void Unknown_Cmd(void);		  


#define END_OF_LIST 0xFF

CMD_STR commands[]= { 
					
					 {'T',Cmd_Set_Text },	      //text
					 {'C',Cmd_Set_Color},	      //color
					 {'S',Cmd_Set_Speed },	    //speed
					 {'I',Cmd_Set_Intensity },  // Set Intensity
					 {'B',Cmd_Rd_Battery },     // Battery Status
					 {'F',Cmd_Set_Party },     // Fiesta!!!
					 
					 
					 {EOT,Cmd_No_more_msj},
					 
					 {END_OF_LIST,Unknown_Cmd},
					 
					};
					 
	
	


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

/*
        

LEDSTR LedScreen1 [TEST_ROWS][TEST_COLS]={
{{0x01,0x02,0x03},{0x04,0x05,0x06},{0x07,0x08,0x09}},    // first 3 elem of first row (rest are zero)
{{0x10,0x20,0x30},{0x40,0x50,0x60},{0x70,0x80,0x90}},    // first 3 elem of second row (rest are zero)
{{0x11,0x12,0x13},{0x14,0x15,0x16},{0x17,0x18,0x19}},
{{0x21,0x22,0x23},{0x24,0x25,0x26},{0x27,0x28,0x29}},
};

*/

//int i,j;



static void system_init(void);
/////void init_display(void);

static unsigned char end_of_transmision = FALSE;
static unsigned char op_status;

unsigned char endsts=0;
unsigned char timsts=0; 
unsigned int adcval=0;


void WS2812B_Test(void);


void LEDtest2(void);
void LEDtest3(void);
void Scitest(void);


void test_delay(unsigned int dly); 


void Matrix2Vector(LEDSTR *);
void Set_Color(LEDSTR  );

void Set_Intensity(unsigned char new_intensity);


unsigned char Batt_Status(unsigned int bat_level );




LEDSTR DestLedScreen [TEST_ROWS*TEST_COLS];  // The data stored is sent directly to the RGB Led Display      

void PrintMatrix(LEDSTR * p2Matrix);

#define I_MAX   0x28      // Maxima intensidad  

//#define I_MAX   0x04      // Maxima intensidad     (At Home)

// Green  Red  Blue

//LEDSTR colorLEDsON = {0xff,0xff,0xff};           
//LEDSTR colorLEDsOFF = {0x00,0x00,0x00};



LEDSTR color={I_MAX,I_MAX,I_MAX};  // White (default)

//                     G     R     B
LEDSTR Led_Colors[]={{0x00 ,0x00 ,0x00 },     // Black
                     {0x00 ,0x00 ,I_MAX},     // Blue
                     {I_MAX,0x00 ,0x00 },     // Green
                     {I_MAX,0x00 ,I_MAX},     // Cyan (Blue+Green)
                     {0x00 ,I_MAX,0x00 },     // Red
                     {0x00 ,I_MAX,I_MAX},     // Magenta (Red +Blue)
                     {I_MAX,I_MAX,0x00 },     // Yellow   (Green + Red)                 
                     {I_MAX,I_MAX,I_MAX},     // White  
                     
};

#define C_Black   0
#define C_Blue    1
#define C_Green   2
#define C_Cyan    3
#define C_Red     4
#define C_Magenta 5
#define C_Yellow  6
#define C_White   7





#define DEFAULT_INTENSITY  I_MAX  // '0'


unsigned char Intensity_Table[]={I_MAX,I_MAX/2,I_MAX/4};  //'0'-'2'
unsigned char Led_intensity; 


void Cqtestbench(void);

void testbench_2(void);

void timetoshift(void)

{

_printf("shift\n") ;             


}



// -----------------------------------------------

#define DEFAULT_SPEED  20     // '3'
  
unsigned int speed; 

#define S_0  1  
#define S_1  5  
#define S_2  10  
#define S_3  20 
#define S_4  40  
#define S_5  50 
#define S_6  80 
#define S_7  100 
#define S_8  200 
#define S_9  300

unsigned int SpeedTable[]={S_0,S_1,S_2,S_3,S_4,S_5,S_6,S_7,S_8,S_9};    // 0-9


// -----------------------------------------------

#define MAX_TEXT_LEN 200
char textBuf[MAX_TEXT_LEN];
              
void main(void) {                          
  
 
               
 
 
 system_init();
 
  _asm cli;
  
  
// testbench_2();

 
//  for (;;) ;
 
 
 
/* 
 _asm cli;
 
  for (;;)
  Scitest();
*/
  
////  LEDtest2();   // OK!!

  _printf("Start");

  LEDtest3();
  
  
  

  
/// WS2812B_Test();                     


   
 
}




static void system_init(void) 
{



  _asm sei; 

  #ifdef FLASH     

 /////    pll_init();	  // solo para flash  (ver config.h)

  #endif				     
                           
    QueueInit();
    Sci_Init();


    PORTA = 0x00;
    DDRA = 0xFF;
    
    init_SPI();
    
    atd_init();
    
    rti_start();      

                 
    speed=DEFAULT_SPEED;   // message shift speed
    Led_intensity=DEFAULT_INTENSITY;
 
    
//    rti_init();

  _asm cli; 

}













/* This test sends data generated by LEDscreen.c 
   to screen   (OK)
 */
 

 

void LEDtest2(void) {        //// ojo no va mas   (only for tests)
  

    LEDSTR *p2Matrix=NULL;  
    
  //  LEDscreen_setShiftEnded_voidCallback(timetoshift);
        
    LEDscreen_setActualMSJ("HELLO");  
  //  LEDscreen_setMSJ("LIESL");  
    
    for (;;) {    
    
    p2Matrix=LEDscreen_getScreenAddress();
    
    PORTA |= 0x01;
     
    LEDscreen_ShiftMSJ();  // shift msg one colum left
    
    if( Get_End_Of_Shift_Status() == TRUE)   //Ckeck if the whole msg was sent
      
            _printf("Hallo Welt \n  ");
                                                  
    
    Matrix2Vector(p2Matrix);     // Convert Matrix to Vector
    
    
    
    Set_Color(color);      
    
    WS2812B_Init();
    
    WS2812B_Set_Data_pointer((unsigned char *)DestLedScreen);
    
    WS2812B_Set_Data_Length(32*8*sizeof(LEDSTR));
        
    WS2812B_Send_data();
    
    PORTA &= 0xFE;          //21.3 ms        
    
    //test_delay(100);        //24.8 ms     // Blocking W/software Timer
    
    
    rti_start();                     // Non Blocking W/hardware Timer
    
   Set_Timer_ms(25);
   while( Get_Timer_ms_Status())
   ;

//    delayms(25);   // Blocking W/hardware Timer

    rti_stop();
    
                                    
       _asm nop;
       _asm nop;   
       _asm nop;
       _asm nop;
    
    
  
    }
    
    
     
    
}    

#define TIME_OUT 1 

void LEDtest3(void) {
  

    LEDSTR *p2Matrix=NULL;  
    unsigned char temp;
//    unsigned char show_led=0;
    
    
    
 //   LEDscreen_setShiftEnded_voidCallback(timetoshift);
        
    LEDscreen_setActualMSJ("**C5N**");  
 
    
    for (;;) {    
    
      
    adcval=atd_getsample();
       
    _printf("ADC;%d \n",adcval);
    
    
  /////  putcspi0(show_led++);
    
    p2Matrix=LEDscreen_getScreenAddress();
    
    PORTA |= 0x01;
     
    LEDscreen_ShiftMSJ();  // shift msg one colum left
    
    if( Get_End_Of_Shift_Status() == TRUE)   //Ckeck if the whole msg was sent
    {
      
            //_printf("Hallo Welt \n  ");
            
             end_of_transmision = FALSE;
             
             Reset_FSM();
             
             QueueInit();
                        
             Sci1_Putchar(XON);     // HC05 Bluetooth
             
 ////////            rti_start();                     // Non Blocking W/hardware Timer
    
             Set_Timer_ms(3000);    // 3 seconds window
  
 
/* TIMER TEST 
             _printf("Timer in \n");
           while(1){
            
             if( Get_Timer_ms_Status()) {
              
                  _printf("Timer\n");
                    
                    Set_Timer_ms(1000);     
                        
             }
           }
TIMER TEST END*/           
		
     //// _printf("-(%c)[%.2X]-",ch,ch);   
    
             
    
              do    
              {
                    if(messages_count())
                    _printf("Remaining mess %d\n",messages_count());
                    
                    if(new_messages())
                         op_status=command_parser(commands);	// Process the cmd
            
              }
              
              while ((endsts=(end_of_transmision ==  FALSE)) && (timsts=(Get_Timer_ms_Status()!=TIME_OUT)));
            
               if(!endsts)
                   _printf("end_of_trans EOT\n");
               if(!timsts)
                  _printf("timeout EOT\n");                  
            
                                                             
             
           
       //////////////       rti_stop(); 
              
            
              while(QueueStatus())                  /// cleanup
	                op_status=PullQueue(&temp);
            
    
    }
    
    Matrix2Vector(p2Matrix);     // Convert Matrix to Vector
    
    Set_Color(color); 
    
    Set_Intensity(Led_intensity);
      
    
    WS2812B_Init();
    
    WS2812B_Set_Data_pointer((unsigned char *)DestLedScreen);
    
    WS2812B_Set_Data_Length(32*8*sizeof(LEDSTR));
        
    WS2812B_Send_data();
    
    PORTA &= 0xFE;          //21.3 ms        
    
    
 /// Set_Timer_ms(24);       // 24 ms   esto es normal velocidad posta
     
     
     Set_Timer_ms(speed); 
     while (Get_Timer_ms_Status()!=TIME_OUT) ;
     
   // test_delay(100);        //24.8 ms  (OLD)
    
  



                                    
       _asm nop;
       _asm nop;   
       _asm nop;
       _asm nop;
    
    
  
    }
    
    
     
    
}     




void test_delay(unsigned int dly)  {


unsigned int x,y,a; 


for (x=0;x<dly;x++)
    for (y=0;y<1000;y++)
      
            a+=1;


}







void Set_Color(LEDSTR grb_gain ) {

unsigned int n_pixels=TEST_ROWS*TEST_COLS;
unsigned char dest_index=0;

      while (n_pixels--) {
      
      
        DestLedScreen[dest_index].Green &=grb_gain.Green;
        DestLedScreen[dest_index].Red   &=grb_gain.Red ;
        DestLedScreen[dest_index].Blue  &=grb_gain.Blue ;
      
        dest_index++;
      }
       


}


// =================Matrix2Vector Index Table================= 



unsigned char RowIndex[]={0,1,2,3,4,5,6,7,7,6,5,4,3,2,1,0};
unsigned char ColUpdat[]={0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1};



/* ===========================================================
     Matrix2Vector() 

    Copies Text Scrolling Matrix to Linear Array

 * ===========================================================*/

void Matrix2Vector(LEDSTR* p2Matrix)      // 600 us ???  
{
          
          
unsigned char col_index=0;
unsigned char src_index=0;            
unsigned char dest_index=0;
unsigned int  n_pixels=TEST_ROWS*TEST_COLS;
      
      
      
      // copies all matrix pixels to Send Array
      while (n_pixels--) {
        
        DestLedScreen[dest_index++]=((LEDSTR(*)[32])p2Matrix)[RowIndex[src_index]][col_index];
            	
     	  col_index+=ColUpdat[src_index++];		// Update colum index
			  src_index&=0x0F;				            // modulo arithmetic for Row indexing
      }
  
}





/* TEST  Shows Source Matrix */

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
 



// to test power comsumtiom //

#include "testpat.h"   // Test patterns 

void WS2812B_Test(void) {
  
 WS2812B_Init();
 WS2812B_Set_Data_pointer(temp);
 WS2812B_Set_Data_Length(sizeof(temp)/sizeof(temp[0]));
 WS2812B_Send_data();
 for (;;) ;   // stop for test

}


/// ===========================000000000000000000000000000000======================================


/// ===========================000000000000000000000000000000======================================

/// ===========================000000000000000000000000000000======================================


#define ON 1
#define OFF 0
#define DEBUG ON



 

/* ------------- Comand Parser ------------------ */
	
unsigned char command_parser(CMD_STR *p2cmd)
{
	
	unsigned char cmd;
	
	if(QueueStatus())
	{
		op_status=PullQueue(&cmd);
			
		 _printf("$(%c)-[%.2X]$",cmd,cmd);
	
	
		while (p2cmd->command!= END_OF_LIST && p2cmd->command!=cmd)
				p2cmd++;
	
		(p2cmd->exec)();
		return(OK);
	}
	
	return(QEMPTY);	// Error queue is empty
	
}

//*****************************************
//
//      Cmd_Set_Text
//
//
//*****************************************

void Cmd_Set_Text(void)     
{

///#define MAX_TEXT_LEN 200
///char textBuf[MAX_TEXT_LEN];

unsigned int i=0;
unsigned char data=0;


   _printf("Set Text Cmd : ");
	do
	{
		if (QueueStatus())				    // some news?
			op_status=PullQueue(&data);
		else
			return;
						
	    
	  //_printf("%c",data);
	  //	 _printf("*(%c)-[%.2X]* ",data,data);
	  textBuf[i++]=data; 
	   
	  
	  if(i > MAX_TEXT_LEN-1) // Prevent  overwiting
	  {   
	  
	    textBuf[i]=0;            
	    return;
	  }
	  
	  
	  
	  
	} while (data);
	
	 textBuf[i]=data;
	

   LEDscreen_setActualMSJ(textBuf);
	
	 _printf("\n");
}

//*****************************************
//
//      Cmd_Set_Color
//
//
//*****************************************


void Cmd_Set_Color(void)
{


unsigned int i=0;
unsigned char data=0;                                                   


   _printf("Set Color Cmd : ");
   

		if (QueueStatus())				    // some news?
			op_status=PullQueue(&data);
		else
			return;
						
	    
	  _printf("%c",data);

   if ((data >= '0')  &&  (data <= '7') ) // Protect from unexpected data
    
	 color=Led_Colors[data-'0']; 

	 op_status=PullQueue(&data);  // Get terminator and discard
	
	 _printf("\n");
}



 //*****************************************
//
//      Cmd_Set_Speed
//
//
//*****************************************


void Cmd_Set_Speed(void)
{


unsigned int i=0;
unsigned char data=0;                                                   


   _printf("Set Speed Cmd : ");
   

		if (QueueStatus())				    // some news?
			op_status=PullQueue(&data);
		else
			return;
						
	    
	  _printf("%c",data);

   if ((data >= '0')  &&  (data <= '9') ) // Protect from unexpected data
    
	 speed=SpeedTable[data-'0']; 

	 op_status=PullQueue(&data);  // Get terminator and discard
	
	 _printf("\n");
}


 //*****************************************
//
//      Cmd_Set_Party
//
//
//*****************************************


void Cmd_Set_Party(void)
{


unsigned int i=0;
unsigned char data=0;                                                   


   _printf("Set Party Cmd : ");
                  

		if (QueueStatus())				    // some news?
			op_status=PullQueue(&data);
		else
			return;
						
	    
	  _printf("%c",data);

   if ((data >= '0')  &&  (data <= '1') ) // Protect from unexpected data
   {
    
	  if (data == '1') 
	  Set_Party_Mode_On();
	  if (data == '0')
	  Set_Party_Mode_Off();
	  
	 }
	  
	 

	 op_status=PullQueue(&data);  // Get terminator and discard
	
	 _printf("\n");
}




 //*****************************************
//
//      Cmd_Set_Intensity
//
//
//*****************************************


void Cmd_Set_Intensity(void)
{


unsigned int i=0;
unsigned char data=0;                                                   


   _printf("Set Intensity Cmd : ");
   

		if (QueueStatus())				    // some news?
			op_status=PullQueue(&data);
		else
			return;
						
	    
	  _printf("%c",data);

   if ((data >= '0')  &&  (data <= '2') ) // Protect from unexpected data
    
 	Led_intensity=Intensity_Table[data-'0']; 

	 op_status=PullQueue(&data);  // Get terminator and discard
	
	 _printf("\n");
}







void Set_Intensity(unsigned char new_intensity)

{


  if (color.Green==0 && color.Blue==0 && color.Red==0)

      return;

  else {
  
      if(color.Green)
    
         color.Green=new_intensity;
     
      
      if(color.Blue)
    
        color.Blue=new_intensity;
       
       
      if(color.Red)
    
         color.Red=new_intensity;
  }
}














 //*****************************************
//
//      Cmd_Rd_Battery
//
//
//*****************************************


void Cmd_Rd_Battery(void)
{



unsigned char data=0;                                                   


   _printf("Rd_Battery Cmd : ");
   

		if (QueueStatus())				    // some news?
			op_status=PullQueue(&data); // Get terminator and discard
		else
			return;
			
	 
	 
	 // send STX data ETX          data is Battery Status
	 	sendsci(STX);
	 	
//	 	sendsci('N');       // Mando estado de bateria

    
    adcval=atd_getsample();
	  	
	  sendsci(Batt_Status(adcval));
	 	
	 	sendsci(ETX);
	 
	 
	 
}


// Battery Return codes and Levels 

#define	NORMAL 	 '0'
#define	MEDIUM 	 '1'
#define	LOW	   	 '2'
#define	CRITICAL '3'

#define	NORMAL_LEVEL 	900
#define	MEDIUM_LEVEL 	700
#define	LOW_LEVEL	   	500 
#define	CRITICAL_LEVEL  300 


unsigned char Batt_Status(unsigned int bat_level )
{

unsigned char bat_status;
	
	if(bat_level >=NORMAL_LEVEL)
	
		bat_status=NORMAL;
	
	if(bat_level < NORMAL_LEVEL && bat_level >= MEDIUM_LEVEL)	
	
		bat_status=MEDIUM;
	
	if(bat_level < MEDIUM_LEVEL && bat_level >= CRITICAL_LEVEL)	
	
		bat_status=LOW;
		
		
	if(bat_level < CRITICAL_LEVEL)	
	
		bat_status=CRITICAL;
		
	return (bat_status);
	
}





void Unknown_Cmd(void)

{

	_printf("Unknown Cmd ");
	  _printf("\n");
}


void Cmd_No_more_msj(void)

{

	_printf("End of Tranmision\n");
	
	 end_of_transmision = TRUE;
	
}




/// ===========================000000000000000000000000000000======================================

/// ===========================000000000000000000000000000000======================================


/// ===========================000000000000000000000000000000======================================








// Cqueue TestBench         

void Cqtestbench(void)	// queue Test bench
{
unsigned char data;
unsigned char status;

	QueueInit();	// initialize queue
	
status=	PushQueue(1);	// Push something into the queue
status=	PushQueue(2);
status=	PushQueue(3);
	
	if(PushQueue(4)==QFULL)
	{
		_printf( "Queue Overflowed \n");
		return;
	}


	while (QueueStatus())		// some news?
	{
	status=PullQueue(&data); 	// if yes then get data from queue
		_printf( "Data pulled: %d , Remaining: %d   \n",data,QueueStatus());
	}

}




