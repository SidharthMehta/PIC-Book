//2 switch control of led

#include<pic.h>				//header files

void main()
{	
	TRISC=0x00;				//Set PORTC pins as output
	TRISD=0x03;				//Set PD0 pin and PD1 pin as input
	PORTC= 0x00;			//Reset PORTC pins as LOW
	while(1)				//Infinite loop
		if(RD0==0)			//Switch on led on pressing RD0 
			PORTC=0xFF;		//Set PORTC pins as HIGH
		else if(RD1==0)		//Switch off on pressing RD1 
			PORTC=0x00;		//Reset PORTC pins as LOW
}
