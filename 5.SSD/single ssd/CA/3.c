//common anode 0 to 9 9 to 0

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

//gfedcba
void main()
{
	//1 will be off 0 will be ON
	int n[10] = {0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0011000};		//Codes for numbers
	TRISC=0x00;				//Set PORTC pins as output
	int i;					//Number variable
	for(i=0;i<9;i++) 		//Loop runs 9 times
	{
		PORTC=n[i];			//display no 0 to 9 
		delay(20000);		//delay function call
	}
	for(i=0;i<9;i++) 		//Loop runs 9 times
	{
		PORTC=n[9-i];		//display no 9 to 0
		delay(20000);		//delay function call
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}