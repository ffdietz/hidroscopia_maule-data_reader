#include <Arduino.h>

#define PWM_PIN 9

void motor_driver_init(){
  pinMode(PWM_PIN, OUTPUT);
}

void motor_out(byte power){
    analogWrite(PWM_PIN, power);
}

void serial_print(){
  Serial.print("A0: ");
  Serial.print(analogRead(0));
  Serial.print("    A1: ");
  Serial.print(analogRead(1));
  Serial.print("    A2: ");
  Serial.println(analogRead(2));
}

int mapping(int x, int out_min, int out_max) {
//return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return (x - 0 ) * (out_max - out_min) / (1023 - 0 ) + out_min;
}