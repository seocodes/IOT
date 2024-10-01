
#include <Ultrasonic.h>
Ultrasonic ultrasonic(12, 13);
const int pin_ledYellow = 2;
const int pin_ledBlue = 3;
const int pin_ledRed = 4;
int distance;

void setup() {
  pinMode(pin_ledYellow, HIGH);
  pinMode(pin_ledBlue, HIGH);
  pinMode(pin_ledRed, HIGH);
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);

  if (distance > 100){
    digitalWrite(pin_ledBlue, HIGH);
    digitalWrite(pin_ledYellow, LOW);
    digitalWrite(pin_ledRed, LOW);
  }
  if (distance <= 100 && distance > 20){
    digitalWrite(pin_ledYellow, HIGH);
    digitalWrite(pin_ledBlue, LOW);
    digitalWrite(pin_ledRed, LOW);

  }
  if (distance <= 20){
    digitalWrite(pin_ledRed, HIGH);
    digitalWrite(pin_ledBlue, LOW);
    digitalWrite(pin_ledYellow, LOW);
  }


}
