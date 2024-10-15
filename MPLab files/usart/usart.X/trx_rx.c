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
    
    while(1)
    {
        
        c=rx();
        //lcddisp(c);
        trx(c);
        
    } 
    while(1){}
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
    LATD=b;
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