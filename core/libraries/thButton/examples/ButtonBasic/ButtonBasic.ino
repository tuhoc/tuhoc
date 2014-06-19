/*
  TUHOC - thButton - Basic Example

  This example code is in the public domain.
*/


#include <thButton.h>


// Connections ==========================================

int buttonPin = 9;           // Button connected to pin 9

//=======================================================


thButton button(buttonPin);


void setup()
{
  Serial.begin(9600);
  Serial.println("\n***  TUHOC - thButton - Basic Example  ***");
}


void loop()
{
  delay(25);

  if (button.onPress())
  {
    Serial.println();
    Serial.println("button.onPress  event");
  }

  if (button.isPress())
  {
    Serial.println("   button.isPress  state");
  }

  if (button.onRelease())
  {
    Serial.println("button.onRelease  event");
  }

  if (button.isRelease())
  {
  }
}
