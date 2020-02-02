#include<pic.h>			//Header file

void main()
{
	TRISC = 0x00;		//Set PORTC pins as output
	PORTC = 0x00;		//reset PORTC pins as LOW
	
	EEADR = 0x00;		//writing the address
	//EEADRH = 0x01;
	EEDAT = 0xAA;		//Set EEDAT register bits 
	EEDATH = 0x00;		//clear EEDATH bits writing the data
	EEPGD = 0;			//Access data memory
	WREN = 1;			//Enable write
	EECON2 = 0x55;		//set EECON2 0x55
	EECON2 = 0xAA;		//set EECON2 0xAA
	WR = 1;				//Initiate write
	while(EEIF == 0);	//wait for interrupt to occur
	WREN = 0;			//disable write
	
	EEADR = 0x00;		//writing the address
	EEPGD = 0;			//Access data memory
	RD = 1;				//enable read
	int w = EEDAT;		//save data in EEDAT register into variable w
	PORTC = w;			//set PORTC with value in w
	while(1);			//Infinite loop
}