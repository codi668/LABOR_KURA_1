#include <Arduino.h>

void setup() {
  // Pin 9 als Ausgang definieren (Timer1 ist mit Pin 9 verbunden)
  pinMode(9, OUTPUT);

  // Timer1 auf eine Frequenz von 1 kHz einstellen
  TCCR1A = _BV(COM1A0);  // Toggle Pin 9 (OC1A) bei jedem Timer-Überlauf
  TCCR1B = _BV(WGM12) | _BV(CS10);  // CTC-Modus, keine Prescaler

  // Der Wert von OCR1A bestimmt die Frequenz:
  OCR1A = 7999;  // (16 MHz / (2 * 1 kHz)) - 1 = 7999 für 1 kHz
}

void loop() {
  // Im Hauptprogramm muss nichts gemacht werden
}
