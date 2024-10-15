/*
 * File:   intro.c
 * Author: antony
 *
 * Created on 25 July, 2024, 9:24 AM
 */


#include <xc.h>

void main(void) {
    TRISC=0x00;
    while(1){
        
    
    int i=0;
    while(i<50000){
        PORTC=0x00;
        i++;
    }
    i=0;
    while(i<5000){
        PORTC=0xFF;
        i++;
    }
    
      
   }
}
