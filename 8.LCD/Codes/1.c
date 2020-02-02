//To display a character on LCD
#include<pic.h>		//Header file

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}

void lcd_init()
{
	PORTD=0x38;		//Instruction to use 8 char 2 line display
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call

	PORTD=0x01;		//Instruction to clear display
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call

	PORTD=0x0F;		//Instruction to blink cursor
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call

	PORTD=0x80;		//Instruction to initialize cursor
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call
}

void lcd_display(char p)
{
	PORTD=p;		//Function to display a character
	PORTC=0x05;		//set enable and rs HIGH
	delay(100);		//delay function call
	PORTC=0x01;		//reset enable LOW
	delay(100);		//delay function call
}


void main()
{
	TRISC=0x00;			//Set PORTC pins as output
	PORTC=0x00;			//Reset PORTC pins as LOW
	TRISD=0x00;			//Set PORTD pins as output
	PORTD=0x00;			//Reset PORTD pins as LOW
	
	lcd_init();			//initialize LCD
	lcd_display();		//display character on LCD
	while(1);			//Infinite loop
}