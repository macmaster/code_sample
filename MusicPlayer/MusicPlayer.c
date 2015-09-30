/* Music Player.c
   Runs on TM4C123
   Utilizes interrupts, Calculus, and Superposition of Harmonic Waves 
      to implement a 4-key digital piano / music player
   Program written by: Ronald Macmaster
   Date Created: 3/6/2015
   Last Modified: 9/11/2015     
   V.3.2 Replatformed to ANSI C with Chord Functionality    */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "TExaS.h"
#include "Sound.h"
#include "Piano.h"
#include "DAC.h"
#include "Song.h"
#include "mp3.h"

/* Periods calculated for tempo at 144 bpm
 beat period = (60s/tempo)*bus speed 
#define sixteenth_note 8000000
#define eigth_note 1600000         */
#define quarter_note 32000000
#define half_note 60000000

/* Slower (120bpm)                */
#define sixteenth_note 10000000
#define eigth_note 20000000        
/* #define quarter_note 40000000
   #define half_note 80000000     */ 


/* Basic functions defined at end of startup.s */
void DisableInterrupts(void); /* Disable interrupts   */
void EnableInterrupts(void);  /* Enable interrupts    */
void Debug_Init(void); /* User Debugging              */    

/* Here is the appplied approach to generating chords:
   Instead of processing only 1 wave with alternating frequency,
   Allow each succesive interrupt to contribute a dAmp/dt from the sine wave data structure
   Result: Master wave composed of 3 different signals (Sounds like a chord)             */

/* Amplitude of the Master Wave  */
volatile unsigned int amp = 8;

/* Flag: 
  Song is playing(1)
  Song is stopped (0)    */
volatile unsigned int song_flag = 0;

int main(void){      
  
  unsigned int note, play;

  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PA5432,ScopeOn);    /* bus clock at 80 MHz */

  /* Initialization Phase */
    Sound_Init();    
    Debug_Init();       
    Piano_Init();  
    Song_Init(eigth_note);  /* Input = Rhythmnic Subdivision */
    Stop();
    EnableInterrupts();
  
  while(1){                
    GPIO_PORTF_DATA_R ^= 0x04; /* Toggle blue LED Heartbeat (debug) */
    
   /* Plays Song after play button  is pressed 
     Disables Piano while song is playing    */
    play = Song_Input();
  while(play){
    play = Song_Input();
    Song();
    /* Stops song when stop button is pressed */ 
    if(!play)
      Stop();
   }
  
 /* Digital Piano */
 /* Consult Piano.h for more info */  
    note = Piano_In();
    switch(note){
      case (1):
        note = AF0;
        break;
      case (2):
        note = DF;
        break;
      case (4):
        note = F;
        break;
      default:
        note = 0;
      }
    Sound_Play(note);      
    }         
  }


/* ************Debug_Init**********************
  Activates Port F For the Debugging tools
  Uses LED Heartbeats.                        */
void Debug_Init(void){
  uint32_t dummy;
  SYSCTL_RCGC2_R |= 0x20;
  dummy = SYSCTL_RCGC2_R;
  dummy++;
  
  GPIO_PORTF_LOCK_R = 0x4C4F434B;  /* unlock port F */
   GPIO_PORTF_CR_R = 0x0F;
  GPIO_PORTF_PUR_R = 0x01;
  GPIO_PORTF_DIR_R = 0x0E;
  GPIO_PORTF_AMSEL_R = 0x00;
  GPIO_PORTF_AFSEL_R = 0x00;
  GPIO_PORTF_DEN_R = 0x00F;
}

