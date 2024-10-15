
#include <xc.h>
void delay(void);
void main(void) {
    
    TRISC=0x00;
    TRISD=0x00;
    T0CON=0xc7;
    TMR0=0x00;
    while(1){
        PORTD=0xaa;
        delay();
        PORTD=0x00;
        delay();
        
    }
    
    return;
}
void delay(void){
    while(TMR0IF==0);
    TMR0IF=0;
    TMR0=0x00;
}