
             /*
//����2] led�� pc0~ pc7���� ���������� ����Ʈ �ϴ� ���α׷�


#include <mega128a.h>
#include <delay.h>
void main(void)
{  unsigned char i,shift;
   DDRC = 0xff; //���
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

//����3]pc0,2,4,6 on off �ݺ��ڵ�


#include <mega128a.h>
#include <delay.h>
void main(void)
{  
   DDRC = 0xff; //���
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

//����4]pa0 ����ġ ������ led on pa1 ����ġ ������ led off

#include <mega128a.h>

void main(void)
{  
   unsigned char sw; 
   DDRA = 0x00; //�Է�
   DDRC = 0xff; //���
   PORTC = 0xff; 
  
   //PINA�� �ʱⰪ�� 0x00
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










    

//����5] �� ���� ����Ĥ ���ÿ� ������ ��� led 300ms�������� on off 5�� �ݺ�



#include <mega128a.h>
#include <delay.h>
void main(void)
{  
   unsigned char i, sw,cnt =0; 
   DDRA = 0x00; //�Է�
   DDRC = 0xff; //���
   PORTC = 0xff; 
  
   //PINA�� �ʱⰪ�� 0x00
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
 

