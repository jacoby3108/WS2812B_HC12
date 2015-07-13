#include "mc9s12xdp512.h"
#include "rti.h"

static volatile unsigned int rti_dly;

// A write to the RTICTL register restarts the RTI time-out period.
// MC9S12XDP512 Data Sheet, Rev. 2.15 page 103
			  
void rti_start(void) 
{
    
    //RTICTL = 0x50 ;                       // Binary divider  (16MHz / 2^14) = 0.976 mseg ~ 1mseg
    
    RTICTL = 0x0F | RTICTL_RTDEC_MASK;      // Decimal divider (16MHz / 16E3) = 1mseg
    
    CRGFLG = CRGFLG_RTIF_MASK;              // Clear RTI Inerrupt mask
   
    CRGINT |= CRGINT_RTIE_MASK;             // Enable RTI Interrupt
 
    rti_dly = 0;			                      // delay counter start in reset state  	   
}


void rti_stop(void) 
{
    
    _asm sei;
    
    RTICTL = 0x00;                           // RTI off
    
    CRGFLG = CRGFLG_RTIF_MASK;              // Clear RTI Inerrupt mask
   
    CRGINT = 0x00;                          // Disable RTI Interrupt
 
    _asm cli; 	   
}








void delayms(unsigned int dly)      // Blocking delay
{
    // set delay
 
  CRGINT &= ~CRGINT_RTIE_MASK;
	
	rti_dly = dly;	    
	
	CRGFLG =  CRGFLG_RTIF_MASK;
  
  CRGINT |= CRGINT_RTIE_MASK;
	
	// and wait
	while (rti_dly);    
}

void Set_Timer_ms(unsigned int dly)     // Non Blocking delay
{
    // set delay
 
  CRGINT &= ~CRGINT_RTIE_MASK;
	
	rti_dly = dly;	    
	
	CRGFLG =  CRGFLG_RTIF_MASK;
  
  CRGINT |= CRGINT_RTIE_MASK;

	 
}

unsigned char Get_Timer_ms_Status(void)      // Non Blocking delay Status 
{
 	
  return(	rti_dly );	    

	 
}






void interrupt ISR_rti(void) 
{     

  //acá llego cada 1 mseg
	
	// bajo la bandera
	CRGFLG = CRGFLG_RTIF_MASK;  
	
	//Toggle PA1 (DEBUG)
///	PORTA ^= 0x02;     
	
	// pump down user timer  
	if (rti_dly) rti_dly--;

}



