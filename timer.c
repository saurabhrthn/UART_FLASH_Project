#include "timer.h"
#include "main.h"

void init_timer(void)
{
    //1:16 scaling
    T2CKPS0 = 1;
    T2CKPS1 = 1;
    
    //preload register
    PR2 = 250;
    
    //timer2 interrupt enable
    TMR2IE = 1;
    TMR2ON = 1;
}

void reset_timer(void)
{
    TMR0 = 0; // Reset Timer0 count
}

unsigned long get_timer_ticks(void)
{
    return TMR0; // Return Timer0 count (configured for ms resolution)
}