/*  Sound.h
    SysTick ISR that plays sound
    Runs on TM4C123
    Program written by: Ronald MacMaster
    Date Created: 3/6/2015
    Last Modified: 9/11/2015                   */

/* **************Sound_Init*********************
   Initialize Systick periodic interrupts
   Called once, with sound initially off
   Input: none
   Output: none                                */
void Sound_Init(void);


/* **************Sound_Play*********************
   Start sound output
   Input: interrupt period
     Period = 2500000/Frequency
      Maximum C6, 20000
      Minimum NULL,   1
      Disable Sound,  0
   Output: none                                */
void Sound_Play(unsigned int period);


/* ***************Interrupt Handler**************
   Parses Sound Data Structures
   Automatically Acknowledges Device Trigger   */
void SysTick_Handler(void);  

