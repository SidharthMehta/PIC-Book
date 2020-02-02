//divergence

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	TRISC=0x00;				//Set PORTC pins as output
	int i,a,b;
	a=0x08;					//Set bit 5 to 1
	b=0x10;					//Set bit 4 to 1
	for(i=0;i<4;i++)		//Loop runs 4 times
	{	
		PORTC=a|b;			//OR operation and sending contents of OR to PORTC 
		a>>=1;				//left shifting contents of a by 1
		b<<=1;				//right shifting contents of b by 1
		delay(20000);		//delay function call
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}