//switch on key press

#include<pic.h>				//header files

void main()
{
	TRISC=0x00;				//Set PORTC pins as output
	TRISD=0x01;				//Set PD0 pin as input
	if(RD0==0)				//If voltage on RD0 pin is low turn on led //PULL Down logic
		PORTC=0xFF;			//Set PORTC pins as HIGH
	else					//else switch off led
		PORTC=0x00;			//Reset PORTC pins as LOW
}