#include <Arduino.h>
#include <Joystick.h>

Joystick joystick = Joystick(39,36,15); // Instantiate object


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(joystick.isInDeadzone());
  Serial.println(joystick.isButtonPressed());
}