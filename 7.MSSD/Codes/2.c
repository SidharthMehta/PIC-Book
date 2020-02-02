//MSSD 0 to 9999 counting

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay
void display(int x);		//function to control MSSD
int unit(unsigned int x);	//function that gives out the no of digits of a number

void main()
{
	TRISC=0x00;			//Set PORTC pins as output
	PORTC=0x00;			//Reset PORTC pins as LOW
	TRISD=0x00;			//Set PORTD pins as output
	PORTD=0x00;			//Reset PORTD pins as LOW

	int j=0;
	for(j=0;j<9999;j++)	//0 to 9999 counting
	{	
		display(j);		//function to display number
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}

int unit(unsigned int x)	//function that gives out the no of digits of a number
{
	if(x<10)
		return 1;
	else if(x<100)
		return 2;
	else if(x<1000)
		return 3;
	else
		return 4;
}

void display(int x)
{
	//CC
	int n[16] = {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1100111,0b1110111,0b1111100,0b0111001,0b0111111,0b1111001,0b1110001};
	int a[4] = {0x08,0x04,0x02,0x01};	//unit index
	int i=0,j=0,w;
	w=x;
	for(j=0;j<50;j++)		//displaying same number 50 times to remove flickering
	{		
		for(i=0;i<unit(x);i++)//run unit number of times
		{
			PORTC=n[w%10];	//splitting of number
			PORTD=a[i];		//shift digit
			w/=10;
			delay(300);		//delay function call
			PORTD=0x00;		//set PORTD 0
		}
		w=x;				//reload w
	}
}
