/*
 * usartTest.c
 *
 * Created: 2020-12-15 오후 1:37:22
 * Author: embedded_29
 */

#include <mega128a.h>

void putch(char);       //1바이트 송신

void main(void)
{

char string[] = "why not?";
char *pstr;                  //문자열 포인터

//USART 초기화
UCSR1A = 0X0;
UCSR1B = 0B00001000;         //송신 인에이블 TXEN = 1        <-BIT3의 송신기 인에이블을 켠다.
UCSR1C = 0B00000110;         //비동기, 데이터 8비트 모드  8BIT의 비동기    
UBRR1H = 0;
UBRR1L = 103;        //BAUD RATE 9600으로 설정

pstr = string;

while(*pstr !=0) putch(*pstr++);           //문자열 전송

while(1);  //대기

}

//한 바이트 송신
void putch(char data){

    while((UCSR1A &0x20) == 0x0);         //UDRE0 =1 이 될떄 까지 대기 <-플래그 비트
            //UCSR1A 제어, 상태 레지스터 USART 동작 모드 설정 상태레지스터  
            //UCSR1A 초기값 0010 0000
    UDR1 = data; //데이터 전송
         //UDR1 송수신 데이터 저장 8BIT
}