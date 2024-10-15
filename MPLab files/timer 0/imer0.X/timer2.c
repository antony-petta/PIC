/*
 * File:   10msdelay.c
 * Author: anton
 *
 * Created on 23 August, 2024, 11:38 AM
 */


#include <xc.h>
#define fosc 20000000
#define pre 16
#define del 0.01
#define post 16
#define a ((int)(fosc*del)/(4*pre*post))



void delay(void);

void main(void) {
    TRISD=0x00;
    T2CON=0x7e;
    PR2=a;
    
    while(1){
        PORTD=0xaa;
        delay();
        PORTD=0x00;
        delay();
    }
    return;
}
void delay(void){
    while(TMR2IF==0);
    TMR2IF=0;
                       //for getting 1s delay=100 times 10ms

}






