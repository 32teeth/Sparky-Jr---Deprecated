/*
DEFAULT COLOR MAP REFERENCE - DON'T EDIT
--------------------------------------------
*/
char none[] = "000000";
char red[] = "FF0000";
char green[] = "00FF00";
char blue[] = "0000FF";
char purple[] = "FF00FF";
char cyan[] = "00FFFF";
char yellow[] = "FFFF00";
char orange[] = "CC3300";
char pink[] = "FF0066";
char white[] = "FFFFFF";
char grey[] = "CCCCCC";
char dkgrey[] = "666666";

/*
==============================================
  USER EDITABLE AREA BELOW
==============================================
*/

/*
DEFINE YOUR PATTERN
See the color map above
Use the english word for your color selection
--------------------------------------------
available default colors 
(Sparky Jr and Sparky Jr PWM)
============================================
red, green, blue, purple, cyan, yellow, white
--------------------------------------------

********************************************
Sparky Jr PWM users can add custom colors using their hex values
example: "FFCC33" for orange
to obtain hex values for colors, you can use something like photoshop
open the color pallette tool and provide the equivelant hex number
********************************************

*/

char* defaultPattern[18] = {
  red, // P1
  orange, // P2
  yellow, // P3
  green, // P4
  purple, // K1
  pink, // K2
  cyan, // K3
  blue, // K4
  white, // 2x P
  white, // 3x P
  white, // 4x P
  white, // 2x K
  white, // 3x K
  white, // 4x K  
  white,// P1 + K1 (throw SFIV & SSFIV)
  white,// P2 + K2 (focus SFIV & SSFIV)
  white,// P3 + K3 (taunt SFIV & SSFIV)
  white // P4 + K4 
};

