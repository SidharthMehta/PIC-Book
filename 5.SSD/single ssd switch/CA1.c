//counting on switch press CA

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

//gfedcba
void main()
{
	//1 will be off 0 will be ON
	int n[10] = {0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0011000};	//Codes for numbers
	TRISC=0x00;				//Set PORTC pins as output
	TRISD=0x03;				//Set PD0 pin and PD1 pin as input
	PORTC=0xFF;				//Set PORTC pins as HIGH
	int i;					//Number variable
	if(RD0==0)				//Count 0 to 9 on pressing RD0 
		for(i=0;i<10;i++) 	//Loop will run 10 times
	{
		PORTC=n[i];			//Loop to display number
		delay(20000);		//delay function call
	}
	else if(RD1==0)			//Count 9 to 0 on pressing RD1
		for(i=0;i<10;i++) 	//Loop will run 10 times
		{
			PORTC=n[9-i];	//Loop to display number
			delay(20000);	//delay function call
		}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}