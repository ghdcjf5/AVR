
             /*
//문제2] led가 pc0~ pc7까지 순차적으로 쉬프트 하는 프로그램


#include <mega128a.h>
#include <delay.h>
void main(void)
{  unsigned char i,shift;
   DDRC = 0xff; //출력
 //  PORTC = 0xff; 
  // shift = 0b00000001;
while (1)
    {   PORTC = 0xff;
        shift = 0x01;
        for(i=0;i<8;i++){     
           
            PORTC = ~(PORTC&shift);
            shift = shift<<1;
            
            delay_ms(500);   
            
        }
       
    }
}
  
 



         */










   /*

//문제3]pc0,2,4,6 on off 반복코드


#include <mega128a.h>
#include <delay.h>
void main(void)
{  
   DDRC = 0xff; //출력
   PORTC = 0xff;
  
while (1)
    {  

            PORTC =0b10101010;
            delay_ms(1000);
            PORTC =0b11111111;  
            delay_ms(1000); 
         
       
       
    }
    
}
*/












  

      /*

//문제4]pa0 스위치 누를시 led on pa1 스위치 누를시 led off

#include <mega128a.h>

void main(void)
{  
   unsigned char sw; 
   DDRA = 0x00; //입력
   DDRC = 0xff; //출력
   PORTC = 0xff; 
  
   //PINA의 초기값은 0x00
while (1)
    {        
     sw = PINA & 0b00000011;  
          if(sw == 0b00000010){
            PORTC = 0x00; 
          }
          if(sw == 0b00000001){
            PORTC = 0xff; 
          }
 
    }
 
  
}  

*/










    

//문제5] 두 개의 스위칟 동시에 누르면 모든 led 300ms간격으로 on off 5번 반복



#include <mega128a.h>
#include <delay.h>
void main(void)
{  
   unsigned char i, sw,cnt =0; 
   DDRA = 0x00; //입력
   DDRC = 0xff; //출력
   PORTC = 0xff; 
  
   //PINA의 초기값은 0x00
while (1)
    {        
     sw = PINA & 0b00000011;  
          if(sw == 0b00000000 && cnt == 0){
         
              for(i=0;i<5;i++){
              
                 PORTC = 0x0;
                 delay_ms(300);  
                 PORTC = 0xff;
                 delay_ms(300); 
                 cnt++;
              }
          
          }
          
          if(sw ==0b00000011) cnt =0;
    }
 
  
}  
 


