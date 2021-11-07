#include <Arduino.h>
#include "microSD.h"
#include "motorDriver.h"

boolean serial_enable = true;

unsigned long prev_millis = 0;

unsigned long interval_on = 10;
unsigned long interval_off = 900;

byte motor_power = 0;
boolean current_state = true;

void setup() {
 Serial.begin(9600);
  // sd_init();
  motor_driver_init();
}

void loop() {
  unsigned long current_millis = millis();

  //SD CARD READ TO SET THE MOTOR POWER

  if(current_millis - prev_millis >= (current_state ? interval_on : interval_off)) {

    //INVERSE LOGIC TO NPN TRANSISTOR DRIVER
    if(!current_state)  motor_power = analogRead(2) / 4;
    else                motor_power = 0;

    interval_on   = analogRead(1);
    interval_off  = analogRead(0);

    current_state =! current_state;
    prev_millis = current_millis;
  }
  
  motor_out(motor_power);
}



//1 fast protoype
//2 pcb design
//3 manufaturing //4  programming