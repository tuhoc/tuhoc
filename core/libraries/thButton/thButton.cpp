/*

TUHOC - thButton library

See thButton.h


This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/


#include "thButton.h"


#define DEBOUNCE_TIME   50            // wait 50ms after each pin changes


#define  IS_PRESS    _BV(0)
#define  WAS_PRESS   _BV(1)
#define  ON_PRESS    _BV(2)
#define  ON_RELEASE  _BV(3)
#define  IS_HOLD     _BV(4)
#define  ON_HOLD     _BV(5)


word holdTime = 500;                  // default Hold time = 500 ms


thButton::thButton(byte pin)
{
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);  
  //_flags = 0;                       // led Arduino initialize _flags to 0 
}


void thButton::update()
{
  word interval = millis() - _changeTime;
  
  // Read pin state to IS_PRESS
  if (interval > DEBOUNCE_TIME) 
  {
    if (digitalRead(_pin) == LOW)
    { 
      _flags |= IS_PRESS;
    } 
    else
    { 
      _flags &= ~IS_PRESS;
    }
  }

  // Detect changes
  switch (_flags & (WAS_PRESS | IS_PRESS))
  {
    case WAS_PRESS:                   // onRelease event
      _flags = ON_RELEASE; 
      _changeTime = millis();
      break;

    case IS_PRESS:                    // onPress event
      _flags = WAS_PRESS | IS_PRESS | ON_PRESS;
      _changeTime = millis();
      interval = 0;
      break;
  }

  // Checking Hold state
  if ((_flags & IS_PRESS)             // isPress state
   && (!(_flags & IS_HOLD))           // IS_HOLD not set
   && (interval >= holdTime))         // long Press interval
  {                                   
    _flags |= IS_HOLD | ON_HOLD;      // set Hold flags
  }
}


boolean thButton::isPress()
{
  update();
  return (_flags & IS_PRESS); 
}


boolean thButton::isHold()
{  
  update();
  return (_flags & IS_HOLD); 
}
 

boolean thButton::onEvent(byte event)
{
  update();
  boolean result = _flags & event;
  _flags &= ~event;                    // Reset event flag after checking
  return result;
}


boolean thButton::onPress()
{
  return onEvent(ON_PRESS);
}


boolean thButton::onHold()
{  
  return onEvent(ON_HOLD);
}


boolean thButton::onRelease()
{
  return onEvent(ON_RELEASE);
}


boolean thButton::isRelease()
{
  update();
  return !(_flags & IS_PRESS);
} 


void thButton::setHoldTime(word holdTime_ms)
{
  holdTime = holdTime_ms;
}
