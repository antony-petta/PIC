/*
 * File:   7segment.c
 * Author: anton
 *
 * Created on August 30, 2024, 9:11 AM
 */


#include <xc.h>
void delay(long int);

void main(void) {
    TRISC=TRISA=TRISB=0x00;
    ADCON1=0x0f;
  
    
    unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    unsigned char digit[]={0x0e,0x0d,0x0b,0x07};
    while(1){
        
        /*for(int j=0;j<10;j++){
        PORTC=arr[j];
        delay(80000);
        }*/
       
        for(int n=0;n<10;n++){
        for(int m=0;m<10;m++){
        for(int l=0;l<10;l++){
        for(int j=0;j<10;j++){
            for(rep=0;rep<100;rep++){
            PORTA=0x0e;
            PORTB=arr[j];
            delay(4000);
            PORTA=0x0d;
            PORTB=arr[l];
            delay(4000);
            PORTA=0x0b;
            PORTB=arr[m];
            delay(4000);
            PORTA=0x07;
            PORTB=arr[n];
            delay(4000); 
            }
        }
        }
        }
        }
   /*   PORTC=0x06;//1
        delay(80000);
        PORTC=0x5b;//2
        delay(80000);
        PORTC=0x4f;//3
        delay(80000);
        PORTC=0x66;//4
        delay(80000);
        PORTC=0x6d;//5
        delay(80000);
        PORTC=0x7d;//6
        delay(80000);
        PORTC=0x07;//7
        delay(80000);
        PORTC=0x7f;//8
        delay(80000);
        PORTC=0x6f;//9
        delay(80000);
  */
        
    }
    return;
}
void delay(long int time){
    for(long int i=0;i<time;i++);
}