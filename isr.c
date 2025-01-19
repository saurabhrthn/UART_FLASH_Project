#include <xc.h>

void __interrupt() isr(void)
{
    //To check if Timer 2 Interrupt Flag is enabled or not
    if (TMR2IF == 1)
    {
        TMR2IF = 0;  //Disable the Timer 2 Interrupt Flag bit
    }
}
