/*
 * File:   10msdelay.c
 * Author: anton
 *
 * Created on 23 August, 2024, 11:38 AM
 */


#include <xc.h>

void delay(void);

void main(void) {
    TRISC=0x00;
    T1CON=0x31;
    CCP1CON=0x02;
    CCPR1H=0x20;
    CCPR1L=0x10;
    while(1){   
    }
    return;
}
                






