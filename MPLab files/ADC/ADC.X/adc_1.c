#include<xc.h>
#include<stdio.h>
void lcdctrl(unsigned char);
void lcddisp(unsigned char);
void lcdstring(const char *p);
void delay(long int);


void main(void) {
    TRISB=0XF0; //1111 0000
    TRISC=0X00;
    TRISD=0x00; 
    TRISA=0xff; 
    lcdctrl(0x38);
    lcdctrl(0x01);
    lcdctrl(0x0f);
    ADCON1=0X00;
    
    ADCON2=0x86;
    
   while(1){
       int adc1,adc2;
       char cnv1[15],cnv2[15];
       ADCON0=0x01;
       delay(500);
       GO=1;
       while(ADIF==0);
       ADIF=0;
       adc1=ADRES;
       sprintf(cnv1,"ADC value %4d",adc1);
       lcdctrl(0x80);         
       lcdstring(cnv1);
       ADCON0=0x05;
       delay(500);
       GO=1;
       while(ADIF==0);
       ADIF=0;
       adc2=ADRES;
       sprintf(cnv2,"ADC value %4d",adc2);
       lcdctrl(0xc0);         
       lcdstring(cnv2);
       
       
   }
    return;
   }
    

void delay(long int time){
    for(long int i=0;i<time;i++);
}
void lcdctrl(unsigned char a){
    
   
    PORTD=a;
    RC0=0;
    RC1=1;
    delay(100);
    RC1=0;
    delay(5000);
}
void lcddisp(unsigned char b){
   
   
    PORTD=b;
    RC0=1;
    RC1=1;
    delay(100);
    RC1=0;
    delay(5000);
}
void lcdstring(const char *p){
    while(*p)
    { 
        lcddisp(*p);
        p++;
    }
}

     
      
     


