#include<LPC214X.h>
#include<math.h>

int flag = 1;
int value ;

int i, temp;

float t2;


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
	
	t2 = 2 * 3.14 /30;
	
	while(1){
	
		
		
		temp = 0x3FF/30;
		
		for(i = 0; i<30; i++){ 
		
			/*	if(i<16){
					//flag = 0;
					DACR = (temp * i << 6);
				}
				else{
					//flag = 1;
					DACR = (temp * (30-i) << 6);
				} */
			
			  DACR = (int)(((sin(t2 * (float)(i))) * 0x3FF/2) + (0x3FF/2)) << 6; 
				
				myDelay(1);
	}
}


}