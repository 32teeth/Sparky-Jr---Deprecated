/*
  SparkyClass.cpp
*/

/*
  include declaration
*/
#include "EEPROM.h"
#include "SparkyClass.h"


/*
==========================================================
  config
==========================================================
*/

/*
  baud rate
*/
const int baudrate = 57600;

/*
  MESSAGE
*/
String MESSAGE = "";

/*
  @common_pins assigned from #define board index in boards array above
  @rgb_pins assigned from #define board index in boards array above
  @input_pins assigned from #define board index in boards array above
  uncomment your version
  recomment all others
*/

#define SparkyJrUSB
//#define SparkyJrFTDI
//#define SparkyJrShield

/*
  @size = #buttons and #common
  @scope = #colors (ie RGB = 3)
  @row = #buttons in a row
*/
const int inputs = 8;
const int outputs = 8;
const int colors = 3; 

/*
  pattern 
  @patternLength 
  @defaultPattern
  @sparkyPattern
*/
const int patternLength = 18;
long sparkyPattern[18];

long rgbColorArray[8][3];
int power[3] = {75, 50, 25};

/*
  
*/
long sparkyCurrentColor[8] = {0,0,0,0,0,0,0,0};
long sparkyDestinationColor[8] = {0,0,0,0,0,0,0,0};
boolean effects[] = {true};

/*
 include files
*/
#include "SparkyConfig.h"
#include "SparkyBoards.h" 
#include "SparkyUtilities.h"
#include "SparkyEvents.h"
#include "SparkyEffects.h"
#include "SparkyColorControl.h"

/*
==========================================================
==========================================================
  <<constructor>>
==========================================================
==========================================================
*/
SparkyClass::SparkyClass()
{

  /*
    io
  */
  this->io(); 
 
  /*
    set pattern
  */ 
  this->pattern();
}

/*
==========================================================
  class methods
==========================================================
*/

/*
  @io
  set properties for pins
  input_pins default to HIGH (these are pulldown activated
  output_pins (common anode lines to RGB LEDs
  rgb_pins (red, green, blue cathode lines)
*/
void SparkyClass::io()
{
  // Initialize

  for(int n = 0; n < inputs; n++)
  {
    /*RGB pins*/
    if(n < 3){pinMode(colorPins[n], OUTPUT);}
    
    /*input and common pins*/
    pinMode(buttonPins[n], INPUT); 
    pinMode(commonPins[n], OUTPUT);
    
    /*turn off all common*/
    digitalWrite(buttonPins[n], HIGH);    
    digitalWrite(commonPins[n], LOW);
    
  }  
}

/*
  @program
  take pattern defined in SparkyConfig.h 
  convert to long
  store in user_pattern
*/
void SparkyClass::pattern()
{ 
  MESSAGE = "";
  MESSAGE += "pattern()\n";
  MESSAGE += "-------------------------------------\n";

  /*
    read defaultPattern 
    convert hex into long
    store long to sparkyPattern
  */
  for(int n = 0; n < patternLength; n++)
  {
    char* color = defaultPattern[n];
    sparkyPattern[n] = strtol(color, NULL, 16);
  }
  
  for(int n = 0; n < outputs; n++)
  {
    sparkyDestinationColor[n] = sparkyPattern[n];
  }
  
  this->set();
  
  /*
  for(int n = 0; n < 18; n++)
  {     
    // set original pattern from SparkyConfig.h
    char* color = pattern[n];
    user_pattern[n] = strtol(color, NULL, 16);    
    
    long stored = this->getEEPROM(n);
    
    MESSAGE += n;
    MESSAGE += ":";
    MESSAGE += stored;
    MESSAGE += " user_pattern:";
    MESSAGE += user_pattern[n];
    
    if(stored != -1)
    {
      char buffer[12];
      ltoa(stored, buffer, 16);
      color = buffer;
      //user_pattern[n] = strtol(color, NULL, 16);      
      
      MESSAGE += " overwrite:";
      MESSAGE += user_pattern[n];      
    }
    
    MESSAGE += "\n";
  }
  */
  /*
  // only used during debug mode
  Serial.begin(baudrate);
  Serial.print(MESSAGE);
  */
}


/*
==========================================================
==========================================================
  <<deconstructor>>
==========================================================
==========================================================
*/
SparkyClass::~SparkyClass(){/* Nothing */}
