/* DAC.h
   Configures the DAC Output
   Runs on TM4C123
   Program written by: Ronald MacMaster
   Date Created: 3/6/2015
   Last Modified: 9/11/2015                   */

/* **************DAC_Init*********************
   Initialize 4-bit DAC
   Called once at beginning of program
   Input: none 
   Output: none                               */
void DAC_Init(void);

/* **************DAC_Out*********************
   Output to DAC
   Called during ISR
   Give the function a digital output; it outputs an analog voltage
   Range: 3.3V, Precision: 4 bits, Resolution: 0.22V
   Output Analog Voltage = Input*Resolution 
   Input: 4-bit data, 0 to 15 
   Output: none                               */
void DAC_Out(unsigned int data);


