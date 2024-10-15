#include<xc.h>
#include<stdio.h>
#include<string.h>
#define output_start 0
#define output_end 150ul
#define input_end 308ul
#define input_start 0

void delay(long int);
void lcdctrl(unsigned char);
void lcddisp(unsigned char);
void lcdstring(const char *p);


void main(void) {
    TRISC=0X80;
    TRISD=0X00;
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=129;
    TRISB=0XF0; //1111 0000
    TRISA=0xff; 
  
    ADCON1=0X00;
    
    ADCON2=0x86;
    
   while(1){
       int adc,temp;
       char cnv[25];
       ADCON0=0x01;
       delay(500);
       GO=1;
       while(ADIF==0);
       ADIF=0;
       adc=ADRES;
       int a = output_start + ((float)(output_end - output_start) / (input_end - input_start)) * (adc-input_start);
        if(a!=temp){
       sprintf(cnv,"temp value is %4d \r\n",a);
      
       for(int i=0;i<=strlen(cnv);i++){
           lcddisp(cnv[i]);
       }
       delay(1000);
       temp=a;
        }
       
   }
    return;
   }
    

void lcdctrl(unsigned char a){
    RC0=0;
   
    PORTD=a;
    RC1=1;
    delay(100);
    RC1=0;
    delay(5000);
 
}
void lcddisp(unsigned char b){
    RC0=1;
    
    PORTD=b;
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
void delay(int time){
    for(long int i=0;i<time;i++);
}


     


