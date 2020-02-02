//controlling LEDs using key press on matrix 1

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	TRISC=0x00;				//Set PORTC pins as output
	PORTC=0x00;				//Set PORTC as LOW
	TRISB=0x00;				//Set PORTB pins as output
	PORTB=0x00;				//Set PORTB as LOW
	TRISD=0xF0;				//Set PORTD pins PD0-3(row) as output PD4-7(columns) as Input of keypad matrix
	PORTD=0x01;				//Set PD0 as HIGH 

	int i=0;				//counter variable
	for(i=0;i<4;i++)		//Loop runs 4 times
	{
		if(RD4==1)			//Check which column is HIGH(active)
		{
			if(i==0)		//row 0 
			{
				PORTC=0x01;	//Set PC0 as HIGH
				delay(1000);//delay function call
			}
			else if(i==1)	//row 1
			{
				PORTC=0x02;
				delay(1000);
			}
			else if(i==2)	//row 2
			{
				PORTC=0x04;
				delay(1000);
			}
			else if(i==3)	//row 3
			{
				PORTC=0x08;
				delay(1000);
			}
		}
		if(RD5==1)
		{
			if(i==0)
			{
				PORTC=0x10;
				delay(1000);
			}
			else if(i==1)
			{
				PORTC=0x20;
				delay(1000);
			}
			else if(i==2)
			{
				PORTC=0x40;
				delay(1000);
			}
			else if(i==3)
			{
				PORTC=0x80;
				delay(1000);
			}
		}
		if(RD6==1)
		{
			if(i==0)
			{
				PORTB=0x01;
				delay(1000);
			}
			else if(i==1)
			{
				PORTB=0x02;
				delay(1000);
			}
			else if(i==2)
			{
				PORTB=0x04;
				delay(1000);
			}
			else if(i==3)
			{
				PORTB=0x08;
				delay(1000);
			}
		}
		if(RD7==1)
		{
			if(i==0)
			{
				PORTB=0x10;
				delay(1000);
			}
			else if(i==1)
			{
				PORTB=0x20;
				delay(1000);
			}
			else if(i==2)
			{
				PORTB=0x40;
				delay(1000);
			}
			else if(i==3)
			{
				PORTB=0x80;
				delay(1000);
			}
		}
		PORTD=(PORTD&0xF0)<<1;//shift output on (PORTD)columns left
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}