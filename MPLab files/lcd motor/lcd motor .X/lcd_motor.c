
#include <xc.h>
void lcdctrl(unsigned char);
void lcddisp(unsigned char);
void lcdstring(const char *p);
void motor1(int,int);
void motor2(int,int);
void delay(long int);
void main(void) {
    TRISC=0x60;
    TRISD=0x00;
    TRISB=0x00;
    lcdctrl(0x01);
    lcdctrl(0x0c);
    lcdctrl(0x38);
    int c1=-1;
    int c2=-1;
    while(1){
        if(RC5==1){            
            if(c1==2){
                c1=-1;
            }
            c1++;
            while(RC5==1);
        lcdctrl(0x80);//to move cursor to line 1
        if(c1==0){
            
            motor1(0,1);
            lcdstring("clockwise>>     ");
        }
        else if(c1==1){
            
            motor1(1,0);
            lcdstring("anticlockwise<<");
        }
        else if(c1==2){
            
            motor1(0,0);
            lcdstring("stop!!           "); 
        }  
        }
        if(RC6==1){
            
            if(c2==2){
                c2=-1;
            }
            c2++;
            while(RC6==1);
            lcdctrl(0xc0);//to move cursor to line 2
        if(c2==0){
            motor2(0,1);
            lcdstring("clockwise>>    ");    
        }
        else if(c2==1){
            motor2(1,0);
            lcdstring("anticlockwise<<");
        }
        else if(c2==2){
            motor2(0,0);     
            lcdstring("!!!!!!!!stop!!!!!!!!");
        }  
        }
    }
    return;
}

void motor1(int m,int n){
    RC3=m;
    RC4=n;
    
}
void motor2(int x,int y){
    RB7=x;
    RB6=y;
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

    