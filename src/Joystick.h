#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"

class Joystick {
public:
  Joystick(int xPin, int yPin, int buttonPin) {
    // Assign values for potentiometers
    this->xPin = xPin;
    this->yPin = yPin;
    detectCenterPosition();

    // Setup button
    this->buttonPin = buttonPin;
    pinMode(this->buttonPin, INPUT_PULLUP);
  };

  void setName(String s) { this->name = s; }

  std::pair<int, int> getJoystickValues() {
    int xVal = analogRead(this->xPin);
    int yVal = analogRead(this->yPin);
    return std::make_pair(xVal, yVal);
  }

  bool isInDeadzone() {
    int offset = 60;
    auto joystick = getJoystickValues();

    return std::abs(joystick.first - joyXCenterVal) < offset &&
           std::abs(joystick.second - joyYCenterVal) < offset;
  }

  bool isButtonPressed() { return digitalRead(buttonPin) == 0; }

  String getJoystickStatus(){
    String s;
    auto joystick = getJoystickValues();

    s += "X: " + joystick.first;
    s += ", Y: " + joystick.second;
    if(isButtonPressed()){
      s += " button pressed!";
    }
    return s;
  }

private:
  void detectCenterPosition() {
    auto joystick = getJoystickValues();
    joyXCenterVal = joystick.first;
    joyYCenterVal = joystick.second;
  };

  int xPin = 0;
  int yPin = 0;
  int buttonPin = 0;
  int joyXCenterVal = 0;
  int joyYCenterVal = 0;
  String name = "";
};

#endif