    #include<xc.h>
    #include<string.h>
    void lcdctrl(unsigned char);
    void lcddisp(unsigned char);
    void lcdstring(const char *p);
    void delay(long int);



    unsigned char a;
    int flag=0;//temprpry variable to check if button for new code is pressed
    void main(void) {
        ADCON1=0X0F;
        TRISB=0XF0; //1111 0000
        TRISC=0X00;
        TRISD=0x00; 
        lcdctrl(0x34);
        lcdctrl(0x0c);
        
        
        
       while(1){
           lcdctrl(0x40);//cgram starting location
           //1
           lcddisp(0x00);
           lcddisp(0x1f);
           lcddisp(0x15);

           lcddisp(0x15);

           lcddisp(0x17);
           lcddisp(0x15);
           lcddisp(0x17);
           lcddisp(0x00);
           //2nd
           
           lcddisp(0x00);
           lcddisp(0x1f);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x13);
           lcddisp(0x13);
           lcddisp(0x01);
           //3
           lcddisp(0x00);
           lcddisp(0x1f);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x00);
           //4
           lcddisp(0x04);
           lcddisp(0x1f);
           lcddisp(0x15);
           lcddisp(0x15);
           lcddisp(0x15);
           lcddisp(0x17);
           lcddisp(0x17);
           lcddisp(0x05 );
           //5
           lcddisp(0x00);
           lcddisp(0x00);
           lcddisp(0x1f);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x1d);
           lcddisp(0x15);
           lcddisp(0x1d);
           //6
            lcddisp(0x00);
           lcddisp(0x00);
           lcddisp(0x1f);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           //7
           lcddisp(0x07);
           lcddisp(0x05);
           lcddisp(0x1f);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           lcddisp(0x11);
           
           
           lcdctrl(0x80);
           lcddisp(0x00);
           lcddisp(0x01);
           lcddisp(0x02);
           lcddisp(0x03);
           lcddisp(0x04);
           lcddisp(0x05);
           lcddisp(0x06);
           
           
          
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
