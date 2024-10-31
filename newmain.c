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
unsigned char clock_out = 0;
unsigned char clock_out_2 = 0;
unsigned char a = 1;
unsigned char b = 0;
void main(void) {
   GPIO = 0b00000000;
   TRISGPIO = 0b00000000;
   //ADCON0 &= ~((1<<ANS1) | (1<<ANS0));
   ADCON0 = 0b00000000;
   CM1CON0 = 0b01010001;
   OPTION /*REG*/ = 0b10000000;
   TMR0 = 0;
   while (a == 1){
   for(y = 0; y < 800; y++){//Частота 43 kHz 
          GPIO = 0b00010001; 
          GPIO = 0b00100001;
           __delay_us(300);  //12   58  300(13,8kHz)
           GPIO = 0b00010001;
	    }
   GPIO = 0;
   __delay_ms(500);
   b += 1 ;
   if (b >= 2) a = 0; 
   }
//==============================================================================  
    while(1){   
       while (clock_out == 0){//1
      x ++;
      t = 0;
      p = 0;
      GPIO = 0b00100001;// 0b00100001
      GPIO = 0b00010001; //0b00010001
      __delay_us(28);  //18(13,8kHz)
      GPIO = 0b00100001;//0b00100001
       if (x >= 65500) {
            clock_out = 1;
        } 
        }
//---------------------------------------      
       while (clock_out == 1){//2
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(26);  //18(13,8kHz) 
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
      GPIO = 0b00100001;//0b00100001 
      GPIO = 0b00010001;//0b00010001
      __delay_us(24);  //18(13,8kHz) 
      GPIO = 0b00100001;//0b00100001
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
      __delay_us(22);  //18(13,8kHz) 
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
      GPIO = 0b00100001;//0b00100001 
      GPIO = 0b00010001;//0b00010001 
      __delay_us(20);  //18(13,8kHz) 
      GPIO = 0b00100001;//0b00100001
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
      __delay_us(18);  //18(13,8kHz) 
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
      GPIO = 0b00100001;//0b00100001 
      GPIO = 0b00010001;//0b00010001 
      __delay_us(16);  //18(13,8kHz) 
      GPIO = 0b00100001;//0b00100001
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
      __delay_us(14);  //18(13,8kHz) 
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
      GPIO = 0b00100001;//0b00100001 
      GPIO = 0b00010001;//0b00100001
      __delay_us(12);  //18(13,8kHz) 
      GPIO = 0b00100001;//0b00100001
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
      __delay_us(9);  //18(13,8kHz) 
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
      GPIO = 0b00100001;//0b00100001 
      GPIO = 0b00010001;//0b00010001 
      __delay_us(8);  //18(13,8kHz) 
      GPIO = 0b00100001;//0b00100001
             if (x == 65500 && (p == 9 || t == 5)) {
           clock_out = 11;
                 if (t == 5) clock_out = 9;
            p = 10;
        } 
        }                         
//---------------------------------------++
        while (clock_out == 11){//12
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(7);//Задаём частоту излучения 
      GPIO = 0b00100000;
             if (x == 0 && (p == 10 || t == 5)) {
           clock_out = 12;
                 if (t == 5) clock_out = 10;
            p = 11;

        } 
        }     
//---------------------------------------
    while (clock_out == 12){//13
      x ++;
      GPIO = 0b00100101; 
      GPIO = 0b00010101; 
      __delay_us(6);  //18(13,8kHz) 
      GPIO = 0b00100101;
                   if (x == 65500 && (p == 11 || t == 5)) {
          clock_out = 13;
                if (t == 5) clock_out = 11;
            p = 12;
        } 
        }       
//---------------------------------------
        while (clock_out == 13){//14
      x --;
      GPIO = 0b00100000; 
      GPIO = 0b00010000; 
      __delay_us(5);  //18(13,8kHz) 
      GPIO = 0b00100000;
                   if (x == 0 && p == 12) {//Проверяем 
            clock_out = 12;
            t = 5;
        } 
        }    
    }
}

