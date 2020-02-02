#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	BRG16 = 0;				//8 bit baud rate generator is used
	BRGH = 1;				//High speed baud rate is set
	SPBRGH = 0x00;			//Desired baud rate is set
	SPBRG = 0b00011001;
	SYNC = 0;				//asynchronous mode is used
	SPEN = 1;				//asynchronous serial port is enabled
	char a[18] = "EMTECH FOUNDATION\0";
	int i; 
	TXEN = 1;				//Transmission is enabled
	for(i=0;i<18;i++)
	{
		TXREG = a[i];		//Data is loaded into TXREG register
		delay(100);			//delay function call
	}
	while(1);				//Infinite loop
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}