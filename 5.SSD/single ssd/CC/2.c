//common cathode 9 to 0

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

//gfedcba
void main()
{
	//1 will be on 0 will be Off
	int n[10] = {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1100111};	//Codes for numbers
	TRISC=0x00;				//Set PORTC pins as output
	int i;					//Number variable
	for(i=0;i<10;i++) 		//Loop will run 10 times
	{
		PORTC=n[9-i];		//display no in reverse
		delay(20000);		//delay function call
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}