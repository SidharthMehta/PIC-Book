#include<pic.h>

void main()
{
    TRISC=0x00;
    PR2=0x64;
    CCP1CON=0x0C;
    DC1B0=0;
    DC1B1=0;
    CCPR1L=0x34;
    while(1)
    {
        TMR2IF=0;
        T2CKPS1=0;
        T2CKPS0=1;
        TMR2ON=1;
        while(TMR2IF==0);
        
    }
}
