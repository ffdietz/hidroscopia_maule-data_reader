#include <Arduino.h>
#include "microSD.h"


//include sd module
//sd reader
//motor driver control
//speed control


//1 fast protoype
//2 pcb design
//manufaturing
// programming

void setup() {
  Serial.begin(9600);
  // sd_init();
  //pinMode PWM OUTPUT
  pinMode(3, OUTPUT);
}

byte state = 0;
void loop() {
  // sd read
  // millis delay( analogRead )
  //  analogWrite
  analogWrite(3, 64 + analogRead(1)/4); //minimun motor signal
  delay(500);
  analogWrite(3, 0);
  delay(500);
  Serial.println(analogRead(1)/4);
}