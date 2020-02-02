//led blink 25 times

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	TRISC=0x00;				//Set PORTC pins as output
	int y=0;				//counter variable
	for(;y<25;y++)			//loop runs 25 times
	{						//blinking operation
		PORTC=0x01;			//RC0 is set
		delay(20000);		//delay function call
		PORTC=0x00;			//RC0 is reset
		delay(20000);		//delay function call
	}
	while(1);				//Infinite loop to stop operation
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}