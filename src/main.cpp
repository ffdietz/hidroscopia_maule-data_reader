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
  // Serial.begin(9600);
  sd_init();
  //pinMode PWM OUTPUT
  pinMode(13, OUTPUT);
}

void loop() {
  // sd read
  // millis delay( analogRead )
  //  analogWrite
  }