/* DAC.c
   Configures the DAC Output
   Runs on TM4C123
   Program written by: Ronald MacMaster
   Date Created: 3/6/2015
   Last Modified: 9/11/2015                   */

#include <stdint.h>
#include "tm4c123gh6pm.h"

/* **************DAC_Init*********************
   Initialize 4-bit DAC
   Called once at beginning of program
   Input: none 
   Output: none                               
   PA 2-5 are DAC OUTPUT
   PE 0-2 are the Switch Inputs              */
void DAC_Init(void){
  
  unsigned int dummy;
  SYSCTL_RCGC2_R |= 0x10;  /* Turn on Ports A and E */
  dummy = SYSCTL_RCGC2_R;
  dummy++;
  
/* Activates Port A for the DAC and sets PA2-5 as Bits 0-3 on the DAC. 
   Call it once at beginning of program. 
   Test by verifying desired Port and Pins turn on and are enabled. 
   Can be edited to use different Port or pins as desired            */
  
  GPIO_PORTA_DIR_R |= 0x3C;
  GPIO_PORTA_AMSEL_R &= 0x00;
  GPIO_PORTA_AFSEL_R &= 0x00;
  GPIO_PORTA_DEN_R |= 0x3C;    
  
 }
 
/* **************DAC_Out*********************
 Output the value of data to DAC 
 Range: 3.3V, Precision: 4 bits, Resolution: 0.22V
 Test by confirming correct digital value is output to ports
 Measure Analog Output with a voltmeter
 Up percision by changing shift and with DAC Init
 Sets the bits of DAC that are set in the actual input after shifts
 Input: 4-bit data, 0 to 15 
 Output: none                                      */
void DAC_Out(unsigned int data){
/* DAC Output is on PA2-5, so left shift 2 bits  */
  GPIO_PORTA_DATA_R = (data << 2);
}



