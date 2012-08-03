/*
  SparkyClass.h
*/
#ifndef SparkyClass_h
#define SparkyClass_h

#include "arduino.h"

class SparkyClass
{
  public:
    /*
      <<constructor>>
      <<deconstructor>>      
    */
    SparkyClass();
    ~SparkyClass();
    
    /*
      events
    */
    void intro();
    void poll();    

    
    /*
      effects
    */
    void burst(int number);
    void marquee(int number);  
    
  private:
    /*
      methods
    */
    void io();
    void pattern();

    /*
      color controller
    */
    void set();    
    void draw();
    void shift(long number);    
    
    /*
      utilities
    */
    int* RGB(long number);      
};

#endif
