#include <xc.h>
void trx(char a);
void delay();
char rx();
void lcddisp(char b);
void lcdctrl(int a);
void main(void) 
{
    TRISC=0X80;
    TRISD=0X00;
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=129;
    lcdctrl(0X38);
	lcdctrl(0X01);
	lcdctrl(0x0F);
	lcdctrl(0X0E);
	lcdctrl(0X80);
    char c;
    int flag1=0,flag2=0;
    while(1)
    {
        
        c=rx();
        switch(c)
        {
            case '#':
                flag1=1;
                break;
            case '*':
                flag2=1;
                break;
            default:
                if(flag1==1){
                    if(flag2==0){
                        trx(c);
                    }
                    else if(flag2==1){
                        return;
                    }
                }
        }
                
    }
} 
    

void trx(char a)
{  
    TXREG=a;
    while(TXIF==0);
    TXIF=0;
    
}
char rx()
{
    while(RCIF==0);
    return(RCREG);
            
}
void lcddisp(char b)
{
    PORTD=b;
    RC0=1;
    RC1=1;
    delay();
    RC1=0;
}
void lcdctrl(int a){
    PORTD=a;
    RC0=0;
    RC1=1;
    delay();
    RC1=0;
}
void delay()
{
    int i,j;
    for(i=0;i<=200;i++)
    {
        for(j=0;j<=200;j++)
        {
        }
    }

}