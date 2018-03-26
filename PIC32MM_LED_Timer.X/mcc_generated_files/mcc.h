/*
    File Name:        :  mcc.h

    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/

#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include "interrupt_manager.h"
#include "tmr1.h"

#define _XTAL_FREQ  24000000UL

 /*SYSKEY - blokuje/odblokowuje zapisy do ustawienia zegara*/             
 inline static void SYSTEM_RegUnlock(void)
{
    SYSKEY = 0x12345678; //write invalid key to force lock
    SYSKEY = 0xAA996655; //write Key1 to SYSKEY
    SYSKEY = 0x556699AA; //write Key2 to SYSKEY
}


inline static void SYSTEM_RegLock(void)
{
   SYSKEY = 0x00000000; 
}


void SYSTEM_Initialize(void);


void OSCILLATOR_Initialize(void);


#endif	/* MCC_H */

/*End of File*/