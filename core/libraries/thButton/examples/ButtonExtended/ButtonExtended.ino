/*
  TUHOC - thButton - Extended Example

  This example code is in the public domain.
*/


#include <thButton.h>


// Connections ==========================================

int buttonA_Pin = 9;            // Button_A connected to pin 9
int buttonB_Pin = 8;            // Button_B connected to pin 8

//=======================================================


thButton buttonA(buttonA_Pin);
thButton buttonB(buttonB_Pin);


int buttonA_PressCount   = 0;
int buttonA_ReleaseCount = 0;
int buttonB_PressCount   = 0;
int buttonB_ReleaseCount = 0;


void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("***  TUHOC - thButton - Extended Example  ***");
  
  thButton::setHoldTime(500);
}


void loop()
{
  delay(25);


  // Button A ============================================
  
  if (buttonA.onPress())
  {
    buttonA_PressCount++;
    Serial.println();
    Serial.print("[Button A_]   onPress     #");
    Serial.println(buttonA_PressCount); 
  }

  if (buttonA.onRelease())
  {
    buttonA_ReleaseCount++;
    Serial.print("[Button A_]   onRelease   #");
    Serial.println(buttonA_ReleaseCount); 
  }
  
  if (buttonA.onHold())
  {
    Serial.println("[Button A_]   onHold");
  }
  
  if (buttonA.isPress())
  {
    Serial.print("[Button A_]     isPress");
    
    if (buttonA.isHold())
    {
      Serial.print("   isHold");
    }
    
    Serial.println();
  }

  if (buttonA.isRelease())
  {
  }
  
  // Button B ============================================
  
  if (buttonB.onPress())
  {
    buttonB_PressCount++;
    Serial.println();
    Serial.print("[Button _B]   onPress     #");
    Serial.println(buttonB_PressCount); 
  }

  if (buttonB.onRelease())
  {
    buttonB_ReleaseCount++;
    Serial.print("[Button _B]   onRelease   #");
    Serial.println(buttonB_ReleaseCount); 
  }
  
  if (buttonB.onHold())
  {
    Serial.println("[Button _B]   onHold");
  }
  
  if (buttonB.isPress())
  {
    Serial.print("[Button _B]     isPress");
    
    if (buttonB.isHold())
    {
      Serial.print("   isHold");
    }
    
    Serial.println();
  }
}
