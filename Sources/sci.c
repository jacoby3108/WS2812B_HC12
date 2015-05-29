#include "mc9s12xdp512.h"

#include "sci.h"


//static unsigned char sci_int = SCI_EMPTY;  //SCI driver rx Flag =  SCI_FULL if data was received

static unsigned char rxdata,RxQueueStatus;               //SCI driver rx data contains valid data when sci_int= SCI_FULL


// Driver Init

void Sci_Init(void) {



    SCI1BD = 260; // SCI_Baud= BusClk/(16*BD_reg)=9615.38
    
    SCI1CR1 = 0;   // Set Default Values 8 bit No parity 1 Stop  
        

    //Transmit & Receive Enable

    SCI1CR2 |= (SCI1CR2_TE_MASK|SCI1CR2_RE_MASK); 
    
    // Rx interrupt enable 
    
    SCI1CR2 |=  SCI1CR2_RIE_MASK; 

  
}


// Driver Services

//========================================
// Sci1_RxStatus() 
//
// Returns 1 if one byte has been recieved
//=========================================
char Sci1_RxStatus(void){
  

  return (SCI1SR1 & SCI1SR1_RDRF_MASK);

}

//=======================================================
// Sci1_Putchar(char ) 
//
// Sends one byte to the serial Comunication interface 1
//=======================================================
void Sci1_Putchar(char ch) 
{

    while (!(SCI1SR1 & SCI1SR1_TDRE_MASK));

    SCI1DRL = ch;

}

//=============================================================
// Sci1_Getchar(char ) 
//
// Retrieves one byte from serial Comunication interface 1
//
// Note Call Sci1_RxStatus() before calling Sci1_Getchar(char)
//
//            if( Sci1_RxStatus() )
//                    Sci1_Getchar(char); 
//
//=============================================================


char Sci1_Gechar(void) 

{

    while (!(SCI1SR1 & SCI1SR1_RDRF_MASK));

    return SCI1DRL;

}


void interrupt ISR_sci(void) 
{     

   char scists;
   
           scists=SCI1SR1;
           rxdata=SCI1DRL;
          
           RxQueueStatus=FULL;

}

char Sci1_GetQueueSatus(void){
  
  char temp;
  
    temp=RxQueueStatus;
    
    if(RxQueueStatus==FULL)
       RxQueueStatus=EMPTY;

  return (temp);

}

char Sci1_GetQueueData(void){
  

  return (rxdata);

}






//============================T E R M I O =====================
 

//=============================================================
// TERMIO_PutChar and  TERMIO_GetChar For SCI0   
//
// 
// Both are the link between SCI0 interface 
// and the C putchar() and getchar() functions
//
//           OJO SCI 0
//=============================================================


void TERMIO_PutChar(char ch) 

{

    while (!(SCI0SR1 & SCI0SR1_TDRE_MASK));

    SCI0DRL = ch;

}



char TERMIO_GetChar(void) 

{

    while (!(SCI0SR1 & SCI0SR1_RDRF_MASK));

    return SCI0DRL;

}