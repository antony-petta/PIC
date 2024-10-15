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
//#define post 16
//#define a ((int)(fosc*del)/(4*pre))



void delay(void);

void main(void) {
    ADCON1=0x0f;
    TRISC=0x00;
    TRISD=0x00;
    T2CON=0x06;
    PR2=255;
    
    TRISB=0xff;
    while(1){
        if(RB0==0){
            CCP1CON=0x0c;
            CCPR1L=0x80;
            
        }
        else if(RB1==0){
            CCP1CON=0x0c;
            CCPR1L=0xc0;
            
        }
        else if(RB2==0){
            CCP1CON=0x0c;
            CCPR1L=0x40;
            
        }
    }
    return;
}
void delay(void){
    while(TMR2IF==0);
    TMR2IF=0;
                       //for getting 1s delay=100 times 10ms

}






