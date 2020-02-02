//multiple SSD 0 to 99 counting CA

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

//gfedcba
void main()
{
	//1 will be on 0 will be Off
	int n[10] = {0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0011000};	//Codes for numbers
	TRISC=0x00;				//Set PORTC pins as output
	TRISD=0x00;				//Set PORTD pins as output
	PORTC=0x00;				//Set PORTC pins as LOW Tens place OFF
	int i,j;				//counter variable
	for(i=0;i<10;i++) 
	{
		if(i>0)
			PORTC=n[i];		//condition to not print tens digit from 0 to 9
		for(j=0;j<10;j++)
		{
			PORTD=n[j];		//inner loop units place
			delay(20000);	//delay function call
		}
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}