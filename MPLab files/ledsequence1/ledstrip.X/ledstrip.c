/*
 * File:   ledstrip.c
 * Author: anton
 *
 * Created on 26 July, 2024, 10:00 AM
 */


#include <xc.h>

void main(void) {
    while(1){
        int i;
        TRISC=0x00;
        PORTC=1;
        for(i=1;i<8;i++){
            PORTC=PORTC*2;
            for(int j=0;j<30000;j++);
        }
    }
    return;
}
