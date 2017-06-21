// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#include <util\delay.h>

#define k 1000
// Define here the global static variables
//
int My_global;

int i;

void delay(){
	_delay_ms(15);
	
/*	i = k;
	while(i>0) i--; */
}

void writeCommand(){
	PORTB = 0x01; //command selected
	PORTB = 0x00;
}

void writeData(){
   PORTB = 0x05; //data selected	
	PORTB = 0x04;
}



// ***********************************************************
// Main program
//
int main(void) {
	
	
	DDRB = 0x07;
	DDRD = 0xFF;	
	delay();
	
	
	PORTD = 0x30; //8-bit mode
	writeCommand();
	delay();
	
	PORTD = 0x0F; //turn on, cursor enable, blink
   writeCommand();
	delay();
		
	PORTD = 0x01; //clear
	writeCommand();
	delay();
		
	PORTD = 0x80; //start address line 1
	writeCommand();
	delay();
	
	PORTD = 0x41; //data - 'A'	
	writeData();
	delay();
	
	PORTD = 0x42; //data - 'B'	
	writeData();
	delay();
	
	
	PORTD = 0x43; //data 'C'	
	writeData();
	delay();
	
	PORTD = 0xC0; //start address line 2
	writeCommand();
	delay();
	
	PORTD = 0x44;  //data 'D'	
	writeData();
	delay();
	
	PORTD = 0x45;  //data 'E'	
	writeData();
	delay();
	
	PORTD = 0x46;  //data 'F'	
	writeData();
	delay();

   while(1) {
   }

}





