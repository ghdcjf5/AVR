/*
 * usartTest.c
 *
 * Created: 2020-12-15 ���� 1:37:22
 * Author: embedded_29
 */

#include <mega128a.h>

void putch(char);       //1����Ʈ �۽�

void main(void)
{

char string[] = "why not?";
char *pstr;                  //���ڿ� ������

//USART �ʱ�ȭ
UCSR1A = 0X0;
UCSR1B = 0B00001000;         //�۽� �ο��̺� TXEN = 1        <-BIT3�� �۽ű� �ο��̺��� �Ҵ�.
UCSR1C = 0B00000110;         //�񵿱�, ������ 8��Ʈ ���  8BIT�� �񵿱�    
UBRR1H = 0;
UBRR1L = 103;        //BAUD RATE 9600���� ����

pstr = string;

while(*pstr !=0) putch(*pstr++);           //���ڿ� ����

while(1);  //���

}

//�� ����Ʈ �۽�
void putch(char data){

    while((UCSR1A &0x20) == 0x0);         //UDRE0 =1 �� �ɋ� ���� ��� <-�÷��� ��Ʈ
            //UCSR1A ����, ���� �������� USART ���� ��� ���� ���·�������  
            //UCSR1A �ʱⰪ 0010 0000
    UDR1 = data; //������ ����
         //UDR1 �ۼ��� ������ ���� 8BIT
}