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