//LED control using switches

#include<pic.h>				//header files

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay
void blink();				//function for blinking
void RotateLeft();			//function for left rotation
void RotateRight();			//function for right rotation
void ConvDiv();				//function of convergence and divergence
void OFF();					//function to turn of LEDs

void main()
{	
	TRISC=0x00;				//Set PORTC pins as output
	TRISD=0x1F;				//Set PD0,1,2,3,4,5 pins as input
	PORTC=0x00;				//Reset PORTC pins as LOW
	int v=0;				//condition flag for checking which button was last pressed
	while(1)				//Infinite loop
	{						//Pull Down logic
		if(RD0==0||v==1)	//Execute if button on RD0 is pressed or last pressed is 1
		{
			blink();		//function call
			v=1;			//Set last pressed as 1
		}
		if(RD1==0||v==2)	//Execute if button on RD1 is pressed or last pressed is 2
		{
			RotateLeft();	//function call
			v=2;			//Set last pressed as 2
		}
		if(RD2==0||v==3)	//Execute if button on RD2 is pressed or last pressed is 3
		{
			RotateRight();	//function call
			v=3;			//Set last pressed as 3
		}
		if(RD3==0||v==4)	//Execute if button on RD3 is pressed or last pressed is 4
		{
			ConvDiv();		//function call
			v=4;			//Set last pressed as 4
		} 
		if(RD4==0||v==5)	//Execute if button on RD4 is pressed or last pressed is 5
		{
			OFF();			//function call
			v=5;			//Set last pressed as 5
		}
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}

void blink()				//function for blinking
{
	PORTC=0xFF;				//PORTC is set
	delay(20000);			//delay function call
	PORTC=0x00;				//PORTC is reset
	delay(20000);			//delay function call
}

void RotateLeft()			//function for left rotation
{
	int i;					//counter variable
	for(i=0;i<8;i++)		//Loop runs 8 times
	{
		PORTC=0x80;			//set MSB RC7 HIGH
		PORTC>>=i; 			//shifting contents bitwise towards right by i
		delay(20000);		//delay function call
	}
}

void RotateRight()			//function for right rotation
{
	int i;					//counter variable
	for(i=0;i<8;i++)		//Loop runs 8 times
	{
		PORTC=0x01;			//set LSB RC0 HIGH
		PORTC<<=i; 			//shifting contents bitwise towards left by i
		delay(20000);		//delay function call
	}
}

void ConvDiv()				//function of convergence and divergence
{
	int i,a,b;
	/*Converge operation*/
	a=0x80;					//Set bit 7 to 1
	b=0x01;					//Set bit 0 to 1
	for(i=0;i<3;i++)		//Loop runs 3 times
	{	
		PORTC=a|b;			//OR operation and sending contents of OR to PORTC
		a>>=1;				//right shifting contents of a by 1
		b<<=1;				//left shifting contents of b by 1
		delay(20000);		//delay function call
	}
	/*Diverge operation*/
	a=0x08;					//Set bit 5 to 1
	b=0x10;					//Set bit 4 to 1
	for(i=0;i<3;i++)
	{	
		PORTC=a|b;			//OR operation and sending contents of OR to PORTC 
		a>>=1;				//left shifting contents of a by 1
		b<<=1;				//right shifting contents of b by 1
		delay(20000);		//delay function call
	}
}

void OFF()					//function to turn of LEDs
{
	PORTC=0x00;				//PORTC is reset
}