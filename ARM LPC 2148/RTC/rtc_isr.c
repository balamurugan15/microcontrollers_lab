#include<LPC214x.h>

#define PCLK 15000000	


void my_rtc_isr() __irq
{
	IO1SET = (1<<16);
	VICVectAddr = 0 ;
}


int main(){


	IO1DIR = (1<<16);
	IO1CLR = (1<<16);
 
  CCR = 0x00; //disable
	
	SEC = 30;
	HOUR = 9;
	MIN = 35;
	DOM = 30;
	DOW = 5;
	DOY = 85;
	MONTH = 3;
	YEAR = 2017;
	
	ALSEC = 35;
	ALMIN = 35;
	ALHOUR = 9;
	
	AMR = (1<<3) | (1<<4) | (1<<5)| (1<<6) | (1<<7);
	
	PREINT = (int)(PCLK / 32768) - 1;
	PREFRAC = PCLK - ((PREINT + 1) * 32768);
	
	VICVectCntl0 = 13 | (1<<5);
	//VICIntSelect default irq
	VICVectAddr0 = (long) (my_rtc_isr);
	VICIntEnable |= (1<<13);
	
	
	CCR = 0x01; // enable

	//while(!(ILR & (0x02)));
	
	

	while(1){
	}
	
	return 0;
}
