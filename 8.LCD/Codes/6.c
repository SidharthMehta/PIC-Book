//To display a 5 digit number on LCD
#include<pic.h>				//header files
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
	LCDPORT=0x80 + row*4*16 + column ;	//Instruction to move cursor
	PORTC=0x04;		//Set 0x04 on PORTC pins
	delay(100);		//delay function call
	PORTC=0x00;	
	delay(100);
}

void lcd_rotateleft()
{
	LCDPORT=0x1C;			//Instruction to rotatle display left
	PORTC=0x04;
	delay(100);
	PORTC=0x00;
	delay(100);
}

void lcd_rotateright()
{
	LCDPORT=0x18;		//Instruction to rotatle display left
	PORTC=0x04;
	delay(100);
	PORTC=0x00;
	delay(100);
}

void lcd_init()
{
	LCDPORT=0x38;		//Instruction to use 2 line display
	PORTC=0x04;
	delay(100);
	PORTC=0x00;	
	delay(100);

	LCDPORT=0x0E;		//Instruction to display cursor
	PORTC=0x04;
	delay(100);
	PORTC=0x00;
	delay(100);

	LCDPORT=0x01;		//Instruction to clear display
	PORTC=0x04;
	delay(100);
	PORTC=0x00;	
	delay(100);

}

void lcd_write(char p)
{
	LCDPORT=p;		//Function to display a character
	PORTC=0x05;
	delay(100);
	PORTC=0x01;
	delay(100);
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
	LCDPORT = 0x00;
	int i=0,j=0;

	lcd_init();
	
		i=43210;			//number to display
		lcd_movecursor(0,0);
		lcd_write((i/10000)%10+'0');//splitting method
		lcd_movecursor(0,1);
		lcd_write((i/1000)%10+'0');	
		lcd_movecursor(0,2);
		lcd_write((i/100)%10+'0');
		lcd_movecursor(0,3);
		lcd_write((i/10)%10+'0');
		lcd_movecursor(0,4);
		lcd_write(i%10+'0');
		lcd_movecursor(0,5);
		delay(100000);	//delay function call

	while(1);			//Infinite loop
}