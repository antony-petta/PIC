#include<xc.h>
void delay(int);
void lcdctrl(unsigned char);
void lcddisp(unsigned char);
void lcdstring(const char *p);
void main(void) 
{
    TRISC=TRISD=0;
    lcdctrl(0x01);
    lcdctrl(0x0f);
    lcdstring("antony");
    while(1);
}
void lcdctrl(unsigned char a){
    RC0=0;
    RC1=0;
    PORTD=a;
    RC2=1;
    delay(100);
    RC2=0;
    delay(5000);
 
}
void lcddisp(unsigned char b){
    RC0=1;
    RC1=0;
    PORTD=b;
    RC2=1;
    delay(100);
    RC2=0;
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
    
    