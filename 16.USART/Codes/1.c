#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	SPBRGH = 0x00;			//Desired baud rate is set
	SPBRG = 0b00011001;
	BRG16 = 0;				//8 bit baud rate generator is used
	BRGH = 1;				//High speed baud rate is set
	SYNC = 0;				//asynchronous mode is used
	SPEN = 1;				//asynchronous serial port is enabled
	TXEN =1;				//Transmission is enabled
	TXREG = '1';			//Data is loaded into TXREG register
	while(1);				//Infinite loop
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}