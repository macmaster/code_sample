/* Song.h
   Controls Song (currently playing)
   Runs on TM4C123
   Program written by: Ronald MacMaster
   Date Created: 3/6/2015
   Last Modified: 9/11/2015                 */


/* ***************Timer_Handler**************
   Parses Data Structure
   Acknowledges device trigger              */
void Timer0A_Handler(void);

/* ******Device Arm & Disarm Functions***** */
/* Play Button (->) */                  
void Song(void);
/* Stop Button (||) */
void Stop(void);
/* Choose Song to Play  */
unsigned int Song_Input(void);



/* **************Song_Init*********************
 Initialize Timer0A periodic interrupts
 Controls the Speed and Rhytmnic Subdivision of the song
 Input: Time Signature Period  (60s/tempo)*bus speed
 Output: nothing                             */
void Song_Init(unsigned int period);


