#include<LPC214x.h>

int main(){
	
	AD0CR = (1<<1) | (5<<8) | (2<<17) | (1<<21);
	PINSEL1 |= (1<<24);
	IO1DIR = (0xFF<<16);
	IO1CLR = (0xFF<<16);
	
	while(1){
		AD0CR |= (1<<24);
		
		while(!(AD0DR1>>31));
	//	while(!(AD0DR1 & 0x80000000));
		IO1PIN = ((AD0DR1>>6) & 0x3FC)<<16;
	}
	return 0;
}
	
	