/*
 * File:   newmain.c
 * Author: Никита
 *
 * Created on 12 марта 2024 г., 20:10
 */


#include <xc.h>
#include "newfile.h"
#define _XTAL_FREQ 8000000
unsigned int clock;
unsigned int clock2 = 9;
unsigned int clock3;
unsigned int y = 1;
unsigned int x;
unsigned int p = 0;
unsigned int t;
unsigned int clock_out = 0;
unsigned int clock_out_2 = 0;
//-------------------функция-обработчик задержки------------------
void dela_y (unsigned int i){
    
	for(y = 0; y <= i; y++){
		//__delay_us(1);
	}
}

/*
void Interrupt(void){
// __delay_ms(500);
         GP5 = 1;
       //__delay_ms(500);
        GP5 = 0;    
    TMR0 = 1;
}
*/
void main(void) {
   GPIO = 0b00000000;
   TRISGPIO = 0b00000000;
   //ADCON0 &= ~((1<<ANS1) | (1<<ANS0));
   ADCON0 = 0b00000000;
   CM1CON0 = 0b01011001;
   OPTION /*REG*/ = 0b10000000;
   TMR0 = 0;
   //OPTION = 0b10110000;//0bxx0xxxxx Тактирование таймера
   //CM1CON0 = 0b11110000;
  
      if (clock_out == 0){
              if (x >= 6){
      t++;
  }
  else{
      y = 0;
  }
     	for(; y < 800; y++){//Частота 43 kHz
         // GPIO = 0b00100000; 
          GPIO = 0b00010100; 
		  // GP5 = 1;
          // GP4 = 0;
          //GPIO = 0b00010000;
          GPIO = 0b00100100;
           //GP5 = 0;
           //GP4 = 1;
           __delay_us(600);  //12   58  300(13,8kHz)
           //GPIO = 0b00100000; 
           GPIO = 0b00010100;
           //GP5 = 1;
           //GP4 = 0;
	    }       
  x ++;

         if (t >= 6){
    y = 0; 
    x = 0; 
    clock_out = 0;
    t = 0;
         }}
   __delay_ms(500);
   
          if (clock_out == 0){
              if (x >= 6){
      t++;
  }
  else{
      y = 0;
  }
     	for(; y < 800; y++){//Частота 43 kHz
         // GPIO = 0b00100000; 
          GPIO = 0b00010000; 
		  // GP5 = 1;
          // GP4 = 0;
          //GPIO = 0b00010000;
          GPIO = 0b00100000;
           //GP5 = 0;
           //GP4 = 1;
           __delay_us(600);  //12   58  300(13,8kHz)
           //GPIO = 0b00100000; 
           GPIO = 0b00010000;
           //GP5 = 1;
           //GP4 = 0;
	    }       
  x ++;

         if (t >= 6){
    y = 0; 
    x = 0; 
    clock_out = 0;
    t = 0;
         }}
  // __delay_ms(00);
//==========================================================   
    while(1){   
       while (clock_out == 0){//1
      x ++;
      t = 0;
      p = 0;
      GPIO = 0b00100100; 
      GPIO = 0b00010100; 
      __delay_us(100);  //18(13,8kHz) 
      GPIO = 0b00100100;
       if (x >= 65500) {
            clock_out = 1;
        } 
        }
//---------------------------------------      
       while (clock_out == 1){//2
      x --;
     // t = 0;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(150);  //18(13,8kHz) 
      GPIO = 0b00100000;
       if (x == 0 && (p == 0 || t == 5)) {
            clock_out = 2;
            
            if (t == 5) clock_out = 0;
            p = 1;
        } 
        }       
//---------------------------------------           
       while (clock_out == 2){//3
      x ++;
      GPIO = 0b00100100; 
      GPIO = 0b00010100; 
      __delay_us(200);  //18(13,8kHz) 
      GPIO = 0b00100100;
       if (x >= 65500 && (p == 1 || t == 5)) {
            clock_out = 3;
            
            if (t == 5) clock_out = 1;
            p = 2;
        } 
        }       
//---------------------------------------     
       while (clock_out == 3){//4
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(250);  //18(13,8kHz) 
      GPIO = 0b00100000;
       if (x == 0 && (p == 2 || t == 5)) {
            clock_out = 4;
            
            if (t == 5) clock_out = 2;
            p = 3;
        } 
        }       
//--------------------------------------- 
       while (clock_out == 4){//5
      x ++;
      GPIO = 0b00100100; 
      GPIO = 0b00010100; 
      __delay_us(300);  //18(13,8kHz) 
      GPIO = 0b00100100;
       if (x >= 65500 && (p == 3 || t == 5)) {
            clock_out = 5;
            
            if (t == 5) clock_out = 3;
            p = 4;
        } 
        }     
//---------------------------------------
       while (clock_out == 5){//6
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(350);  //18(13,8kHz) 
      GPIO = 0b00100000;
       if (x == 0 && (p == 4 || t == 5)) {
            clock_out = 6;
             if (t == 5) clock_out = 4;
            p = 5;
        } 
        }       
//---------------------------------------
        while (clock_out == 6){//7
      x ++;
      GPIO = 0b00100100; 
      GPIO = 0b00010100; 
      __delay_us(375);  //18(13,8kHz) 
      GPIO = 0b00100100;
       if (x == 65500 && (p == 5 || t == 5)) {
           clock_out = 7;
            if (t == 5) clock_out = 5;
            p = 6;
        } 
        }       
//---------------------------------------
       while (clock_out == 7){//8---
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(400);  //18(13,8kHz) 
      GPIO = 0b00100000;
       if (x == 0 && (p == 6 || t == 5)) {
           clock_out = 8;
            if (t == 5) clock_out = 6;
            p = 7;
        } 
        }     
//---------------------------------------
        while (clock_out == 8){//9
      x ++;
      GPIO = 0b00100100; 
      GPIO = 0b00010100; 
      __delay_us(425);  //18(13,8kHz) 
      GPIO = 0b00100100;
       if (x == 65500 && (p == 7 || t == 5)) {
           clock_out = 9;
            if (t == 5) clock_out = 7;
            p = 8;
        } 
        }       
//---------------------------------------
       while (clock_out == 9){//10
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(450);  //18(13,8kHz) 
      GPIO = 0b00100000;
       if (x == 0 && (p == 8 || t == 5)) {
           clock_out = 10;
            if (t == 5) clock_out = 8;
            p = 9;
        } 
        }     
//---------------------------------------
        while (clock_out == 10){//11
      x ++;
      GPIO = 0b00100100; 
      GPIO = 0b00010100; 
      __delay_us(475);  //18(13,8kHz) 
      GPIO = 0b00100100;
       if (x == 65500 && p == 9) {
            clock_out = 9;
            t = 5;
        } 
        }       
//---------------------------------------
     /*   while (clock_out == 11){//12
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(500);  //18(13,8kHz) 
      GPIO = 0b00100000;
       if (x == 0 && (p == 10 || t == 5)) {
            if (t == 5) clock_out = 10;
            p = 11;
        } 
        }     
//---------------------------------------
       while (clock_out == 12){//13
      x ++;
      GPIO = 0b00100100; 
      GPIO = 0b00010100; 
      __delay_us(525);  //18(13,8kHz) 
      GPIO = 0b00100100;
       if (x == 65500 && (p == 11 || t == 5)) {
            if (t == 5) clock_out = 11;
            p = 12;
        } 
        }       
//---------------------------------------
       while (clock_out == 13){//14
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(550);  //18(13,8kHz) 
      GPIO = 0b00100000;
       if (x == 0 && (p == 12 || t == 5)) {
            if (t == 5) clock_out = 12;
            //p = 13;
            t = 5;
        } 
        }     
//---------------------------------------
        while (clock_out == 14){//15
      x ++;
      GPIO = 0b00100100; 
      GPIO = 0b00010100; 
      __delay_us(575);  //18(13,8kHz) 
      GPIO = 0b00100100;
       if (x == 65500) {
            clock_out = 0;
        } 
        }    */   
//---------------------------------------
      /* while (clock_out == 7){//16
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(17);  //18(13,8kHz) 
      GPIO = 0b00100000;
       if (x == 0) {
            clock_out = 0;
        } 
        } */    
//---------------------------------------
    }
}

/*
 
        while (clock_out == 7){//8
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(17);  //18(13,8kHz) 
      GPIO = 0b00100000;
       if (x == 0) {
            clock_out = 0;
        } 
        }     
 
 */

