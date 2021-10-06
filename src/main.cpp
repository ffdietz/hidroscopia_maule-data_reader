#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);
}

boolean state = HIGH;
void loop() {
  digitalWrite(2, state);
  delay(10);
  state = !state;
}