/*
 * sendData.c
 *
 * Created: 2020-12-22 ���� 12:43:45
 * Author: embedded_29
 */
  /*
#include <mega128a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{

    float a = 12.34568;
    UCSR0A = 0x0;
    UCSR0B = 0b00001000;
    UCSR0C = 0b00000110;
    UBRR0H = 0;
    UBRR0L = 103;
    printf("%f\t",a);     
    
while (1)
    {
    // Please write your application code here

    }
}
*/

//project�� configure���� printf feature�� float�� �ٲ�� �Ǽ��� ��µȴ�.


 /*

//
// ������ �͹̳�(VT100 �ܸ���) ���� RS232�� ���� ������
//
// �����Ϸ� : �ڵ����
//
// CPU : ATMEGA128
// ��  �� : USART0 �۽Ž���     
// ��  �� : BAUD = 38.4K, DataBit = 8 bit, StopBit = 1, Parity = None;
//        
//      Set Attribute Mode    <ESC>[{attr1};{attr2};{attr3}m
//          attr1               attr2(Foreground Colours)  {attr3}(Background Colours)
// 0    Reset all attributes     30    Black               40    Black            
// 1    Bright                       31    Red                 41    Red              
// 2    Dim                          32    Green              42    Green            
// 4    Underscore               33    Yellow             43    Yellow           
// 5    Blink                        34    Blue                 44    Blue             
// 7    Reverse                   35    Magenta           45 Magenta          
// 8 Hidden                        36 Cyan                   46 Cyan             

#include <mega128.h>
#include <stdio.h>
#include <delay.h>

#include <stdlib.h>

#define  ESC 27

void main(void)
{  
    int count = 0;

    float a= 12.34567;

    char str[10];
    
     // USART �ʱ�ȭ
    UCSR0A = 0x0;
    UCSR0B = 0b00001000;     // �۽� �ο��̺� TXEN = 1
    UCSR0C = 0b00000110;     // �񵿱� ������ 8��Ʈ ���      
    UBRR0H = 0;                   // X-TAL = 16MHz �϶�, BAUD = 38.4K
    UBRR0L = 103;                  // 25 : 38.4K  103 : 9600

    a = a/2.0;
     

    ftoa(a,7,str);                              // float�� string�� ��ȯ      

 
    printf( "%c[1;32;47m",ESC );        // ����� ����
    
    while(1)
    {
       ++count; 
      
        printf("        Hello World \r\n");

  
        printf(" %s \r\n" ,str); 

     

         // �޴�ȭ�鿡�� Project => Config => C compiler => (s)printf Features ����  float,witdth,precision ����


        printf(" %f  \r\n", a);    


        if(count > 10)
        {
             delay_ms(1000); 
             printf( "%c[2J", ESC );     // ȭ��Ŭ����       
             count = 0;
        } 

    }
}

*/



#include <mega128a.h>
#include <delay.h>

flash unsigned char ledArray[9] = {0x0, 0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80} ;

void main(void)
{  
    unsigned char rcvData, data=0;
   
    DDRC = 0xff;
    PORTC = 0b00000000;
   
    UCSR0A = 0x0;
    UCSR0B = 0b00010000;
    UCSR0C = 0b00000110;
    UBRR0H = 0;
    UBRR0L = 103;
  
//portc = 0x0 �� ����  
while (1)
    {
        while((UCSR0A & 0x80) == 0x0){
        
            PORTC = ledArray[data];  
            delay_ms(1000); 
            //PORTC = ledArray[0];  
            data =0;   
        }     
        
         rcvData = UDR0;  
          
         if(rcvData>='0' && rcvData<='8'){
    
         data = rcvData-'0'; 
       
         
         }

    }
}

