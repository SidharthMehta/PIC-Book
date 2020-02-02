//Right rotation

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	TRISC=0x00;				//Set PORTC pins as output
	int i;					//counter variable
	for(i=0;i<8;i++)		//Loop runs 8 times
	{
		PORTC=0x01;			//set LSB RC0 HIGH
		PORTC<<=i; 			//shifting contents bitwise towards left by i
		delay(20000);		//delay function call
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}