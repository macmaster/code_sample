/* Sound.c
   SysTick ISR that plays sounds
   Runs on TM4C123
   Program written by: Ronald MacMaster
   Date Created: 3/6/2015
   Last Modified: 9/11/2015          */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "DAC.h"
#include "Piano.h"

/* ***********DATA STRUCTURES (Editable)**************   
   (dFlute/dt)/4                                       */
const short int delta[32] = {
  0,0,0,0,0,0,0,0,0,0,0,
  -1,0,0,0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,0,0,0,0};

/* Flute(t)  
  Consult dac_flute.xls for more info                  */  
const unsigned short int Flute[32] = {    
  7,9,10,12,13,15,  
  15,15,13,12,10,  
  8,7,6,5,5,4,4,
  4,3,3,2,1,1,  
  0,0,0,1,2,3,4,5  
 };    

 
 /* ***************Interrupt Handler**************
 Parses through the data structure
 Automatically acknowledges the trigger         */
void SysTick_Handler(void){
  
/* Toggle red LED Heartbeat (debugging) */
  GPIO_PORTF_DATA_R ^= 0x02; 
  
/* Parsing: 0 <= k < 32 */
 static short int k = 0; 
  DAC_Out(Flute[k]); 
  k = 0x1F&(k+1);
 }
 
 
/* **************Sound_Play*********************
   Start sound output. Set Systick Interrupt Period
   Only plays notes within valid Range
   Input: interrupt period
     Period = 2500000/Frequency (bus speed / (n of table entries * desired frequency))
      Maximum C6, 20000
      Minimum NULL,   1
      Disable Sound,  0
   Output: none                                */
void Sound_Play(uint32_t period){
  if ((period > 0) && (period < 20000))
    NVIC_ST_RELOAD_R = period - 1; /* Change Note (pitch frequency)  */
  else
    NVIC_ST_RELOAD_R = 0; /* Sound is OFF. */
 }

 
/* **************Sound_Init*********************
   Initialize Systick periodic interrupts
   Called once, with sound initially off
   DO NOT MODIFY
   Input: Nothing
   Output: none                                */
void Sound_Init(void){  
  DAC_Init();  
/* Reload initally with period-1 */
/* Enable interrupts on PL1      */
  NVIC_ST_CTRL_R = 0;  
  NVIC_ST_RELOAD_R = 0x00FFFFFF;  
  NVIC_ST_CURRENT_R = 0;  
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF)|0xE0000000; /* priority 7 */
  NVIC_ST_CTRL_R = 7;  
 }

 





