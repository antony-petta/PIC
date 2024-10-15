/*
 * File:   ledstrip2.c
 * Author: anton
 *
 * Created on 27 July, 2024, 10:20 AM
 */


#include <xc.h>

void main(void) {
    while(1){
        unsigned int i;
        TRISC=0x00;
        TRISD=0x00;
        PORTC=1;
        for(unsigned long int j=0;j<50000;j++);
        for(i=0;i<7;i++){
            PORTC=(PORTC*2)+1;
            for(unsigned long int j=0;j<50000;j++);
        }
        PORTC=0xFF;
        PORTD=1;
        for(unsigned long int j=0;j<50000;j++);
        for(i=0;i<7;i++){
            PORTD=(PORTD*2)+1;
            for(unsigned long int j=0;j<50000;j++);
        }
        PORTC=0XFF;
        PORTD=0XFF;
        
        for(i=0;i<7;i++){
            
            PORTD=PORTD/2;
            for(unsigned long int j=0;j<50000;j++);
        }
        PORTD=0;
        
        PORTC=0xFF;
        for(unsigned long int j=0;j<50000;j++);
        for(i=0;i<7;i++){
            PORTC=(PORTC/2);
            
            for(unsigned long int j=0;j<50000;j++);
        }
        PORTC=0;
        for(unsigned long int j=0;j<50000;j++);
        
       
    }
        return;
    

}
