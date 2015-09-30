/* Song.c
   Controls Song (currently playing)
   Runs on TM4C123
   Program written by: Ronald MacMaster
   Date Created: 3/6/2015
   Last Modified: 9/11/2015                 */

#include <stdint.h>
#include "DAC.h"
#include "tm4c123gh6pm.h"
#include "Piano.h"
#include "Sound.h"
#include "mp3.h"

void DisableInterrupts(void); /* Disable interrupts  */
void EnableInterrupts(void);  /* Enable interrupts   */

extern unsigned int amp;             /* Current amplitude of DAC output */
extern unsigned int song_flag;       /* Song Playing , Song Stopped : (1, 0) */
extern const short int delta[32];    /* (dFlute/dt)/4 */
extern const unsigned int Flute[32]; /* Flute(t)  */

void Song_Init(unsigned int period){
/* Timer 0: Head Timer, commands other 3 timers
   Timer 1: Melody
   Timer 2: Harmony
   Timer 3: Bass                              */
  
  DisableInterrupts();
  SYSCTL_RCGCTIMER_R |= 0x0F;   /* 0) activate TIMER0-3    */
  
/* Timer 0A Init. (This guy is boss) Very important PL1  */
  
  TIMER0_CTL_R = 0x00000000;    /* 1) disable TIMER0A during setup                             */
  TIMER0_CFG_R = 0x00000000;    /* 2) configure for 32-bit mode                                */
  TIMER0_TAMR_R = 0x00000002;   /* 3) configure for periodic mode, default down-count settings */
  TIMER0_TAILR_R = period-1;    /* 4) reload value                                             */
  TIMER0_TAPR_R = 0;            /* 5) bus clock resolution                                     */
  TIMER0_ICR_R = 0x00000001;    /* 6) clear TIMER0A timeout flag                               */
  TIMER0_IMR_R = 0x00000001;    /* 7) arm timeout interrupt                                     */
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x20000000; /* 8) priority 1                          */
  /* interrupts enabled in the main program after all devices initialized                      */
  /* vector number 35, interrupt number 19                                                      */
  NVIC_EN0_R |= 1<<19;           /* 9) enable IRQ 19 in NVIC                                    */
 
/* ********** Backup Timers *************** */
/* Each on a lower, equivalent priority level 
    Reload is nothing to start with (Will be assigned by Timer0) */
 
  TIMER3_CTL_R = TIMER2_CTL_R = TIMER1_CTL_R = 0x00000000;    /* 1) disable TIMER1-3A during setup                            */
  TIMER3_CFG_R = TIMER2_CFG_R = TIMER1_CFG_R = 0x00000000;    /* 2) configure for 32-bit mode                                */ 
  TIMER3_TAMR_R = TIMER2_TAMR_R = TIMER1_TAMR_R = 0x00000002; /* 3) configure for periodic mode, default down-count settings */
  TIMER3_TAILR_R = TIMER2_TAILR_R = TIMER1_TAILR_R = 0;       /* 4) reload value                                              */
  TIMER3_TAPR_R = TIMER2_TAPR_R = TIMER1_TAPR_R = 0;          /* 5) bus clock resolution                                      */
  TIMER3_ICR_R = TIMER2_ICR_R = TIMER1_ICR_R = 0x00000001;    /* 6) clear TIMER1A timeout flag                                */
  TIMER3_IMR_R = TIMER2_IMR_R = TIMER1_IMR_R = 0x00000001;    /* 7) arm timeout interrupt                                    */

/* Timer 1-3 Priorities
   Less important, so PL 3 */
   
/* Timer1 */
NVIC_PRI5_R = (NVIC_PRI5_R&0xFFFF00FF)|0x00006000; 
  NVIC_EN0_R |= 1<<21;           /* 9) enable IRQ 19 in NVIC */
  
/* Timer2 */
NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x60000000; 
  NVIC_EN0_R |= 1<<23;           /* 9) enable IRQ 19 in NVIC */
  
/* Timer3 */
NVIC_PRI8_R = (NVIC_PRI8_R&0x00FFFFFF)|0x60000000; 
  NVIC_EN1_R |= 1<<3;           /* 9) enable IRQ 19 in NVIC */

TIMER0_CTL_R = TIMER3_CTL_R = TIMER3_CTL_R = TIMER2_CTL_R = TIMER1_CTL_R = 0x00000001;    /* 10) Turn all their intterupts on. Here we go (Yikes!! *fingers crossed*) */

  song_flag = 1; /* Semaphore for main */
  
  EnableInterrupts();
  
}  
 

/* **************Timer_Play********************* */
/* Start sound output
   Input: interrupt period
     Period = 2500000/Frequency
      Maximum C6, 20000
      Minimum NULL,   1
      Disable Sound,  0
   Output: none                                  */        
void High_Play(uint32_t period){
  if ((period > 0) && (period < 20000))
    TIMER1_TAILR_R = period - 1; /* set melody note */
  else
    TIMER1_TAILR_R = 0; /* Sound is OFF */
}

void Middle_Play(uint32_t period){
  if ((period > 0) && (period < 20000))
    TIMER2_TAILR_R = period - 1; /* set harmony note */
  else
    TIMER2_TAILR_R = 0; /* Sound is OFF */
}

void Low_Play(uint32_t period){
  if ((period > 0) && (period < 20000))
    TIMER3_TAILR_R = period - 1; /* set bass note */
  else
    TIMER3_TAILR_R = 0; /* Sound is OFF */
}


  
/* ***************Timer_Handler**************
   Parses Data Structure
   Acknowledges device trigger              */
void Timer0A_Handler(void){
  
  static unsigned int j = 0; /* index   */
  static unsigned int p = 0; /* intro index. (loops just once)  */
  
  
/* Only use the if else on songs with an intro  
   ------------------------------------------ */
  if(p < 32){
    High_Play(CeruleanCityIntro_high[p]); 
    Middle_Play(CeruleanCityIntro_middle[p]); 
    Low_Play(CeruleanCityIntro_low[p]); 
    p++;
  }
 /* --------------------------------------- */
  else{                                      
    High_Play(CeruleanCityIntro_high[j]); 
    Middle_Play(CeruleanCityIntro_middle[j]); 
    Low_Play(CeruleanCityIntro_low[j]); 

    /* 0x7f for song size 128 */   
    /* 0xff for song size 256 */
    j = 0x7F&(j+1); 
  
  }    
    
  amp = 8; /* Stabilize Amplitude (prevents DAC saturation)   */
  TIMER0_ICR_R = TIMER_ICR_TATOCINT; /* Acknowledge device trigger */
  
}


/* ISR Plays the melody note */
void Timer1A_Handler(void){

  static unsigned int x = 0; /* index */
    
  amp += delta[x];/* Calculus */
  
  DAC_Out(amp); /* Output to DAC */
  x = 0x1F&(x+1);
  TIMER1_ICR_R = TIMER_ICR_TATOCINT; /* Acknowledge device trigger */
 }

/* ISR Plays the harmony note */
void Timer2A_Handler(void){

  static unsigned int y = 0; /* index */
    
  amp += delta[y];/* Calculus  */
  
  DAC_Out(amp); /* Output to DAC */
  y = 0x1F&(y+1);
  TIMER2_ICR_R = TIMER_ICR_TATOCINT; /* Acknowledge device trigger */
 }

/* ISR Plays the bass note */
void Timer3A_Handler(void){
  
  static unsigned int z = 0; /* index */
    
  amp += delta[z];/* Calculus  */
  
  DAC_Out(amp); /* Output to DAC */
  z = 0x1F&(z+1);
  TIMER3_ICR_R = TIMER_ICR_TATOCINT; /* Acknowledge device trigger */
 }


/**********Song_Input*********/
/* Choose Song to Play       */
uint32_t Song_Input(void){  
  return (GPIO_PORTF_DATA_R&0x01);
}

/* Stop Button (||) */
void Stop(void){
    TIMER0_IMR_R = TIMER1_IMR_R = TIMER2_IMR_R = TIMER3_IMR_R = 0; 
        Sound_Play(0);
    song_flag = 0;
}

/* Play Button (->) */ 
void Song(void){
      TIMER0_IMR_R = TIMER1_IMR_R = TIMER2_IMR_R = TIMER3_IMR_R = 1; 
  song_flag = 1;
}
