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
unsigned int on_t;
unsigned int off_t;
unsigned int temp;

char b,c;

unsigned int a;
unsigned int init, final;

// Interrupt handler example for INT0
//

ISR(TIMER1_CAPT_vect){
 temp = ICR1;
 b = ICR1L;
 c = ICR1H;
 //rise detected
 if(a == 0){
   TCCR1B = (1<<CS10);
   init = temp;
   a++;
 }
 else if(a == 1){
   final = temp;
   a++;
   TCCR1B = ((1<<ICES1)|(1<<CS10));
   on_t = final - init;
   init = final;	
 }
 else if(a == 2){
   final = temp;
   a++;
   off_t = final - init;
   TCCR1B = 0x00;
   cli();
 }
}



// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//

// ***********************************************************
// Main program
//
int main(void) {

   a=0;
	DDRB = 0xFE;
	TCCR1A = 0x00;
	TIMSK = (1<<TICIE1);
	TCCR1B = ((1<<ICES1)|(1<<CS10));
	TIFR = (1<<ICF1);
	sei();
	
   while(a<3);

   a = 0;
   while(1) ;

}





