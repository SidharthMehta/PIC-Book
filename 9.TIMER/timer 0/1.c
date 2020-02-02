#include<pic.h>		//header file

//#define delayVal 235 //20us delay = no of timer bits * prescaler bits * 4/fosc 20 = x *1*1 TMR0= 235
//#define delayVal 205 //50us
//#define delayVal 155 //100us
//#define delayVal 5 //500us OPTION_REG = 0b0000000
//#define delayVal 0x05 //1ms OPTION_REG = 0b00000001
#define delayVal 2.5

/*PRIVATE FUNCTION DECLARATION*/
void delay(float);		//function to generate delay


void main()
{
	OPTION_REG = 0b00000111; //1:256 prescaler
	TRISC = 0x00;		//Set PORTC pins as output
	PORTC = 0x00;		//Reset PORTC pins as LOW
	while(1)
	{
		PORTC = 0xFF;		//program for blinking
		delay(delayVal);
		PORTC = 0x00;
		delay(delayVal);
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(float a)
{
	TMR0=0;		//clear TMR0
	T0IF=0;		//Timer 0 interrupt flag its set 1 when overflow occurs
	int i;
	for(i=0;i<(a/0.065);i++)		//loop to generate delay
	{
		T0IF=0;
		while(T0IF==0);		//wait for counting to complete
	}
	int z =(((float)a/0.065)-(int)(a/0.065))*255;	//formula to calculate counting bits
	TMR0 = 255 - z;
	while(T0IF==0);
}