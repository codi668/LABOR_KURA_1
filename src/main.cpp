#include <Arduino.h>

const int pwmPin = 9;          // PWM-Ausgang an Pin 9
volatile int dutyCycle = 128;  // Duty-Cycle von 0 bis 255 (128 entspricht 50%)

void setup() {
  pinMode(pwmPin, OUTPUT);     // Setzt den PWM-Pin als Ausgang
  digitalWrite(pwmPin, LOW);   // Startet mit LOW

  // Timer1 konfigurieren
  // Normal Mode (kein PWM-Modus), Prescaler 64

  TCCR1A = 0;                  // Normal Mode
  TCCR1B = (1 << CS11) | (1 << CS10); // Prescaler 64

  // Overflow-Interrupt aktivieren
  TIMSK1 = (1 << TOIE1);       // Overflow-Interrupt für Timer1 aktivieren

  // Interrupts global aktivieren
  sei();
}

ISR(TIMER1_OVF_vect) {
  static int counter = 0;      // Zählt bis zum Duty-Cycle-Wert

  if (counter < dutyCycle) {
    digitalWrite(pwmPin, HIGH); // Setzt den Pin auf HIGH, wenn der Counter < Duty-Cycle
  } else {
    digitalWrite(pwmPin, LOW);  // Setzt den Pin auf LOW, wenn der Counter >= Duty-Cycle
  }

  counter++;
  if (counter >= 256) {        // Wenn der Counter 255 erreicht, zurücksetzen
    counter = 0;
  }
}

void loop() {
  // Ändern des Duty-Cycles für das PWM-Signal
  // Beispiel: wir ändern den Duty-Cycle jede Sekunde

  delay(1000);
  dutyCycle = (dutyCycle + 64) % 256; // Duty-Cycle um 25% erhöhen (64 Schritte)
}
