/*
 * 4digit7seg.c
 *
 * Created: 2020-12-04 ���� 3:07:17
 * Author: PROCESSOR
 */



#include <mega128a.h>
#include <delay.h>

void main(void)
{

    unsigned char m,i,val,Pval;     
    
    DDRB = 0xff;  7~0-> ������� ��  ��
    DDRF = 0x0f;
    
    PORTF = 0b00001110;
    
    
while (1)
    {
    // Please write your application code here
            for(i=0;i<4;i++){
                
           
             val = 0b00000001; 
             
             Pval = 0b11110001;      //i=1�� �� PORTF = 11100010
             for(m=0;m<8;m++){
                PORTB = val;
                delay_ms(500);
                val =val<<1;
             
             }   
               PORTF = ~(Pval<<i+1);
               //i=0�ϋ� 11100010      ->1101 ���·� �ι�������. �� f0r i 0~4���� Pval�� �ʱ�ȭ
               //i=1    10000100
               //i=2    00001000
               //i=3    00010000 
                     
            } 
            PORTF = 0b00001110;
    }
}




/*
#include <mega128a.h>
#include <delay.h>

void main(void)
{

    unsigned char m,i,val,Pval;     
    
    DDRB = 0xff;  7~0-> ������� ��  ��
    DDRF = 0x0f;
    
    PORTF = 0b00001110;
    
    PORTB = 0b00000000;
while (1)
    {
    // Please write your application code here
           
           
         
             
           
    }
}

*/
