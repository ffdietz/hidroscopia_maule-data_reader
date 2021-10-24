#include <Arduino.h>
#include "microSD.h"
#include "motorDriver.h"

boolean serial_enable = true;

//1 fast protoype
//2 pcb design
//manufaturing
// programming

unsigned long prev_millis = 0;
long interval = 1000;
byte motor_power_out = 0;
boolean current_state = true;

void setup() {
 Serial.begin(9600);
  // sd_init();
  motor_driver_init();
}

void loop() {
  unsigned long current_millis = millis();

  if(current_millis - prev_millis >= interval) {
    prev_millis = current_millis;

    if(current_state)       motor_power_out = analogRead(0) / 4;
    if(!current_state)      motor_power_out = 0;

    current_state = !current_state;
    interval = analogRead(1) + 1;
  }
  
  motor_out(motor_power_out);

  serial_print();
  // sd read
  // update analog read >> POWER / HIGH / LOW
  // set timer >> HIGH / LOW
  // analogWrite POWER
  // sd_test();
}