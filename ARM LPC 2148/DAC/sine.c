#include<LPC214X.h>
#include<math.h>

int flag = 1;
int value ;

int i, temp;

int t2;


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
	
	t2 = 2* 3.1415 /30;
	
	while(1){
	
		
		
		temp = 0x3FF/15;
		
		for(i = 0; i<30; i++){ 
		
			/*	if(i<16){
					//flag = 0;
					DACR = (temp * i << 6);
				}
				else{
					//flag = 1;
					DACR = (temp * (30-i) << 6);
				} */
			
			  DACR = (sin(t2 * i)) * 0x3FF; 
				
				myDelay(1);
	}
}


}