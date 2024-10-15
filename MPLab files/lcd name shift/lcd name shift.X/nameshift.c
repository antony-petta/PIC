
#include <xc.h>
void lcdctrl(unsigned char);
void lcddisp(unsigned char);
void lcdstring(const char *p);
void delay(long int);
void main(void) {
    TRISC=0x08;
    TRISD=0x00;
    int c1=-1;
    int j=0;
    lcdctrl(0x01);
    lcdctrl(0x0f);
    lcdctrl(0xa7);
    lcdstring("Hell0");
   
while(1){
            
    for(int j=0;j<16;j++){  
        lcdctrl(0x1c);//shift
        }
    lcdctrl(0x02);//return home
    }
}
void delay(long int time){
    for(long int i=0;i<time;i++);
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

    