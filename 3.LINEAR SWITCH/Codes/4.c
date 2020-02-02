//LED toggle

#include<pic.h>				//header files

#define ON 0				//macros ON on low
#define OFF 1				//macros OFF on HIGH

/*PRIVATE FUNCTION DECLARATION*/
void delay(unsigned int);	//function to generate delay

void main()
{	
	TRISC=0x00;
	TRISD=0x07;
	PORTC=0x00;
	int flag = OFF;					//set state flag OFF
	while(1)
	{
		if(RD0 == OFF && flag== ON)	//Toggle if current state is off and prev is ON
		{
			PORTC=~PORTC;			//Set PORTC as complement of PORTC
			flag=OFF;				//set previous as off	
			//delay(20000);
		}
		else if(RD0==ON)			//IF button connected to RD0 is pressed we get ON
		{
			flag=ON; 				//set previous as ON 
		} 
	}
}

/*PRIVATE FUNCTION DEFINITION*/
void delay(unsigned int x)	//function to generate delay
{
	while(x>0)				//loop runs x times
		x--;				//Decrement x
}