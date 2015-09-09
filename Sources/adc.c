#include "mc9s12xdp512.h"     
#include "adc.h"

// WARNING Dont use ANALOG INPUTS  00 01 08 (ATD0) since they are connected to Board jumpers


#define ADCH2  2       //Canal de medicion H2 pin 15

void atd_init(void)
{	
	// **********  Control Register 2 ******************

	ATD0CTL2 |= ATD0CTL2_ADPU_MASK;				// Turn on the ADT0
	ATD0CTL2 |= ATD0CTL2_AFFC_MASK; 			// Clear flags when regiser is read
	//ATD0CTL2 |= ATD0CTL2_ASCIE_MASK;		// interrupt when conv finished

 
 
 
 	// **********  Control Register 3 ******************
 	
	ATD0CTL3 |= ATD0CTL3_S2C_MASK;				// sequence lenght=2
	
 
 
 
 
 
 
 	// **********  Control Register 4 ******************

 	
	//ATD0CTL4 |= ATD0CTL4_SRES8_MASK;	//10 bit resolution
	
	ATD0CTL4 |= ATD0CTL4_SMP_MASK;		//16 A/D conversion clock periods
	
	ATD0CTL4 |= 0x09;									// Prescaler /20 i.e. 40MHZ / 20= 2Mhz 



   

// **********  Control Register 4 ******************


	ATD0CTL5 |= ATD0CTL5_DJM_MASK;					//Right justified 000000 B9 B8...
	//ATD0CTL5 |= ATD0CTL5_DSGN_MASK;				//UnSigned data representation 
	//ATD0CTL5 |= ATD0CTL5_SCAN_MASK;   		//One conversion sequence 
	//ATD0CTL5 |= ATD0CTL5_MULT_MASK;				//Sample on same channel
	ATD0CTL5 |= ADCH2;						          //start in channel 2
	



 									

}

// Returns 10bit convertion 

unsigned int atd_getsample(void) 
{	
		

	ATD0CTL5 |= ADCH2;   // Start conversion  on channel 2
	
	while(!(ATD0STAT0 & ATD0STAT0_SCF_MASK)){};  // Wait EOC
	return ATD0DR0;								
	
	
}
