/*
 * Sample sketch which makes the Arduino to impersonate a Classic Controller.
 *
 * Use a PushButton connected to the digital pin 2 and GND. It will trigger
 * a D-Pad RIGHT button press of the impersonated Classic Controller.
 *
 * Copyright (c) 2011 Peter Brinkmann (peter.brinkmann@gmail.com)
 *
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 */

// This seems redundant, but we need to declare this
// dependency in the ino file or else it won't be included
// in the build.
#include <Wire.h> 
#include "wiimote.h"

// Classic Controller Buttons
int bdu = 0; // D-Pad Up state
int bdd = 0; // D-Pad Down state
int bdl = 0; // D-Pad Left state
int bdr = 0; // D-Pad Right state
int bm = 0; // MINUS button state
int bhome = 0; // HOME button state
int bp = 0; // PLUS button state
int by = 0; // Y button state
int bx = 0; // X button state
int bb = 0; // B button state
int ba = 0; // A button state
int bzl = 0; // ZL button state
int bl = 0; // L button state
int br = 0; // R button state
int bzr = 0; // ZR button state

/*
 * Analog Buttons.
 * They are initialized with center values from the calibration buffer.
 */
byte lx = calbuf[2]>>2;
byte ly = calbuf[5]>>2;
byte rx = calbuf[8]>>3;
byte ry = calbuf[11]>>3;


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

// d-pad buttons
int DPU = 4;//PD4
int DPD = 5;//PD5
int DPL = 6;//PD6
int DPR = 7;//PD7

// option buttons
int MINUS = 8;//PB0
int HOME = 9;//PB1
int PLUS = 10;//PB2

// face buttons
int Y = 0;//PD0
int X = 1;//PD1
int B = 2;//PD2
int A = 3;//PD3

// shoulder buttons
int ZL = 17;//PC3
int L = 16;//PC2
int R = 15;//PC1
int ZR = 14;//PC0

String names[15] =  {"DPU","DPD", "DPL", "DPR", "MINUS", "HOME", "PLUS", "Y", "X", "B", "A", "ZL", "L", "R", "ZR"};
int inputs[15]   =  {DPU ,DPD, DPL, DPR, MINUS, HOME, PLUS, Y, X, B, A, ZL, L, R, ZR};
int outputs[15]  =  {bdu, bdd, bdl, bdr,  bm,  bhome,  bp, by, bx,bb,ba,bzl,bl,br,bzr};




// Wiimote button data stream
byte *stream_callback(byte *buffer)
{
  //wiimote_write_buffer(buffer, bdl, bdr, bdu, bdd, ba, bb, bx, by, bl, br,bm, bp, bhome, lx, ly, rx, ry, bzl, bzr);
  wiimote_write_buffer(
    buffer, 
    outputs[2],//bdl, 
    outputs[3],//bdr, 
    outputs[0],//bdu, 
    outputs[1],//bdd, 
    outputs[10],//ba, 
    outputs[9],//bb, 
    outputs[8],//bx, 
    outputs[7],//by, 
    outputs[12],//bl, 
    outputs[13],//br,
    outputs[4],//bm, 
    outputs[6],//bp, 
    outputs[5],//bhome, 
    lx, 
    ly, 
    rx, 
    ry, 
    outputs[11],//bzl, 
    outputs[14]//bzr
  );
  return buffer;
}

void setup()
{
  // Set PushButton pins as input, turning pull-up on
  for(int n = 0; n < 15; n++)
  {
    pinMode(inputs[n], INPUT);
    digitalWrite(inputs[n], HIGH);    
  }

  // Prepare wiimote communications
  wiimote_stream = stream_callback;
  wiimote_init();
  
  Serial.begin(9600);
}

void loop() {
  /*
  * If PushButton is pressed, pinRight will be LOW.
  * This value is then inverted and given to variable "bdr", that represents
  * D-Pad RIGHT button.
  */
  for(int n = 0; n < 15; n++){outputs[n] = !digitalRead(inputs[n]);} 

  delay(50);
}
