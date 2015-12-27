/* Piano.h
   Configures the off-board piano keys
   Runs on TM4C123
   Program written by: Ronald MacMaster
   Date Created: 3/6/2015
   Last Modified: 9/11/2015                   */


/* **************Piano_Init*********************
   Initialize piano key inputs
   Called once at beginning of program
   Input: none 
   Output: none                               */
void Piano_Init(void);


/* **************Piano_In*********************
 Input from piano key inputs 
 Input: none 
 Output: 0 to 7 depending on keys
 0x01 is Key0, 0x02 is Key1, 0x04 is  Key2    */ 
unsigned int Piano_In(void);
