//Timer 0 interrupt
#include<pic.h>		//header files

#define ON 1		//macros
#define OFF 0
#define LED1 RC1
#define LED2 RC0

void interrupt delay()
{
	T0IF = 0;		//setting interrupt flag to 0
	TMR0 = 0;		//set timer to 0
	LED1 = !LED1;	//LED controlled nty TIMER0 delay
}

void main()
{
	GIE = 1;		//enable interrupts
	TRISC = 0x00;	//Set PORTC pins as output
	PORTC = 0x00;	//Reset PORTC pins as LOW
	TRISD = 0x01;	//Set RD0 pin as input
	PORTD = 0x00;	//Reset PORTD pins as LOW
	T0IE = 1;		//enable TImer 0 interrupt
	OPTION_REG = 0b00000111;	///set prescaler 1:256
	while(1)
	{
		if(RD0 == ON)	//LED controlled by switch
			LED2 = ON;
		else
			LED2 = OFF;
	}
}