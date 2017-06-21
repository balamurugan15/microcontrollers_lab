#include<LPC214x.h>

#define l1 1
#define l2 3
#define l3 7
#define l4 15
#define l5 31
#define l6 63
#define l7 127
#define l8 255

unsigned int a,b;

int main(){
	
	AD0CR = (1<<1) | (5<<8) | (1<<16) | (1<<21);  //burst
	PINSEL1 |= (1<<24);
	IO1DIR = (0xFF<<16);
	IO1CLR = (0xFF<<16);
	
	while(1){
		while(!(AD0DR1>>31));
		
		a = AD0DR1>>6;
		b = a/128;
		
		if(a<153.46) IO1PIN = l1<<16;
		else if(a<(153.46 * 2)) IO1PIN = l2<<16;
		else if(a<(153.46 * 3)) IO1PIN = l3<<16;
		else if(a<(153.46 * 4)) IO1PIN = l4<<16;
		else if(a<(613.86 + 92.079)) IO1PIN = l5<<16;
		else if(a<(613.86 + 92.079 * 2)) IO1PIN = l6<<16;
		else if(a<(613.86 + 92.079 * 3)) IO1PIN = l7<<16;
		else if(a<(613.86 + 92.079 * 4)) IO1PIN = l8<<16;
	//	IO1PIN = ((AD0DR1>>6) & 0x3FC)<<16;
	}
}


	
	