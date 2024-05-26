/* 
 * File:   newfile.h
 * Author: Никита
 *
 * Created on 12 марта 2024 г., 20:10
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

#define _XTAL_FREQ 8000000

#ifdef	__cplusplus
extern "C" {
#endif


// PIC12F510 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config OSC = IntRC      // Oscillator Select (INTOSC with 1.125 ms DRT)
#pragma config WDT = OFF         // Watchdog Timer Enable bit (WDT enabled)
#pragma config CP = OFF         // Code Protect (Code protection off)
#pragma config MCLRE = ON       // Master Clear Enable bit (GP3/MCLR Functions as MCLR)
#pragma config IOSCFS = ON      // Internal Oscillator Frequency Select bit (8 MHz INTOSC Speed)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>


#ifdef	__cplusplus
}
#endif

#endif	/* NEWFILE_H */

