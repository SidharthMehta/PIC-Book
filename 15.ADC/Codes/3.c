//reading two LM35 sensors
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
	ADCON1 = 0b10110000;	//set ADFM bits
	TRISA = 0b00000011;		//set RA0,1 as input
	ANSEL = 0b00000011;		//set RA0,1 as analog
	TRISC = 0x00;			//Set PORTC pins as output
	TRISD = 0x00;			//Set PORTD pins as output
	LCDPORT = 0x00;
	CONTROL = 0x00;

	lcd_init();				//initialize LCD
	
	while(1)
	{
		ADCON0 = 0b11000001;
		delay(1000);
		GO = 1;
		while(GO == 1);
		if(GO == 0 && CHS0 == 0)	//changing chanel
		{
			lcd_moveCursor(0,0);
			int up = ADRESH;
			int low = ADRESL;
			up *= 256;
			up += low;
			if(up<33)
				lcd_write('-');
			if(up<33)
				up = (int)((33 - up)*1.67);
			else
				up = (int)((up-33)*0.152);
			int i;
			char ad[4];
	
			for(i=0; i<4; i++)
			{
				ad[3-i] =  up%10 + '0';
				up /= 10;			
			}
			for(i=0; i<4; i++)
			{
				lcd_write(ad[i]);
			}
			lcd_write(' ');
		}

		ADCON0 = 0b11000101;
		delay(1000);
		GO = 1;
		while(GO == 1);
		if(GO == 0 && CHS0 == 1)	//changing chanel
		{
			lcd_moveCursor(1,0);
			int up = ADRESH;
			int low = ADRESL;
			up *= 256;
			up += low;
			if(up<33)
				lcd_write('-');
			if(up<33)
				up = (int)((33 - up)*1.67);
			else
				up = (int)((up-33)*0.152);
			int i;
			char ad[4];
			for(i=0; i<4; i++)
			{
				ad[3-i] =  up%10 + '0';
				up /= 10;			
			}
			for(i=0; i<4; i++)
			{
				lcd_write(ad[i]);
			}
			lcd_write(' ');
		}
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