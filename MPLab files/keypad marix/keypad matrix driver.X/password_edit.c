#include<xc.h>
#include<string.h>
void lcdctrl(unsigned char);
void lcddisp(unsigned char);
void lcdstring(const char *p);
void delay(long int);
unsigned char keypad(void);
void newcode(void);
int c1,c2=0;

unsigned char a;
int index,index2;
char pass[]="1234",inp[]="0000",new[]="0000";//9876
int flag=0;//temprpry variable to check if button for new code is pressed
int flag2=0;
void main(void) {
    ADCON1=0X0F;
    TRISB=0XF0; //1111 0000
    TRISC=0X00;
    TRISD=0x00; 
    lcdctrl(0x38);
   while(1){
       lcdctrl(0x80);
       lcdctrl(0x01);
       lcdstring("Enter code");//to display when lcd is turned on. to take input password
       lcdctrl(0xc0);
       for(index=0;index<4;index++){            
           if(flag==1){
               break;
           }
           else{
           a=keypad();
           switch(a){
               case 'a':
                   index=index-2;//to reduce the array index when backspace is used
                   break; 
               case 'b':
                    lcdctrl(0x01);
                    lcdctrl(0x80);
                    lcdstring("Enter new code");
                    newcode();
                    flag=1;// flag turns 1 if button for new code is pressed
                    index=4;
                    break;

               case 'c':
                    for(index=0;index<4;index++){  //to clear the entire screen and to reset the array index
                        inp[index]==0;
                    }
                    lcdctrl(0x01);
                    return;
            
               default:
                   a=keypad();
                   lcddisp(a);   //if any of the above keys are not pressed then it will directly take input and store it in a variable and go for password checking
                   inp[index]=a;
            }
           
            while(RB4==0||RB5==0||RB6==0||RB7==0); 
           }
       
       }

       delay(10000);
       if(flag==0){// if flag is 0 then it mean the button for new code is note  pressed
       if(strcmp(new,inp)==0){
           lcdctrl(0x01);
           lcdstring("Access Granted");
           for(int j=0;j<10;j++){
               
               lcdctrl(0x08);
               delay(10000);
               lcdctrl(0x0f);
               delay(10000);
           }
       }

       else {           
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
       
       else if(flag==1){                            //if flag is 1 it means the button for new code is pressed 
           
           lcdctrl(0x01);
           lcdctrl(0x80);
           lcdstring("Enter code");                   //displays continue to do next action to see old and new password
           delay(5000);
           lcdctrl(0xc0);
           for(index=0;index<4;index++){  
                   a=keypad();
                   lcddisp(a);   //if any of the above keys are not pressed then it will directly take input and store it in a variable and go for password checking
                   inp[index]=a;
                   while(RB4==0||RB5==0||RB6==0||RB7==0);
           }
           if(strcmp(new,inp)==0){
           lcdctrl(0x01);
           lcdstring("Access Granted");
           for(int j=0;j<10;j++){
               
               lcdctrl(0x08);
               delay(10000);
               lcdctrl(0x0f);
               delay(10000);
           }
       }

       else {           
           lcdctrl(0x01);
           lcdstring("Access Denied");
           for(int j=0;j<10;j++){
               lcdctrl(0x08);
               delay(10000);
               lcdctrl(0x0f);
               delay(10000);
           }
       }

           a=keypad();
           
           
           while(RB6==0);
                    
       }

   
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
void newcode(void){             //function to take new code 
    lcdctrl(0xc0);
    for(index2=0;index2<4;index2++){
        a=keypad();
        switch(a){                // backspace part
            case 'a':
                index2=index2-2;
                break; 
            case 'c':                                   // clear part
                for(index2=0;index2<4;index2++){           
                    new[index2]==0;
                }
                lcdctrl(0x01);
                break;   
            default:              //store input 
                a=keypad();
                lcddisp(a);
                
                new[index2]=a;
        }
        while(RB4==0||RB5==0||RB6==0||RB7==0); 
        
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
            
            return 'b';
         
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
            
            return 'c';
            
        }
        else if(RB6==0)
        {
            lcdctrl(0x01);
            if(c2==2){
                c2=0;
            }
            c2++;
            while(RB6==0);
            if(c2==1){                    //to print old and new code 1st click old code 2 nd click new code
                lcdctrl(0x80);
                lcdstring("old code is");
                lcdctrl(0xc0);
                for(index=0;index<4;index++){
                    lcddisp(pass[index]);
                }
            }
            else if(c2==2){
                lcdctrl(0x80);
                lcdstring("new code is");
                lcdctrl(0xc0);
                for(index=0;index<4;index++){
                    lcddisp(new[index]);
                }
            }
            else{
                break;
            }
        }
        else if(RB7==0)
        {
            
        }
        }
     
}