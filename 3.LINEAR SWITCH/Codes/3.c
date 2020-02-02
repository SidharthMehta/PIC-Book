//question 3

#include<pic.h>				//header files

void main()
{	
	TRISC=0x00;				//Set PORTC pins as output
	TRISD=0x07;				//Set PD0,1,2,3 pins as input
	PORTC= 0x00;			//Reset PORTC pins as LOW
	while(1)				//Infinite loop
		if(RD0==0)			//IF button connected to RD0 is pressed we get 0 
			PORTC=0x0F;		//Set lower 4 PORTC pins as HIGH and switch on first 4 LED
		else if(RD1==0)		//IF button connected to RD1 is pressed we get 0
			PORTC=0xF0;		//Set higher 4 PORTC pins as HIGH and switch on last 4 LED
		else if(RD2==0)		//IF button connected to RD2 is pressed we get 0
			PORTC=0x00;		//Reset PORTC pins and switch off all LED
}