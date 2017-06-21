#include <LPC214X.h>

#define N 1000

int i;
int j;
long int temp ;

int main(void){
	
	IO1DIR = 0x00FF0000;
	
	while(1){
	
			IO1CLR = 0x00FF0000; //turn off all leds
		
			//IO1SET = 0x00000000;
			
			for(i=0;i<N;i++);
				
			IO1SET = 0x00010000; //turn on 1 led
			
			
			
			//turn on
			for(j=0;j<7;j++){
				
				for(i=0;i<N;i++);
				
				IO1SET = IO1SET<<1;
				
			}
			
			for(i=0;i<N;i++);
				
			//turn off
			
			IO1CLR = 0x00800000;
			 
			temp = 0x00800000;
			
			
			for(j=0;j<7;j++){
				
				for(i=0;i<N;i++);
				temp = temp >>1;
				IO1CLR = temp;
				
			}
			
			//odd on ; even off
			
			for(i=0;i<N;i++);
			
			IO1PIN = 0x00AA0000;
			
			//odd off ; even on
			
			for(i=0;i<N;i++);
			
			IO1PIN ^= 0x00FF0000;
			

			for(i=0;i<N;i++);
	
  }
	}
