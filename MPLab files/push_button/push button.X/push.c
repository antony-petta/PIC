#include <xc.h>
  void main(void) {
      TRISC=0x01;
      TRISD=0x00;
      int count=0;
      while(1){
         if(RC0==1){
           if(count==3)
            {
                count=0;
            }
            count++;
            
            while(RC0==1);
        }
         if(count==1)
            {
            PORTD=0X01;
            
            }
            else if(count==2)
            {
            PORTD=0X00;
            
            }
            else  if(count==3){
                    PORTD=0X01;
                    for(unsigned int i=0;i<=65000;i++);
                    PORTD=0X00;
                    for(unsigned int i=0;i<=65000;i++);
            }    
    }
  }