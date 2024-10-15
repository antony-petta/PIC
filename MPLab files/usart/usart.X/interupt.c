/*
 * File:   interupt.c
 * Author: anton
 *
 * Created on 22 August, 2024, 8:47 AM
 */


#include <xc.h>

void delay(long int time);
void main(void) 
{
 ADCON1=0x0f;
TRISD=0x00;
TRISC=0x00;
TRISB=0xff;
INTCON=0xd0;
    while(1){
  PORTC=0xaa;
  delay(90000);
            PORTC=0x00;
            delay(90000);
        
    }
    
    return;
}
void delay(long int time){
        for(long int i=0;i<time;i++);
    }

void __interrupt() isr(){
        if(INT0IF==1){
            PORTD=0xaa;
            delay(90000);
            PORTD=0x00;
            delay(90000);
        }
        INT0IF=0;
    }