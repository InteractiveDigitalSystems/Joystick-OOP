#include <Arduino.h>
#include <Joystick.h>

Joystick joystick = Joystick(36, 39, 15); // Instantiate object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

// void printJoystickState(Joystick *joystick) {
//   // put your main code here, to run repeatedly:
//   Serial.print("Button state: ");
//   Serial.print(joystick->isButtonPressed());
//   if (joystick->isInDeadzone() == false) {
//     Serial.print(" , X ");
//     Serial.print(joystick->getJoystickValues().first);
//     Serial.print(" , y ");
//     Serial.print(joystick->getJoystickValues().second);
//   }
//   Serial.println();
// }

void loop() { 
  // printJoystickState(&joystick);

    // put your main code here, to run repeatedly:
    Serial.print("Button state: ");
    Serial.print(joystick.isButtonPressed());
    if (joystick.isInDeadzone() == false) {
      Serial.print(" , X ");
      Serial.print(joystick.getJoystickValues().first);
      Serial.print(" , y ");
      Serial.print(joystick.getJoystickValues().second);
    }
    Serial.println();
  }