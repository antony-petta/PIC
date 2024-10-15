/*
 * File:   10msdelay.c
 * Author: anton
 *
 * Created on 23 August, 2024, 11:38 AM
 */


#include <xc.h>
#define fosc 20000000
#define pre 8
#define del 0.1
#define max 2^16
#define a (max)-((int)(fosc*del)/(4*pre))

void delay(void);

void main(void) {
    TRISD=0x00;
    T1CON=0x31;
    TMR1=a;
    while(1){
        PORTD=0xaa;
        delay();
        PORTD=0x00;
        delay();
    }
    return;
}
void delay(void){
    while(TMR1IF==0);
    TMR1IF=0;
    TMR1= a;                   //for getting 1s delay=100 times 10ms

}






