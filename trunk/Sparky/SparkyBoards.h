
/*
  @commonPins assigned from #define board index in boards array above
  @colorPins assigned from #define board index in boards array above
  @buttonPins assigned from #define board index in boards array above
*/

//  Sparky Jr USB
//----------------------------------------------------
#ifdef SparkyJrUSB
  int commonPins[outputs] = {23,22,21,20,19,18,13,5};
  int colorPins[colors] = {9,11,10};
  int buttonPins[inputs] = {3,2,0,1,4,12,6,8};
  int configLED = 7;
#endif
//----------------------------------------------------
//
 
//----------------------------------------------------

//  Sparky FTDI
//----------------------------------------------------
#ifdef SparkyJrFTDI
  int commonPins[outputs] = {18,17,16,15,14,13,12,8};
  int colorPins[colors] = {9,10,11};
  int buttonPins[inputs] = {0,1,2,3,4,5,6,7};
  int configLED = 19;  
#endif
//----------------------------------------------------


//  Sparky Shield
//----------------------------------------------------
/*
// ATMEL ATMEGA8 & 168 / ARDUINO
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5 / D19)
//      (D 0) PD0  2|    |27  PC4 (AI 4 / D18)
//      (D 1) PD1  3|    |26  PC3 (AI 3 / D17)
//      (D 2) PD2  4|    |25  PC2 (AI 2 / D16)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1 / D15)
//      (D 4) PD4  6|    |23  PC0 (AI 0 / D14)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM
//      (D 8) PB0 14|    |15  PB1 (D 9) PWM
//                  +----+
*/
#ifdef SparkyJrShield
  int commonPins[outputs] = {18,17,16,15,14,13,12,8};
  /*
        
  */
  int colorPins[colors] = {9,10,11};
  int buttonPins[inputs] = {0,1,2,3,4,5,6,7};
  int configLED = 19;
#endif
//----------------------------------------------------  
