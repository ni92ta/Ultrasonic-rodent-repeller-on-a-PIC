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
unsigned int p;
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
   TMR0 = 0;
   //OPTION = 0b10110000;//0bxx0xxxxx Тактирование таймера
   //CM1CON0 = 0b11110000;
  
    /*   if (clock_out == 0){
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
         }}*/
  // __delay_ms(00);
//==========================================================   
    while(1){

       
        if (clock_out == 0){
              if (x >= 6){
      t++;
  }
  else{
      y = 0;
  }
     	for(; y < 65000; y++){//Частота 43 kHz
         // GPIO = 0b00100000; 
          GPIO = 0b00010000; 
		  // GP5 = 1;
          // GP4 = 0;
          //GPIO = 0b00010000;
          GPIO = 0b00100000;
           //GP5 = 0;
           //GP4 = 1;
           __delay_us(5);  //12   58  300(13,8kHz)
           //GPIO = 0b00100000; 
           GPIO = 0b00010000;
           //GP5 = 1;
           //GP4 = 0;
	    }       
  x ++;

         if (t >= 6){
    y = 0; 
    x = 0; 
    clock_out = 1;
    t = 0;
  }
        }
//---------------------------------------
        if (clock_out == 1){
       	for(; y < 65530; y++){//Частота 34 kHz
            GPIO = 0b00100000; 
		  // GP5 = 1;
           //GP4 = 0;
            GPIO = 0b00010000; 
           //GP5 = 0;
          // GP4 = 1;
           __delay_us(30);   //16  
           GPIO = 0b00100000; 
           //GP5 = 1;
           //GP4 = 0;
	    }        
  x ++;
  if (x >= 6){
      t++;//
  }
  else{
      y = 0;
  }
         if (t >= 6){
    y = 0; 
    x = 0;
    clock_out = 2;
    t = 0;
  }
        }
//---------------------------------------  
        if (clock_out == 2){
       	for(; y < 65530; y++){//Частота 29 kHz
            GPIO = 0b00100000; 
		  // GP5 = 1;
          // GP4 = 0;
                        
        GPIO = 0b00010000; 
           //GP5 = 0;
           //GP4 = 1;
           __delay_us(40);   //20 
           GPIO = 0b00100000; 
          // GP5 = 1;
          // GP4 = 0;
	    }        
  x ++;
  if (x >= 6){
      t++;
  }
  else{
      y = 0;
  }
         if (t >= 6){
    y = 0; 
    x = 0;
    clock_out = 0;
    t = 0;
  }
        }
//---------------------------------------  

  
/*
 * 44kHz 9us
 * 40kHz 10us
 * 28kHz 15us 
 * 21kHz 20us
 * 
 * 18kHz 24us
 * 17kHz 25us
 */        


      
    }
}

