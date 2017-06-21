// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

#define k 1000
// Define here the global static variables
//
int My_global;

int i;



// ***********************************************************
// Main program
//
int main(void) {
	
	
	DDRB = 0x07;
	DDRD = 0xFF;
	
	i = k;
	while(i>0) i--;
	
	
	PORTD = 0x30; //8-bit mode
	PORTB = 0x01;
	PORTB = 0x00;
	
	i = k;
	while(i>0) i--;
	
	PORTD = 0x0F; //turn on, cursor enable, blink
	PORTB = 0x01;
	PORTB = 0x00;
	
	i = k;
	while(i>0) i--;
		
	PORTD = 0x01; //clear,
	PORTB = 0x01;
	PORTB = 0x00;
	

	i = k;
	while(i>0) i--;
		
	PORTD = 0x80; //start address
	PORTB = 0x01;
	PORTB = 0x00;
	

	i = k;
	while(i>0) i--;
	
	PORTB = 0x05; //data selected	
	PORTD = 0x41;
	PORTB = 0x04;
	
	i = k;
	while(i>0) i--;
	
	PORTB = 0x05; //data selected	
	PORTD = 0x42;
	PORTB = 0x04;

	i = k;
	while(i>0) i--;
	
	
	PORTB = 0x05; //data selected	
	PORTD = 0x43;
	PORTB = 0x04;
	
   i = k;
	while(i>0) i--;
	
	PORTD = 0xC0; //start address
	PORTB = 0x01;
	PORTB = 0x00;
	
		i = k;
	while(i>0) i--;
	
	PORTB = 0x05; //data selected	
	PORTD = 0x44;
	PORTB = 0x04;
	
	i = k;
	while(i>0) i--;
	
	PORTB = 0x05; //data selected	
	PORTD = 0x45;
	PORTB = 0x04;

	i = k;
	while(i>0) i--;
	
	
	PORTB = 0x05; //data selected	
	PORTD = 0x46;
	PORTB = 0x04;
	


   while(1) {
   }

}



