#include<pic.h>				//header files
#include<string.h>

#define LCDPORT PORTD		//LCD data pins
#define CONTROL PORTC		//LCD contol pins

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);
void instructionWrite(int);
void dataWrite(int);
void lcd_command();
void lcd_data();
void lcd_clear();
void lcd_init();
void lcd_write(int);
void lcd_moveCursor(int, int);
void lcd_rotateLeft();
void lcd_writeLine(char *p);

void main()
{
	TRISC = 0x80;			//Set PORTC pins as output
	TRISD = 0x00;			//Set PORTD pins as output
	LCDPORT = 0X00;
	CONTROL = 0X00;
	SPBRGH = 0x00;			//Desired baud rate is set
	SPBRG = 0b00011001;
	BRG16 = 0;				//8 bit baud rate generator is used
	SPEN = 1;				//asynchronous serial port is enabled
	TXEN = 1;				//Transmission is enabled
	BRGH = 1;				//High speed baud rate is set
	SYNC = 0;				//asynchronous mode is used
	int a;
	CREN = 1;
	lcd_init();				//LCD is initialized
	while(1)
	{
		while(RCIF==0);		//Waiting for receiver flag
		a = RCREG;
		lcd_write(a);		//display data on LCD
		TXREG = a;			//receive data from transmitter
	}
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

void lcd_write(int p)
{
	dataWrite(p);			//write at cursor position
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
	LCDPORT = x;
	lcd_command();
}

void dataWrite(int x)
{
	LCDPORT = x;
	lcd_data();
}

void delay(unsigned int x)
{
	while(x--);		//Function to generate delay
}
