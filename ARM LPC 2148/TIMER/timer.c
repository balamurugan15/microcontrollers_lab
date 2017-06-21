#include<LPC214x.h>


int value;

void myDelayInit(int ms){  //max value delay 2^32 / ms 
	
	T0PR = 0x0; // no prescalar

  T0MCR = ( 1<<0 | 1<<1 ); //interrup enable, reset on match

	//T0MR0 = 0xE4E1C0; // FOR 1 SEC DELAY
	
	value = 0x3A98 * ms;  //0x3A98 = 1 ms delay count
	T0MR0 = value;
	
	T0TCR = 0x01; //timer on

}

int main(void){

	IO0DIR = (1<<25);

	myDelayInit(1000);  //1 sec

	while(1){
	
		while(!(T0IR & 1));  //wait for interrupt flag
			
		T0IR = 0x1; //clear flag
		
		IO0PIN ^= (1<<25);
		
	}

}
