//sandglass

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);

void main()
{
	TRISC=0x00;				//Set PORTC pins as output
	int i,j,a,b=0x00;
	PORTC=0x00;				//Reset PORTC pins as LOW
	for(i=1;i<8;i++)		//Loop runs 8 times
	{	
		a=0x01;				//Set first bir high
		for(j=0;j<8-i;j++)	//Run loop 8-i times
		{
			PORTC=b;		//Used to assign previous value
			PORTC|=a;		//or operation retain previous values as well as adds new values
			a<<=1;			//LEFT shift bit by 1
			delay(20000);	//Calling delay function
		}
		b|=(a>>1); 			//storing last value in b
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}