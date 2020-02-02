//reading values from ADC 
#include<pic.h>				//header files
#include<string.h>

#define LCDPORT PORTD		//LCD data pins
#define CONTROL PORTC		//LCD contol pins

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay
void lcd_command();			//Write instruction register
void lcd_data();			//Write data register
void instructionWrite(int x);
void dataWrite(int x);
void lcd_clear();
void lcd_init();
void lcd_write(char p);
void lcd_moveCursor(int row, int column);
void lcd_rotateLeft();
void lcd_writeLine(char *p);//write string to display

void main()
{
	ADCON0 = 0b11000001;	//select channel and ADCON bits
	ADCON1 = 0b10000000;	//set ADFM bits
	TRISA = 0b00000001;		//set RA0/AN0 as input
	ANSEL = 0b00000001;		//set RA0/AN0 as analog
	TRISC = 0x00;			//Set PORTC pins as output
	TRISD = 0x00;			//Set PORTD pins as output
	LCDPORT = 0x00;
	CONTROL = 0x00;

	lcd_init();				//initialize LCD
	
	while(1)
	{
		GO = 1;				//start ADC conversion
		delay(1000);		//delay function call
		int up = ADRESH;	//load Higher order bits
		int low = ADRESL;	//load Lower order bits
		up *= 256;			//store data into a single 16 bit integer
		up += low;			//store high and low bits in a single integer
		int i;
		char ad[4];
		for(i=0; i<4; i++)
		{
			ad[3-i] =  up%10 + '0';	//convert adc reading to string
			up /= 10;			
		}
		for(i=0; i<4; i++)
		{
			lcd_write(ad[i]);	//display reading on LCD
		}
		lcd_moveCursor(0,0);	//Move cursor to 0th row oth column
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}

void lcd_command()	//Write instruction register
{
	CONTROL = 0x04;	//Enable high
	delay(100);
	CONTROL = 0x00;	//Enable low
	delay(100);
}

void lcd_data()	//Write data register
{
	CONTROL = 0x05;	//Enable high
	delay(100);
	CONTROL = 0x01;	//Enable low
	delay(100);
}

void instructionWrite(int x)
{
	int z = x;
	LCDPORT = z;
	lcd_command();
}

void dataWrite(int x)
{
	int z = x;
	LCDPORT = z;
	lcd_data();
}

void lcd_clear()
{
	instructionWrite(0x01);	//Clear Display
}

void lcd_init()
{
	instructionWrite(0x38);	//8 data line 2 display line
	instructionWrite(0x01);	//Clear Display
	instructionWrite(0x0E);	//Cursor display
}

void lcd_write(char p)
{
	dataWrite(p);	//write at cursor position
}

void lcd_moveCursor(int row, int column)
{
	instructionWrite(0x80 + 4*row*16 + column);	//cursor position
}

void lcd_rotateLeft()
{
	instructionWrite(0x10);	//left rotate bits
}

void lcd_writeLine(char *p)	//write string to display
{
	int i=0;
	for(i=0;i<strlen(p);i++)
	{
		lcd_write(p[i]);
		if(i==14)
			lcd_moveCursor(1,0);	//Move to line 2 if string is large
	}
}
