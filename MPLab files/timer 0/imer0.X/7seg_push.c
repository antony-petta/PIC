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
    TRISD=0xff;  
    int j=0,l=0,m=0,n=0;
    unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    unsigned char digit[]={0x0e,0x0d,0x0b,0x07};
    while(1){
       
                PORTA=0x0e;
                PORTB=arr[j];
                delay(1000);
                PORTA=0x0d;
                PORTB=arr[l];
                delay(1000);
                PORTA=0x0b;
                PORTB=arr[m];
                delay(1000);
                PORTA=0x07;
                PORTB=arr[n];
                delay(1000); 
        
    
            if(RD0==0){
                j++;
                if(j==10){
                    j=0;
                    l++;
                    if(l==10){
                        l=0;
                      m++;
                      if(m==10){
                          m=0;
                          n++;
                          if(n==10){
                              n=0;
                              return;
                          }
                      }
                        
                  
                    }
                }
                while(RD0==0){
                PORTA=0x0e;
                PORTB=arr[j];
                delay(1000);
                PORTA=0x0d;
                PORTB=arr[l];
                delay(1000);
                PORTA=0x0b;
                PORTB=arr[m];
                delay(1000);
                PORTA=0x07;
                PORTB=arr[n];
                delay(1000); 
                }
            }
            
        
  
    }
    return;
}
void delay(long int time){
    for(long int i=0;i<time;i++);
}