/* Frequencies jacked from Valvano and co.
   All songs are orignally coded by Ronny
   Music jacked from http://www.ninsheetmusic.org/  
   Notes are grouped by Respective Measures 
                                                */

/* Note Frequencies               */
#define C1   1194   /* 2093 Hz    */
#define B1   1265   /* 1975.5 Hz  */
#define BF1  1341   /* 1864.7 Hz  */
#define A1   1420   /* 1760 Hz    */
#define AF1  1505   /* 1661.2 Hz  */
#define G1   1594   /* 1568 Hz    */
#define GF1  1689   /* 1480 Hz    */
#define F1   1790   /* 1396.9 Hz  */
#define E1   1896   /* 1318.5 Hz  */
#define EF1  2009   /* 1244.5 Hz  */
#define D1   2128   /* 1174.7 Hz  */
#define DF1  2255   /* 1108.7 Hz  */
#define C    2389   /* 1046.5 Hz  */
#define B    2531   /* 987.8 Hz   */
#define BF   2681   /* 932.3 Hz   */
#define A    2841   /* 880 Hz     */
#define AF   3010   /* 830.6 Hz   */
#define G    3189   /* 784 Hz     */
#define GF  3378    /* 740 Hz     */
#define F   3579   /* 698.5 Hz    */
#define E   3792   /* 659.3 Hz    */
#define EF  4018   /* 622.3 Hz    */
#define D   4257   /* 587.3 Hz    */
#define DF  4510   /* 554.4 Hz    */
#define C0  4778   /* 523.3 Hz    */
#define B0  5062   /* 493.9 Hz    */
#define BF0 5363   /* 466.2 Hz    */
#define A0  5682   /* 440 Hz      */
#define AF0 6020   /* 415.3 Hz    */
#define G0  6378   /* 392 Hz      */
#define GF0 6757   /* 370 Hz      */
#define F0  7159   /* 349.2 Hz    */
#define E0  7584   /* 329.6 Hz    */
#define EF0 8035   /* 311.1 Hz    */
#define D0  8513   /* 293.7 Hz    */
#define DF0 9019   /* 277.2 Hz    */
#define C7  9556   /* 261.6 Hz    */
#define B7  10200   /* 246.9 Hz   */     /*(Sounds a little sharp)  */
#define BF7 10726   /* 233.1 Hz   */     /*(BE CAREFUL WITH THESE 2 */
#define A7  11364   /* 220 Hz     */
#define AF7 12039   /* 207.7 Hz   */
#define G7  12755   /* 196 Hz     */
#define GF7 13514   /* 185 Hz     */
#define F7  14317   /* 174.6 Hz   */
#define E7  15169   /* 164.8 Hz   */
#define EF7 16071   /* 155.6 Hz   */
#define D7  17026   /* 146.8 Hz   */
#define DF7 18039   /* 138.6 Hz   */
#define C6  19111   /* 130.8 Hz   */

/* LEGEND OF ZELDA TITLE THEME
   Sounds best at 144bpm eigth 120or144bpm 16th */

/* melody */ 
const unsigned long int Zelda_high[128] = {      
  
  A,D,BF0,G0,
  G,D,BF0,G0,
  GF,D,BF0,G0,
  G,D,BF0,G0,
    
  G,C0,A0,F0,
  F,C0,A0,F0,
  E,C0,A0,F0,
  F,C0,A0,F0,
  
  F,BF0,G0,E0,
  E,BF0,G0,E0,
  EF,BF0,G0,E0,
  E,BF0,G0,E0,

  E,A0,F0,D0,
  D,A0,F0,D0,
  DF,A0,F0,D0,
  D,A0,F0,D0,

  A,D,BF0,G0,
  G,D,BF0,G0,
  GF,D,BF0,G0,
  G,D,BF0,G0,
  
  BF,EF,C0,A0,
  A,EF,C0,A0,
  AF,EF,C0,A0,
  A,EF,C0,A0,

  C,D,BF0,G0,
  BF,D,BF0,G0,
  A,D,BF0,G0,
  BF,D,BF0,G0,
  
  A,BF0,G0,E0,
  G,BF0,G0,E0,
  F,BF0,G0,E0,
  E,BF0,G0,E0
  
};  

/* bass */
const unsigned long int Zelda_low[128] = {      
  
  BF7,BF7,D0,A0,
  A0,A0,A0,A0,
  A0,D0,A0,G0,
  C0,A0,G0,D0,
    
  A7,A7,C7,G0,
  G0,G0,G0,G0,
  G0,A7,G0,F0,
  C0,A0,G0,C7,
  
  G7,G7,C7,F0,
  F0,F0,F0,F0,
  F0,G7,F0,E0,
  G0,E0,C7,C7,

  F7,F7,A7,E0,
  E0,E0,E0,E0,
  F7,C7,E0,D0,
  G0,F0,C7,BF7,

  BF7,BF7,D0,A0,
  A0,A0,A0,A0,
  BF7,D0,A0,G0,
  D,A0,G0,D0,
  
  A7,A7,C7,C0,
  C0,C0,C0,C0,
  D0,D0,C0,A0,
  EF,D,C0,A0,

  G7,BF7,D0,BF0,
  BF0,BF0,BF0,BF0,
  G0,D0,BF0,A0,
  C0,BF0,G0,D0,
  
  C7,C7,G0,BF0,
  BF0,BF0,BF0,BF0,
  C7,C7,BF0,G0,
  E,D,G,E
  
};  


/* Pokemon Center
   Sounds best with 120bm eighth notes*/

/* melody */
const unsigned long int PokemonCenter_high[128] = {      
  
  D,A0,D,A,
  A,G,G,GF,
  E,DF,0,0,
  A0,A0,G0,A0,
    
  DF,A0,DF,GF,
  GF,E,E,DF,
  D,GF,0,0,
  D,DF,B0,A0,
  
  D,A0,D,A,
  A,G,G,GF,
  E,DF,0,0,
  A0,A0,G0,A0,
    
  DF,A0,DF,GF,
  GF,E,E,DF,
  D,D,D,0,
  GF0,G0,A0,B0,

  GF,GF,GF,GF,
  A,A,0,0,
  G,A,G,GF,
  E,E,0,0,
  
  DF,DF,DF,0,
  E,E,0,0,
  GF,G,GF,E,
  D,D,D,0,

  GF,GF,GF,0,
  A,A,0,0,
  G,GF,G,A,
  B,B,0,0,
  
  
  A,A,G,GF,
  G,G,0,0,
  GF,G,GF,E,
  D,D,0,0
  
};  

/* Harmony */
const unsigned long int PokemonCenter_middle[128] = {      
  
  GF0,F0,GF0,D,
  D,DF,B0,A0,
  B0,A0,G0,GF0,
  E0,GF0,E0,0,
    
  A0,E0,A0,DF,
  DF,B0,A0,G0,
  GF0,A0,B0,DF,
  A0,0,E0,0,
  
  GF0,F0,GF0,D,
  D,DF,B0,A0,
  B0,A0,G0,GF0,
  E0,GF0,E0,0,
    
  A0,E0,A0,DF,
  DF,B0,A0,G0,
  GF0,E0,D0,E0,
  D0,0,E0,0,

  GF0,E0,D0,0,
  E0,GF0,G0,A0,
  B0,A0,G0,0,
  E0,GF0,G0,A0,
  
  G0,GF0,E0,0,
  DF0,D0,E0,G0,
  GF0,G0,A0,B0,
  A0,A0,A0,0,

  D,DF,B0,0,
  A0,B0,DF,D,
  E,D,DF,0,
  B0,DF,D,E,
  
  
  DF,B0,A0,0,
  G0,A0,B0,G0,
  A0,G0,GF0,E0,
  D0,E0,GF0,G0
  
};  

/* Bass */ 
const unsigned long int PokemonCenter_low[128] = {      
  
  D7,GF7,D7,GF7,
  D7,GF7,G7,GF7,
  E7,A7,E7,A7,
  E7,A7,E7,A7,
    
  E7,A7,E7,A7,
  E7,A7,G7,A7,
  GF7,A7,GF7,A7,
  GF7,A7,G7,A7,
  
  D7,GF7,D7,GF7,
  D7,GF7,G7,GF7,
  E7,A7,E7,A7,
  E7,A7,E7,A7,
    
  E7,A7,E7,A7,
  E7,A7,G7,A7,
  D7,GF7,D7,GF7,
  D7,A7,G7,GF7,

  GF7,A7,GF7,A7,
  GF7,A7,GF7,A7,
  G7,B7,G7,B7,
  G7,B7,G7,B7,
  
  E7,G7,E7,G7,
  E7,G7,E7,G7,
  GF7,A7,GF7,A7,
  GF7,A7,GF7,A7,

  GF7,A7,GF7,A7,
  GF7,A7,GF7,A7,
  G7,B7,G7,B7,
  G7,B7,G7,B7,
  
  E7,G7,E7,G7,
  E7,G7,E7,G7,
  GF7,A7,GF7,A7,
  GF7,A7,GF7,A7,
  
};  



/* Cerulean City Theme
   2 BARS OF INTRO, ENABLE INTRO CODE
   Sounds best with 120bpm 16th notes  */

const unsigned long int CeruleanCityIntro_high[32] = {      
  
  E,0,EF,0,
  DF,0,B0,0,
  A0,0,B0,0,
  DF,0,EF,0,
  
  E,E,0,0,
  0,0,E,B0,
  DF,DF,EF,EF,
  E,GF,AF,A
  
};

const unsigned long int CeruleanCityIntro_middle[32] = {      
  
  0,0,0,0,
  0,0,0,0,
  E0,0,EF0,0,
  DF0,0,C7,0,
  
  B7,B7,0,0,
  0,0,0,0,
  0,0,0,0,
  0,0,0,0
    
};

const unsigned long int CeruleanCityIntro_low[32] = {      
  
  0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  
  E7,E7,AF7,AF7,
  E7,E7,AF7,AF7,
  E7,E7,AF7,AF7,
  E7,E7,AF7,AF7
  
};
  

/* The MEAT of the song  */
/* melody */
const unsigned long int CeruleanCity_high[256] = {      
  
  AF,AF,AF,AF,
  AF,AF,A,AF,
  GF,GF,GF,GF,
  GF,GF,0,0,
    
  0,0,0,0,
  0,0,E,B0,
  DF,DF,EF,EF,
  E,GF,AF,A,
  
  AF,AF,AF,AF,
  AF,AF,E,AF,
  B,B,B,B,
  B,B,0,0,
    
  0,0,0,0,
  0,0,E,B0,
  DF,DF,EF,EF,
  E,GF,AF,A,

  AF,AF,AF,AF,
  AF,AF,A,AF,
  GF,GF,GF,GF,
  GF,GF,0,0,
  
  AF0,0,AF0,0,
  AF0,0,E,B0,
  DF,DF,EF,EF,
  E,GF,AF,A,

  AF,AF,AF,AF,
  AF,AF,E,AF,
  B,B,B,B,
  B,B,0,0,
  
  /*half*/
  
  DF,B0,DF,EF,
  E,E,0,0,
  AF,AF,0,0,
  E,E,0,0,  
  
  
  
  EF,DF,EF,E,
  GF,GF,0,0,
  B,B,0,0,
  GF,GF,0,0,
    
  DF,B0,DF,EF,
  E,0,E,EF,
  E,GF,AF,0,
  AF,A,AF,A,
  
  B,GF,EF,DF,
  B0,DF,EF,GF,
  B,B,B,B,/* END ON EITGH OR QUARTER? */
  0,0,0,0,
    
  E0,E0,E0,E0,
  E0,E0,E0,0,
  B7,B7,B7,0,
  GF0,GF0,GF0,0,

  AF0,AF0,AF0,0,
  A0,A0,A0,0,
  B0,B0,B0,B0,
  B0,B0,B0,0,
  
  B0,B0,B0,B0,
  B0,B0,B0,0,
  AF0,AF0,AF0,0,
  EF,EF,EF,0,

  DF,DF,DF,0,
  EF,EF,EF,0,
  E,0,EF,0,
  DF,0,EF,0,
  
  E,0,0,0,
  0,0,E,B0,
  DF,DF,EF,EF,
  E,GF,AF,A,
  
};
  
  
/* harmony */
const unsigned long int CeruleanCity_middle[256] = {      
  
  B0,B0,B0,B0,
  DF,DF,EF,D,
  DF,DF,0,0,
  B0,B0,0,0,
    
  AF0,AF0,AF0,AF0,
  AF0,AF0,AF0,0,
  E,E,E,E,
  E,E,E,0,
  
  A0,A0,A0,0,
  AF0,0,GF0,0,
  AF0,0,A0,0,
  B0,0,DF,0,
    
  0,0,0,0,
  0,0,E,B0,
  DF,DF,EF,EF,
  E,GF,AF,A,

  DF,DF,DF,0,
  B0,B0,DF,EF,
  DF,DF,DF,0,
  B,B,B,0,
  
  0,E0,0,E0,
  0,0,0,0,
  AF0,AF0,AF0,AF0,
  AF0,AF0,AF0,0,

  B0,B0,B0,0,
  A0,0,AF0,0,
  GF0,0,AF0,0,
  A0,0,B0,0,
  
  /*half*/
  
  E0,0,GF0,0,
  AF0,0,0,0,
  E,E,0,0,
  B0,B0,0,0,  
  
  GF0,0,AF0,0,
  A0,0,0,0,
  GF,GF,0,0,
  EF,EF,0,0,  
  
  E0,0,0,0,
  0,0,GF0,0,
  0,0,0,0,
  A0,0,0,0,
  
  B0,0,0,0,
  0,0,0,0,
  0,0,0,0,/* END ON EITGH OR QUARTER? */
  0,0,0,0,
    
  0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  0,0,0,0,

  0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  
  E0,E0,E0,E0,
  E0,E0,E0,0,
  0,0,0,0,
  0,0,0,0,

  GF0,GF0,GF0,GF0,
  GF0,0,GF0,0,
  AF0,0,AF0,0,
  GF0,0,GF0,0,
  
  E0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  0,0,0,0,
  
};
  
  

/* bass */
const unsigned long int CeruleanCity_low[256] = {      
  
  GF7,0,A7,0,
  GF7,0,A7,0,
  B7,0,A7,0,
  AF7,0,GF7,0,
    
  E7,0,AF7,0,
  E7,0,AF7,0,
  E7,0,AF7,0,
  E7,0,AF7,0,
  
  GF7,0,A7,0,
  GF7,0,A7,0,
  B7,0,A7,0,
  AF7,0,GF7,0,
    
  E7,0,AF7,0,
  E7,0,AF7,0,
  E7,0,AF7,0,
  E7,0,AF7,0,
  
  GF7,0,A7,0,
  GF7,0,A7,0,
  B7,0,A7,0,
  AF7,0,GF7,0,
    
  E7,0,AF7,0,
  E7,0,AF7,0,
  E7,0,AF7,0,
  E7,0,AF7,0,
  
  GF7,0,A7,0,
  GF7,0,A7,0,
  B7,0,A7,0,
  AF7,0,GF7,0,
    
  /*half*/
  
  DF7,0,E7,0,
  DF7,0,0,0,
  AF7,0,0,0,
  E7,0,0,0,
    
  EF7,0,GF7,0,
  EF7,0,0,0,
  B7,0,0,0,
  GF7,0,0,0,
  
    
  DF7,0,0,0,
  0,0,E7,0,
  0,0,0,0,
  AF7,0,A7,0,
  
  B7,0,0,0,
  0,0,0,0,
  0,0,A7,0,
  AF7,0,GF7,0,
  
  E7,0,AF7,0,
  E7,0,AF7,0,
  E7,0,AF7,0,
  E7,0,AF7,0,
  
  GF7,0,A7,0,
  GF7,0,A7,0,
  B7,0,A7,0,
  AF7,0,GF7,0,

  AF7,0,B7,0,
  AF7,0,B7,0,
  AF7,0,B7,0,
  AF7,0,B7,0,
  
  GF7,0,A7,0,
  GF7,0,A7,0,
  B7,0,A7,0,
  AF7,0,GF7,0

};

