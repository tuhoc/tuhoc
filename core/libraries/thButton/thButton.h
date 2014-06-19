/*

TUHOC - thButton library


History

version 1.0 - 140619
  Initial release - quang.dinh@dtt.vn


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


#ifndef THBUTTON_H
#define THBUTTON_H


#include <Arduino.h>


class thButton
{
  public:
    thButton(byte pin);
    
    boolean onPress();
    boolean isPress();
    boolean onRelease();
    boolean isRelease();
    
    boolean onHold();
    boolean isHold();
    static void setHoldTime(word holdTime_ms);
    
  private:
    byte _pin; 
    byte _flags;
    word _changeTime; 
    
    void update();
    boolean onEvent(byte event);
};

 
#endif
