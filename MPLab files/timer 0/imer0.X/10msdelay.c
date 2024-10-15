/*
 * File:   10msdelay.c
 * Author: anton
 *
 * Created on 23 August, 2024, 11:38 AM
 */


#include <xc.h>
void delay(void);
void main(void) {
    TRISD=0x00;
    T0CON=0xc7;
    TMR0=60.68;
    while(1){
        PORTD=0xaa;
        delay();
        PORTD=0x00;
        delay();
    }
    return;
}
void delay(void){
    for(int i=0;i<100;i++){                      //for getting 1s delay=100 times 10ms
    while(TMR0IF==0);
    TMR0IF=0;
    TMR0=60.68;
}
    
}