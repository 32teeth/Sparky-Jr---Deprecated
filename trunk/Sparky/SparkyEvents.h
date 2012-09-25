/*
  button 
  @punch @kick = #buttons in row in active state
  @punches @kicks = buttons states for associated row
  @cross = boolean if same button cross rows is active state
*/
int punch = -1, kick = -1;
int punches[4] = {0,0,0,0};
int kicks[4] = {0,0,0,0};
boolean cross = false;

/*
  @buttonIndex
  @buttonValues = corresponding value to each button 1 - 8, these are used in comparing current down states
  @buttonValues map
  /     \ /     \ /     \ /     \
  |  1  | |  2  | |  4  | |  8  |
  \     / \     / \     / \     /
  
  /     \ /     \ /     \ /     \
  |  16 | |  32 | |  64 | | 128 |
  \     / \     / \     / \     /   
  @buttonState = value from values added together for current press state comparison  
  @buttonCurrent = used in poll to create a value of states  
  @invert = 255 
*/
int buttonIndex;
int buttonValues[8] = {1,2,4,8,16,32,64,128};
int buttonState = 0;
int buttonCurrent = 0;
int buttonPressed[8] = {0,0,0,0,0,0,0,0};
int buttonReleased[8] = {0,0,0,0,0,0,0,0};

boolean hold = false;

/*
  @intro
  simple hello
*/
void SparkyClass::intro()
{
  for(int n = 0; n < outputs; n++)
  {
    for(int c = 0; c < 3; c++){analogWrite(colorPins[c], rgbColorArray[n][c]);}    
    if(buttonPressed[n] == 0)
    {
      digitalWrite(commonPins[n], HIGH);
      delay(250);
      digitalWrite(commonPins[n], LOW);
    }
  } 
}

/*
  @poll
  this method listens to the buttonPins and tests for LOW or HIGH
  sets buttonCurrent based on buttonValues (see above)
  compares to buttonState
  executes if different
*/
void SparkyClass::poll()
{
  /*
  // reset watchers
  punch = kick = -1;
  cross = false; 
  buttonCurrent = 0;
  for(int n = 0; n < 8; n++)
  {
    if(!hold){buttonReleased[n] = buttonPressed[n];}
    buttonPressed[n] = 0;
  }
  */

  /*
    read inputs to determine button state (HIGH|LOW);
  */
  for(int n = 0; n < inputs; n++)
  {
    buttonPressed[n] =  digitalRead(buttonPins[n]);
  }
  
  /*
    draw
  */
  this->draw();
}
