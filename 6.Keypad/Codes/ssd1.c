//controlling SSD using key press on matrix

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{
	//common cathode
	//segment On - 1 segment off - 0 
	//code to display 0 to F
	int n[16] = {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1100111,0b1110111,0b1111100,0b0111001,0b0111111,0b1111001,0b1110001};
	TRISC=0x00;				//Set PORTC pins as output
	PORTC=0x00;				//Set PORTC as LOW
	TRISD=0xF0;				//Set PORTD pins PD0-3(row) as output PD4-7(columns) as Input of keypad matrix
	PORTD=0x01;				//Set PD0 as HIGH 


		int i=0;			//counter variable
	for(i=0;i<4;i++)		//Loop runs 4 times
	{
		if(RD4==1)			//Check which column is HIGH(active)
		{
			if(i==0)		//row 0 
			{
				PORTC=n[0];	//display 0
				delay(1000);//delay function call
			}
			else if(i==1)	//row 1
			{
				PORTC=n[1];
				delay(1000);
			}
			else if(i==2)	//row 2
			{
				PORTC=n[2];
				delay(1000);
			}
			else if(i==3)	//row 3
			{
				PORTC=n[3];
				delay(1000);
			}
		}
		if(RD5==1)
		{
			if(i==0)
			{
				PORTC=n[4];
				delay(1000);
			}
			else if(i==1)
			{
				PORTC=n[5];
				delay(1000);
			}
			else if(i==2)
			{
				PORTC=n[6];
				delay(1000);
			}
			else if(i==3)
			{
				PORTC=n[7];
				delay(1000);
			}
		}
		if(RD6==1)
		{
			if(i==0)
			{
				PORTC=n[8];
				delay(1000);
			}
			else if(i==1)
			{
				PORTC=n[9];
				delay(1000);
			}
			else if(i==2)
			{
				PORTC=n[10];
				delay(1000);
			}
			else if(i==3)
			{
				PORTC=n[11];
				delay(1000);
			}
		}
		if(RD7==1)
		{
			if(i==0)
			{
				PORTC=n[12];
				delay(1000);
			}
			else if(i==1)
			{
				PORTC=n[13];
				delay(1000);
			}
			else if(i==2)
			{
				PORTC=n[14];
				delay(1000);
			}
			else if(i==3)
			{
				PORTC=n[15];
				delay(1000);
			}
		}
		PORTD=(PORTD&0xF0)<<1;//shift output on (PORTD)columns left
	}
}