//binary counter

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	TRISC=0x00;				//Set PORTC pins as output
	int i;					//Counter variable
	PORTC=0x00;				//Reset PORTC pins as LOW
	for(i=0;i<256;i++)		//loop runs 2^8 times
	{	
		delay(20000);		//delay function call
		PORTC+=1;			//increment value in PORTC register by 1
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}