//LCD question 3
#include<pic.h>			//Header file
#include<string.h>

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}

void lcd_newline()
{
	PORTD=0xC0;		//Instruction to move cursor
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call
}

void lcd_init()
{
	LCDPORT=0x38;	//Instruction to use 2 line display
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call

	LCDPORT=0x0E;	//Instruction to display cursor
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call

	LCDPORT=0x01;	//Instruction to clear display
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call
}

void lcd_write(char p)
{
	PORTD=p;		//Function to display a character
	PORTC=0x05;		//set enable and rs HIGH
	delay(100);		//delay function call
	PORTC=0x01;		//reset enable LOW
	delay(100);		//delay function call
}


void lcd_writeline(char *p)
{
	int i;
	for(i=0; i<strlen(p);i++)
		lcd_write(p[i]);
}


void main()
{
	TRISC=0x00;			//Set PORTC pins as output
	PORTC=0x00;			//Reset PORTC pins as LOW
	TRISD=0x00;			//Set PORTD pins as output
	PORTD=0x00;			//Reset PORTD pins as LOW
	
	lcd_init();			//Initialize LCD
	lcd_writeline("EMTECH Foundation");
	lcd_newline();
	lcd_writeline("**Igniting minds");
	while(1);			//Infinite loop
}