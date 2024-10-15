#include<xc.h>
#include<stdio.h>
void lcdctrl(unsigned char);
void delay(long int);


void main(void) {
    TRISB=0XF0; //1111 0000
    TRISC=0X00;
    TRISD=0x00; 
    TRISA=0xff; 
    ADCON1=0X00;
    ADCON2=0x86;
    unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    int adc;
       char cnv[15];
    while(1){
       
       ADCON0=0x01;
       delay(500);
       GO=1;
       while(ADIF==0);
       ADIF=0;
       adc=ADRES;
       int a=adc%10;
       adc=adc/10;
       int b=adc%10;
       adc=adc/10;
       int c=adc%10;
       adc=adc/10;
       int d=adc%10;
       adc=adc/10;
     
           PORTD=0x0e;
           PORTC=arr[a];
           delay(1000);
           PORTD=0x0d;
           PORTC=arr[b];
           delay(1000);
           PORTD=0x0b;
           PORTC=arr[c];
           delay(1000);
           PORTD=0x07;
           PORTC=arr[d];
           delay(1000);
      }
}
    void delay(long int time){
    for(long int i=0;i<time;i++);
}