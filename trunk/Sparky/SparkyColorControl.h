void SparkyClass::set()
{
  
  for(int n = 0; n < outputs; n++)
  {
    int* rgb = this->RGB(sparkyDestinationColor[n]);
    int red = rgb[0];
    int blue = rgb[1];
    int green = rgb[2];
    
    rgbColorArray[n][0] = 255 - red;
    rgbColorArray[n][1] = 255 - green;
    rgbColorArray[n][2] = 255 - blue;
  }   
}

/*

*/
void SparkyClass::draw()
{

  for(int n = 0; n < outputs; n++)
  {
    for(int c = 0; c < 3; c++){analogWrite(colorPins[c], rgbColorArray[n][c]);}    
    if(buttonPressed[n] == 0)
    {
      digitalWrite(commonPins[n], HIGH);
      delayMicroseconds(500);
      digitalWrite(commonPins[n], LOW);
      
      //this->burst(n);
    }
  } 
}

/*
  
*/
void SparkyClass::shift(long number)
{
  // rgb
  /*
  int* rgb = this->RGB(number);
  int red = rgb[0];
  int blue = rgb[1];
  int green = rgb[2];
  */
}
