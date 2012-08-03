/*
 ------------------------------------------------------------------------
 welcome  to Sparky - Plug n Play
 ------------------------------------------------------------------------
*/




/*
  #include files
*/
#include "EEPROM.h"
#include "SparkyClass.h"


/*
  instantiate Sparky
*/
SparkyClass *Sparky = new SparkyClass(); 
void setup()
{
  /*
        Pins 9 and 10: controlled by timer 1
    
        Setting 	Divisor 	Frequency
        0x01 	 	1 	 	31250
        0x02 	 	8 	 	3906.25
        0x03  		64 	 	488.28125
        0x04  		256 	 	122.0703125
        0x05 	 	1024 	 	30.517578125
  */
  TCCR1B = TCCR1B & 0b11111000 | 0x01; 
  /*
        Pins 11 and 3: controlled by timer 2
    
        Setting 	Divisor 	Frequency
        0x01 	 	1  		31250
        0x02 	 	8 	 	3906.25
        0x03  		32  		976.5625
        0x04 	 	64 	 	488.28125
        0x05 	 	128  		244.140625
        0x06  		256  		122.0703125
        0x07 	 	1024  		30.517578125
  */
  TCCR2B = TCCR2B & 0b11111000 | 0x01;  
  
  
  Sparky->intro(); 
}

void loop()
{
  Sparky->poll();
}


