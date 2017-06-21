#include<LPC214X.h>

int flag = 1;
int value ;

int i, temp;


void myDelay(int ms){  //max value delay 2^32 / ms 
	
	T0PR = 0x0; // no prescalar

  T0MCR = ( 1<<0 | 1<<1 ); //interrup enable, reset on match

	//T0MR0 = 0xE4E1C0; // FOR 1 SEC DELAY
	
	value = 0x3A98 * ms;  //0x3A98 = 1 ms delay count
	T0MR0 = value;
	
	T0TCR = 0x01; //timer on
	
	while(!(T0IR & 1));  //wait for interrupt flag
		
	T0IR = 0x1; //clear flag
	
	T0TCR = 0x0; // timer off
	
}

  

int main(void){

	PINSEL1 = (1<<19); //AOUT(DAC) selected
	
	while(1){
	
		myDelay(500);
		
		temp = 0x3FF/2;
		
		for(i = 0; i<4; i++){ 
		
		if(i<3){
			//flag = 0;
			DACR = (temp * i << 6);
		}
		else{
		  //flag = 1;
		  DACR = (temp * (4-i) << 6);
		}
	}
}


}