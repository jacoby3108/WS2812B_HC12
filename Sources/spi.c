

#include "spi.h"

#include "mc9s12xdp512.h"

// SCK0  pin 11 H4   (Clk in 74HC595)
// MOSI0 pin 10 H4   (Data in 74HC595)
// SS0   pin 12 H4   (LOAD 74HC595)

  

// Driver Init

void init_SPI(void) {
 
  DDRS=DDRS |PTS_PTS7_MASK ;      // SS Out  (latch for 74HC595)
  PTS_PTS7=1;                     // SS Ilde (latch for 74HC595)
           
  // Bus Clock 40MHz 

  SPI0BR = ( 0b100 << SPI0BR_SPPR_BITNUM ) | ( 0b010 << SPI0BR_SPR_BITNUM );	  // set baud BusCLk / 40   1MHz
	SPI0CR1=SPI0CR1_SPE_MASK | SPI0CR1_MSTR_MASK;       //latched on rising edge, data transferred msb first
	SPI0CR2=0x00;         
//	WOMS =0;              //enable Port S pull-up
	
}


// Driver ISR



// Driver Services
 
 
 
void putcspi0 (char cx)
{
	    char 	temp;
	    
	    PTS_PTS7=0; // SS Low     (latch for 74HC595)
	    
     	while(!(SPI0SR & SPI0SR_SPTEF_MASK)); 	/* wait until write is permissible */
     	SPI0DR = cx;              	            /* output the byte to the SPI */
     	while(!(SPI0SR & SPI0SR_SPIF_MASK));  	/* wait until write operation is complete */
	    temp 	= SPI0DR;	                        /* clear the SPIF flag */
	    
	    PTS_PTS7=1; // SS goes Hi (latch for 74HC595 rising edge Shift regitrer is transfered to parallel outpus)
	    
	    
}


char getcspi0(void)
{
      char algo=0x045;
     	while(!(SPI0SR & SPI0SR_SPTEF_MASK)); 	/* wait until write is permissible */
     	SPI0DR = algo; 	                        /* trigger 8 SCK pulses to shift in data */
     	while(!(SPI0SR & SPI0SR_SPIF_MASK));  	/* wait until a byte has been shifted in */
     	return SPI0DR; 	                        /* return the character */
}






