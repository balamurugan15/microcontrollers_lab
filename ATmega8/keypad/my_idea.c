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

   DDRB = 0x0C;
   PORTB = 0x03;
   DDRC = 0x0F;
   PORTC = 0xFF;

   while(1) {
   		PORTB = 0x0B;
   		if(!(PINB & 0x01))
   			PORTC = ~(0x01);
   		else if(!(PINB & 0x02))
   			PORTC = ~(0x04);
   		
   		PORTB = 0x07;
   		if(!(PINB & 0x01))
   			PORTC = ~(0x02);
   		else if(!(PINB & 0x02))
   			PORTC = ~(0x08);
        }

}

