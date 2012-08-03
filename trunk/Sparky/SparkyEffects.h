/*
  burst
*/
/*
  0,1,2,3
  4,5,6,7
*/
int burstMap[8][3][3] = {
  {
    {1,4,-1},// 75%
    {2,5,-1},// 50%
    {3,6,-1}// 25%
  },
  {
    {0,2,5},// 75%
    {3,4,6},// 50%
    {7,-1,-1}// 25%
  },
  {
    {1,3,6},// 75%
    {0,5,7},// 50%
    {4,-1,-1}// 25%
  },
  {
    {2,7,-1},// 75%
    {1,6,-1},// 50%
    {0,5,-1}// 25%
  },
  {
    {0,5,-1},// 75%
    {1,6,-1},// 50%
    {2,7,-1}// 25%
  },
  {
    {1,4,6},// 75%
    {0,2,7},// 50%
    {3,-1,-1}// 25%
  },
  {
    {2,5,7},// 75%
    {1,3,4},// 50%
    {0,-1,-1}// 25%
  },
  {
    {3,6,-1},// 75%
    {2,5,-1},// 50%
    {1,4,-1}// 25%
  }  
};
void SparkyClass::burst(int n)
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      for(int c = 0; c < 3; c++){analogWrite(colorPins[c], rgbColorArray[n][c]);}
    
      if(burstMap[n][i][j] != -1)
      {
        int* rgb = this->RGB((long)(sparkyDestinationColor[n]));
        int red = 255-rgb[0];
        int blue = 255-rgb[1];
        int green = 255-rgb[2];
        // change color
        for(int c = 0; c < 3; c++)
        {
          int color = (int)
          (
            floor(
              (float)(
                (rgb[c]) // 255 * 0.75 = 191
              )
            )
          );
          analogWrite(colorPins[c], (int)((25*i)*i));
          
        }      
        digitalWrite(commonPins[burstMap[n][i][j]], HIGH);  
        delayMicroseconds(500);     
        digitalWrite(commonPins[burstMap[n][i][j]], LOW);
      }    

    }    
  }
}

/*
  marquee
*/
void SparkyClass::marquee(int number)
{
}
