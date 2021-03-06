/*

#include <delay.h>
#include <mega128a.h>       
       // 과거 현재     과거 현재
#define QS0 0x00   // 00  00 S0 -> S0 무변화
#define QS1 0x01   // 00  01 S0 -> S1 +증가  check
#define QS3 0x03   // 00  11 S0 -> S2 ?
#define QS2 0x02   // 00  10 S0 -> S3 -감소  check

#define QS4 0x04   // 01  00 S1 -> S0 -감소
#define QS5 0x05   // 01  01 S1 -> S1 무변화
#define QS7 0x07   // 01  11 S1 -> S2 +증가
#define QS6 0x06   // 01  10 S1 -> S3 ?

#define QSC 0x0C   // 11  00 S2 -> S0 ?
#define QSD 0x0D   // 11  01 S2 -> S1 -감소
#define QSF 0x0F   // 11  11 S2 -> S2 무변화
#define QSE 0x0E   // 11  10 S2 -> S3 +증가

#define QS8 0x08   // 10  00 S3 -> S0 +증가
#define QS9 0x09   // 10  01 S3 -> S1 ?
#define QSB 0x0B   // 10  11 S3 -> S2 -감소
#define QSA 0x0A   // 10  10 S3 -> S3 무변화

void main(void)
{
  unsigned char t, cq, pq,counter = 0,cnt=0;
//unsigned char
  DDRC = 0xFF; //led 출력
  DDRA = 0x00; //엔코더 입력   
  while(1)
  {
    cq = PINA & 0x03; //0000 0011 & 0b0000 0011    ->0000 0011   
                      //0000 0010 & 0000 0011  ->0000 0010  
                       //0000 0000  & 0000 0011  ->0000 0000  
                      //0000 0001   & 0000 0011  ->0000 0001
                    
    //pq = 0b0000 0011
  
    t = (pq << 2) | cq;      //0000 1100 or  0000 0011  --> 0000 1111;   
                             //0000 1100 or  0000 0010  -> 0000 1110;   
                             //1111 1000 OR 0000 0000 -> 1111 1000;
                             //
    pq = cq;   //0000 0011;   
                //0000 0010;
                //0000 0001;  
   
   switch(t)
    {   
      case QS1: counter++; break; //증가
      case QS2: counter--; break; //감소
      case QS4: counter--; break; //감소
      case QS7: counter++; break; //증가 
      case QSD: counter--; break; //감소 
      case QSE: counter++; break; //증가 
      case QS8: counter++; break; //증가
      case QSB: counter--; break; //감소
    }
    if(counter < 0 ) counter = 0;
     
    
    PORTC =  counter;
   
    
   } 
  
}


*/
 
#include <delay.h>
#include <mega128a.h>       
       // 과거 현재     과거 현재
#define QS0 0x00   // 00  00 S0 -> S0 무변화
#define QS1 0x01   // 00  01 S0 -> S1 +증가  check
#define QS3 0x03   // 00  11 S0 -> S2 ?
#define QS2 0x02   // 00  10 S0 -> S3 -감소  check

#define QS4 0x04   // 01  00 S1 -> S0 -감소
#define QS5 0x05   // 01  01 S1 -> S1 무변화
#define QS7 0x07   // 01  11 S1 -> S2 +증가
#define QS6 0x06   // 01  10 S1 -> S3 ?

#define QSC 0x0C   // 11  00 S2 -> S0 ?
#define QSD 0x0D   // 11  01 S2 -> S1 -감소
#define QSF 0x0F   // 11  11 S2 -> S2 무변화
#define QSE 0x0E   // 11  10 S2 -> S3 +증가

#define QS8 0x08   // 10  00 S3 -> S0 +증가
#define QS9 0x09   // 10  01 S3 -> S1 ?
#define QSB 0x0B   // 10  11 S3 -> S2 -감소
#define QSA 0x0A   // 10  10 S3 -> S3 무변화

void main(void)
{
  unsigned char t, cq, pq,counter = 0,cnt=0;
//unsigned char
  DDRC = 0xFF; //led 출력
  DDRA = 0x00; //엔코더 입력   
  while(1)
  {
    cq = PINA & 0x03; //0000 0011 & 0b0000 0011    ->0000 0011   
                      //0000 0010 & 0000 0011  ->0000 0010  
                       //0000 0000  & 0000 0011  ->0000 0000  
                      //0000 0001   & 0000 0011  ->0000 0001
                    
    //pq = 0b0000 0011
  
    t = (pq << 2) | cq;      //0000 1100 or  0000 0011  --> 0000 1111;   
                             //0000 1100 or  0000 0010  -> 0000 1110;   
                             //1111 1000 OR 0000 0000 -> 1111 1000;
                             //
    pq = cq;   //0000 0011;   
                //0000 0010;
                //0000 0001;  
   
   switch(t)
    {   
      case QS1: counter++; break; //증가
      case QS2: counter--; break; //감소
      case QS4: counter--; break; //감소
      case QS7: counter++; break; //증가 
      case QSD: counter--; break; //감소 
      case QSE: counter++; break; //증가 
      case QS8: counter++; break; //증가
      case QSB: counter--; break; //감소
    }
    if(counter < 0 ) counter = 0;
     
    switch(counter%9)
    {
        case 1: cnt=0b00000001;  break;  
        case 2: cnt=0b00000010;  break; 
        case 3: cnt=0b00000100;  break;
        case 4: cnt=0b00001000;  break;
        case 5: cnt=0b00010000;  break;
        case 6: cnt=0b00100000;  break;
        case 7: cnt=0b01000000;  break;
        case 8: cnt=0b10000000;  break; 
       

       // default: PORTC=0b00000000;  break;
    }
    
            PORTC = cnt;
   
    
   } 
  
}