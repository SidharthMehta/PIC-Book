//External interrupt
#include<pic.h>		//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay
void interrupt external();

void main()
{
	TRISC = 0x00;	//set PORTC as output
	PORTC = 0x00;	//set PORTC LOW
	TRISB = 0xFF;	//set PORTB as input
	ANSELH = 0x00;	//set PORTB inputs to digital
	TRISD = 0x00;	//set PORTD as output
	PORTD = 0x00;	//set PORTD LOW
	INTEDG = 0;		//set interrupt edge
	PEIE = 1;		//enable peripheral interrupt
	INTE = 1;		//set external internal interrupt
	GIE = 1;		//set global interrupts enable
	
	while(1)
	{
		PORTC = !PORTC;	//LED controlled by normal delay
		delay(1000);	//delay function call
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}

void interrupt external()
{
	INTF = 0;		//clear interrupt flag
	static int i = 0;
	i++;
	if(i>15)		//SSD controlled by external interrupt
		i=0;
	PORTD = i;
	GIE = 1;		//enable interrupts
}
