//To display 00 to 99

#include<pic.h>				//Header dile
#include<string.h>
#define LCDPORT PORTD		//LCD data pins on PORTD

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}

void lcd_movecursor(int row, int column)
{
	LCDPORT=0x80 + row*4*16 + column ;		//Instruction to move cursor
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call
}

void lcd_rotateleft()
{
	LCDPORT=0x1C;	//Instruction to rotate display left
	PORTC=0x04;		//set enable HIGH
	delay(100);		//delay function call
	PORTC=0x00;		//reset enable LOW
	delay(100);		//delay function call
}

void lcd_rotateright()
{
	LCDPORT=0x18;	//Instruction to rotatle display left
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
	int i=0,j=0;

	lcd_init();			//Initialize LCD
	for(i=0;i<99;i++)	//0 to 99 via number splitting
	{
		lcd_write(i/10+'0');
		lcd_movecursor(0,1);
		lcd_write(i%10+'0');
		lcd_movecursor(0,0);
		delay(100000);	//delay function call
	}	
	while(1);			//Infinite loop
}