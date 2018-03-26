/*
    File Name:        :  interrupt_manager.h

    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/

#ifndef _INTERRUPT_MANAGER_H
#define _INTERRUPT_MANAGER_H


void INTERRUPT_Initialize(void);



inline static void INTERRUPT_GlobalEnable(void)
{
    __builtin_enable_interrupts();
}


inline static void INTERRUPT_GlobalDisable(void)
{
    __builtin_disable_interrupts();
}

#endif

/*End of File*/