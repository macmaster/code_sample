/* Piano.c
   Configures the off-board piano keys
   Runs on TM4C123
   Program written by: Ronald MacMaster
   Date Created: 3/6/2015
   Last Modified: 9/11/2015                   */
#include <stdint.h>
#include "tm4c123gh6pm.h"

/* **************Piano_Init*********************
   Initialize piano key inputs
   Called once at beginning of program
   Input: none 
   Output: none                               */
void Piano_Init(void){
  
  unsigned int dummy;
  SYSCTL_RCGC2_R |= 0x10;  /* Turn on Ports A and E */
  dummy = SYSCTL_RCGC2_R;
  dummy++;

/*  ******** Switch Init & PortE_Init ************
   Initializes the 3 switches for piano. All inputs on PE0-2.  
  Can add more switches by adding pins and/or ports
  Verify all are enabled through debug.         */
  GPIO_PORTE_DIR_R &= 0xF8;
  GPIO_PORTE_AMSEL_R &= 0x00;
  GPIO_PORTE_AFSEL_R &= 0x00;
  GPIO_PORTE_DEN_R |= 0x07;  
  
 }

/* **************Piano_In*********************
 Input from piano key inputs 
 Input: none 
 Output: 0 to 7 depending on keys
 0x01 is Key0, 0x02 is Key1, 0x04 is  Key2    
 Test each key individually.
 Add more switches by increasing mask and changing init */
unsigned int Piano_In(void){
  return (GPIO_PORTE_DATA_R&0x07); /* Gives you the input from of all the keys as a bit vector */
}
