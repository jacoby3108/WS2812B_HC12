#include "mc9s12xdp512.h"

#include "sci.h"
#include "cqueue.h"


void sendsci(unsigned char tx);

static unsigned char rxdata;               //SCI driver rxdata 

void irq_sci_fsm(void);
static unsigned char Sci_State;
enum states {S_ILDE,S_STX,S_DATA};


static unsigned char op_status;

static unsigned char msg=0;




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
unsigned char Sci1_RxStatus(void){
  

  return (SCI1SR1 & SCI1SR1_RDRF_MASK);

}

//=======================================================
// Sci1_Putchar(char ) 
//
// Sends one byte to the serial Comunication interface 1
//=======================================================
void Sci1_Putchar(unsigned char ch) 
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


unsigned char Sci1_Gechar(void) 

{

    while (!(SCI1SR1 & SCI1SR1_RDRF_MASK));

    return SCI1DRL;      

}


// ***********************I*R*Q***S*C*I**********************************//

void interrupt ISR_sci(void) 
{     

   char scists;
   
   scists=SCI1SR1;
   rxdata=SCI1DRL;
  
 //  TERMIO_PutChar('[');
   TERMIO_PutChar(rxdata);
 //  TERMIO_PutChar(']');
   irq_sci_fsm();      
  

}

// *******************************************
// irq_sci_fsm(void) 
// This FSM implements a basic HDLC protocol
// *******************************************

void irq_sci_fsm(void)	
{	
	switch (Sci_State)		// Tiny FSM for SCI reception
	{
	
	//**************ILDE State*********************//
		case S_ILDE:		
		
			if(rxdata==ENQ)
				sendsci(ACK);
			else if(rxdata==STX)
				Sci_State=S_STX;	
		break;
	
		
	//**************STX State*********************//
		case S_STX:
	
			if(rxdata==ETX)
			{
							
//				_printf("SCI FSM: End Of Transmision\n");
				msg++;
				sendsci(ACK);
				op_status=PushQueue(EOT);
				Sci_State=S_ILDE;
				
			}
			else 
			{
				
				op_status=PushQueue(rxdata);
				Sci_State=S_DATA;
			}
		
		break;
		
//**************DATA State*********************//

		case S_DATA:
		
			if(rxdata==ETX)
			{
				
			
				
//				_printf("SCI FSM: End Of message\n");
				msg++;
				sendsci(ACK);
				op_status=PushQueue(0x00);
				Sci_State=S_ILDE;
				
			}
			else 
			{
				
				op_status=PushQueue(rxdata);
				
			}
				
	
			break;
	
		default:
	
	  do{
	  }while(0);   // err   
	  
 
//		_printf("SCI FSM: Unexpected Event\n ");
	
	
	}  // end  of Switch

} //end of irq

//// ************** END FSM ***************************


void sendsci(unsigned char tx)
{
	
	Sci1_Putchar(tx); 
 	
}

//*******************************************************************
// new_messages(void)
// 
// Returns how many messages 
// have been received and therefore pending
//
// Note A new message is avaiable when the following is recieved 
// STX Data ETX
// ******************************************************************

unsigned char new_messages(void)
{

  unsigned char temp;
  
  temp=msg;
  
  if(msg)
    msg--;

  return(temp);


}

unsigned char messages_count(void)
{

  

  return(msg);


}



//====================T E R M I O ===Support for SCI0==========
 

//=============================================================
// TERMIO_PutChar and  TERMIO_GetChar For SCI0   
//
// 
// Both are the link between SCI0 interface 
// and the C putchar() and getchar() functions
//
//           OJO SCI 0 la del Monitor 
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