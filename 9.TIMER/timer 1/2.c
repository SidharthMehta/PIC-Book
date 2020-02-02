//function to generate any delay greater 256ms 

#include<pic.h>		//header file

#define delayValue 2.4 //15535 //100ms //64535 //1ms 65035 // 500us

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	TRISC = 0x00;		//Set PORTC pins as output
	PORTC = 0x00;		//Reset PORTC pins as LOW
	T1CON=0b10110001;	//set T1CON register
	while(1)
	{
		PORTC = ~PORTC;	//Toggle LED
		delay(delayValue);
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)
{
	int z=x/0.524,i;
	for(i=0; i<z; i++)	//complete z* 65536 counts
	{
		TMR1H=0;	//clear TMR1
		TMR1L=0;	
		TMR1IF=0;	//clear interrupt flag
		while(TMR1IF==0);//wait for intrrupt
	}
	//partial count
	z = ((float)(x/0.524) - (int)(x/0.524))*65536;
	z = 65535 - z;
	TMR1H=(z&0xFF00)>>8;	//load remaining bit
	TMR1L=z&0x00FF;
	TMR1IF=0;
	while (TMR1IF==0);
}
