/*
==========================================================
  Utility methods
==========================================================
*/

/*
  @RGB
  requires long from hex strtol(hex, NULL, 16);
*/
int* SparkyClass::RGB(long number)
{
  int red = (number>>16);
  int green = ((number>>8) & 0xff);
  int blue = (number & 0xff);
  int rgb[] = {red, green, blue};
  return rgb;
}
