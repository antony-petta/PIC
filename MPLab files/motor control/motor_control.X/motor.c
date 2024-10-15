/*
 * File:   motor.c
 * Author: anton
 *
 * Created on 1 August, 2024, 8:53 AM
 */


#include <xc.h>
void delay(void);
void main(void) {
    TRISD=0x00;
    TRISC=0x03;
    int count0=-1;
    int count1=-1;
    while(1){
        if(RC0==1){
            if(count0==2){
                count0=-1;
            }
            count0++;
            while(RC0==1);
        }
            if(count0==0){
                RD0=0;
                RD1=1;
            }
            else if(count0==1){
                RD0=1;
                RD1=0;
            }
            else if(count0==2){
                RD0=0;
                RD1=0;;
            }
        if(RC1==1){
            if(count1==2){
                count1=-1;
            }
            count1++;
            while(RC1==1);
        }
            if(count1==0){
                RD2=1;
                RD3=0;
            }
            else if(count1==1){
                RD2=0;
                RD3=1;
            }
            else if(count1==2){
                RD2=0;
                RD3=0;
            }
    }
    return;
}
    