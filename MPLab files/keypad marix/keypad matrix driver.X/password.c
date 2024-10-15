  #include<xc.h>
#include<string.h>
void lcdctrl(unsigned char);
void lcddisp(unsigned char);
void lcdstring(const char *p);
void delay(long int);
unsigned char keypad(void);
int c1=0;
void main(void) {
    ADCON1=0X0F;
    TRISB=0XF0; //1111 0000
    TRISC=0X00;
    TRISD=0x00; 
    lcdctrl(0x38);
    
    int index;
    char pass[]="1234",inp[]="0000";
    
   while(1){
       lcdctrl(0x80);
       lcdctrl(0x01);
       lcdstring("Enter Password");
       lcdctrl(0xc0);
       for(index=0;index<4;index++){
            unsigned char a=keypad();
            if(a=='a'){
                index=index-2;
                
            }
            else if(a=='b')
            {
                for(index=0;index<4;index++){
                    inp[index]==0;
                }
                return;
            }
            else{
            lcddisp(a);
            inp[index]=a;
            }
            while(RB4==0||RB5==0||RB6==0||RB7==0);
       }
       delay(10000);
       if(strcmp(pass,inp)==0){
           lcdctrl(0x01);
           lcdstring("Access Granted");
           for(int j=0;j<10;j++){
               
               lcdctrl(0x08);
               delay(10000);
               lcdctrl(0x0f);
               delay(10000);
           }
       }
       else{
           
           lcdctrl(0x01);
           lcdstring("Access Denied");
           for(int j=0;j<10;j++){
               lcdctrl(0x08);
               delay(10000);
               lcdctrl(0x0f);
               delay(10000);
           }
           
           
       }
   }
    return;
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
unsigned char keypad(void){
     
        while(1){
        PORTB=0X0e;//0000 1110
        if(RB4==0)
        {
         return '9';   
        }
        else if(RB5==0)
        {
            return '8';
        }
        else if(RB6==0)
        {
            return '7';
        }
        else if(RB7==0)
        {
            lcdctrl(0x10);  //backspace 
            lcddisp(' '); 
            lcdctrl(0x10);
            while(RB7==0);
            return 'a';
            
        }
        PORTB=0X0D;//0000 1101
         if(RB4==0)
        {

             return '6';
        }
        else if(RB5==0)
        {

            return '5';
        }
        else if(RB6==0)
        {

            return '4';
        }
        else if(RB7==0)
        {

           
        }

        PORTB=0X0B;
         if(RB4==0)
        {

             return '3';
        }
        else if(RB5==0)
        {

            return '2';
        }
        else if(RB6==0)
        {

            return '1';
        }
        else if(RB7==0)
        {

            
        }
        PORTB=0X07;
        if(RB4==0){
            if(c1==2){
                c1=0;
            }
            c1++;
            while(RB4==0);
            if(c1==1){
                lcdctrl(0x0f);
            }
            else if(c1==2){
                lcdctrl(0x08);
            }
        }

        else if(RB5==0)
        {
            lcdctrl(0x01);
            return 'b';
            
        }
        else if(RB6==0)
        {

           
        }
        else if(RB7==0)
        {
            
        }
        }
     
}


/*PORTB=0X0E;
    if(RB4==0)
    {
        RC0=1;
    }
    else if(RB5==0)
    {
        RC1=1;
    }
    else if(RB6==0)
    {
        RC2=1;
    }
    else if(RB7==0)
    {
        RC3=1;
    }
    PORTB=0X0D;
     if(RB4==0)
    {
        RC4=1;
    }
    else if(RB5==0)
    {
        RC5=1;
    }
    else if(RB6==0)
    {
        RC6=1;
    }
    else if(RB7==0)
    {
        RC7=1;
    }
    PORTB=0X0B;
     if(RB4==0)
    {
        RC0=0;
    }
    else if(RB5==0)
    {
        RC1=0;
    }
    else if(RB6==0)
    {
        RC2=0;
    }
    else if(RB7==0)
    {
        RC3=0;
    }
    PORTB=0X07;
    if(RB4==0)
    {
        RC4=0;
    }
    else if(RB5==0)
    {
        RC5=0;
    }
    else if(RB6==0)
    {
        RC6=0;
    }
    else if(RB7==0)
    {
        RC7=0;
    }
    }*/