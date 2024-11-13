#include <Arduino.h>
int pwmPin = 9;           // PWM-Ausgang an Pin 9
int dutyCycle = 128;      // Duty-Cycle von 0 bis 255 (128 entspricht 50%)

void setup() {
  pinMode(pwmPin, OUTPUT); // Setzt den Pin als Ausgang
}

void loop() {
  analogWrite(pwmPin, dutyCycle); // Gibt das PWM-Signal mit dem Duty-Cycle aus
  // Kein delay() erforderlich, da der Wert beständig bleibt
}
