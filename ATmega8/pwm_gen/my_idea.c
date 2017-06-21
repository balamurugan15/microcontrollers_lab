// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

// Define here the global static variables
//
int My_global;





// ***********************************************************
// Main program
//
int main(void) {

   DDRB = 0x02;
   DDRC = 0x01;
	TCCR1A = (1<<COM1A1) | (1<<WGM11) | (1<<WGM10);
	OCR1AH = 0x01;
	OCR1AL = 0xFF;
	TCCR1B = (1<<CS10);
	
	
   while(1) {             // Infinite loop; define here the
		
		if(PINB & 0x02)
			PORTC = PORTC | 0x01;
		else PORTC = PORTC & 0xFE; 	
   }

}

