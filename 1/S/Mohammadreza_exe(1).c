/*
 * Mohammadreza_exe(1).c
 *
 * Created: 11/8/2021 2:09:21 PM
 * Author: Administrator
 */

#include <mega16.h>     
#include <delay.h> 

void main(void){
    char seg[]={0b10111111,0b00111111,0b00000111,0b01111101};
    DDRA=0XFF;      //port A is being used to switch 7-seg
    DDRD=0X00;      //port D is being used for the Button
    PORTD=0x01;     //res for the pull up button in pin 1
    DDRB=0xFF;      //port B is the output for the LEDs & the DP,G,F,E,D,C,B,A parts of each 7-seg
    PORTB=0X00;     //default value for port B 

    while (1){
        if(PIND.0==1);  //so that the it does't start untill the Button is pressed
        delay_ms(200);  //so that the circuit knows you have pressed the button  
        
        if(PIND.0==0){  //so that it can start
            delay_ms(200);
            
            while (1){
                PORTA= 0b11111110;
                PORTB=seg[0];
                delay_ms(10);
                                                     
                PORTA= 0b11111101;
                PORTB=seg[1];
                delay_ms(10);

                PORTA= 0b11111011;
                PORTB=seg[2];
                delay_ms(10);

                PORTA= 0b11110111;
                PORTB=seg[3];
                delay_ms(10);
                
                if (PIND.0==0){ //if the button is pressed again
                    delay_ms(200);
                    PORTB=0;
                    break;
                }
            }
        } 
    }  
}