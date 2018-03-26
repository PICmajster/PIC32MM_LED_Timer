/*
    File Name:        :  main.c

    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/
#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> /*dyrektywy do uint8_t itp*/
#include "delay.h"

#define LED1_TOG PORTA ^= (1<<_PORTA_RA3_POSITION) /*zmienia stan bitu na przeciwny*/
 
void main(void)
{
    
    /*initialize the device*/
    SYSTEM_Initialize(); /*ustawia zegar i wszystkie inne duperele potrzebne do startu procka, zrobimy to w przyjazany sposób w MCC*/
    /*ustawienia pinu RA3 do pracy jako wyjscie cyfrowe*/
    /*odlaczenie RA3 od zegara RC mamy w pliku mcc.c sekcja dotyczaca rejestru FOSCSEL , #pragma config OSCIOFNC = OFF*/
    ANSELAbits.ANSA3 = 0; /*odlaczamy pin RA3 od sekcji analogowej*/
    TRISAbits.TRISA3 = 0; /*ustawiamy kierunek pinu RA3 jako wyjscie*/
    /*od tego momentu RA3 jest normalnym wyjsciem cyfrowym huraaa...*/
   
    while (1)
    {                 
        if(!Timer1_Programowy) {
              Timer1_Programowy = 10 ; /*Timer1 sprzetowy x Timer1_Programowy = 100ms x 10 = 1 s*/
              LED1_TOG ; /*zmieniaj stan wyjscia na przeciwny i mrugamy sobie LED-em*/
          }
    }
}
