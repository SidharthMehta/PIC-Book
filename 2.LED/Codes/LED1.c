//To blink LED

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	TRISC=0x00;				//Set PORTC pins as output
	PORTC=0xFF;				//PORTC pins are set HIGH
	delay(20000);			//delay function call
	PORTC=0x00;				//PORTC pins are set LOW
	delay(20000);			//delay function call
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}