#include<pic.h>		//header file

#define delayValue //15535 //100ms //64535 //1ms 65035 // 500us

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	TRISC = 0x00;		//Set PORTC pins as output
	PORTC = 0x00;		//Reset PORTC pins as LOW
	T1CON=0b10010001;	//set T1CON register
	while(1)
	{
		PORTC = ~PORTC;	//toggle LED
		delay(delayValue);
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)
{
	TMR1H=(x&0xFF00)>>8;//mechanism for loading TMR1H bits
	TMR1L=x&0x00FF;		//mechanism for loading TMR1L bits
	TMR1IF=0;			//clear interrupt flag
	while (TMR1IF==0);	//wait for interrupt to occur
}
