#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay


void main()
{
	TRISC = 0x00;			//Set PORTC pins as output
	PORTC = 0x00;			//Reset PORTC pins as LOW
	int i;					//counter variable
	//common anode codes
	int n[10] = {0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0011000};
	for(i=0;i<10;i++)		//loop runs 10 times
	{
		EEADR = 0x00 + i;	//writing the address
		EEDAT = n[i];		//writing the data
		EEDATH = 0x00;		//clear EEDATH bits writing the data
		EEPGD = 0;			//Access data memory
		WREN = 1;			//Enable write
		EECON2 = 0x55;		//set EECON2 0x55
		EECON2 = 0xAA;		//set EECON2 0xAA
		WR = 1;				//Initiate write
		while(EEIF == 0);	//wait for interrupt to occur
	}
	WREN = 0;				//disable write
	
	for(i=0;i<10;i++)		//loop runs 10 times
	{
		EEADR = 0x00 + i;	//writing the address
		EEPGD = 0;			//Access data memory
		RD = 1;				//enable read
		int w = EEDAT;		//save data in EEDAT register into variable w
		PORTC = w;			//set PORTC with value in w
		delay(10000);		//delay function call
	}

	for(i=0;i<10;i++)	
	{
		EEADR = 0x09 - i;	//writing the address
		EEPGD = 0;			//Access data memory
		RD = 1;				//enable read
		int w = EEDAT;		//save data in EEDAT register into variable w
		PORTC = w;			//set PORTC with value in w
		delay(10000);		//delay function call
	}
	while(1);				//Infinite loop
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}