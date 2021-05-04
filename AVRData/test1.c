

#include <mega128.h>
#include <delay.h>


/*
void main(void){

    DDRC = 0b11111111;
    
    while(1){
    
        PORTC = 0b01010101;      //7 6 5 4 3 2 1 0
        delay_ms(500);
        
        PORTC = 0b10101010;
        delay_ms(500);
    
    }


}

*/

void main(void){

    DDRC = 0b11111111;
    PORTC = 0b00000000;      //7 6 5 4 3 2 1 0    
    
    while(1){
    
        
     
        
        //PORTC ^=0x80;
     //   PORTC =~PORTC;
         PORTC =~PORTC;
        delay_ms(500);
    
    }


}