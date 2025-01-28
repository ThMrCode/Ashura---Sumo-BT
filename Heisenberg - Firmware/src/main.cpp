#include <Arduino.h>
const uint8_t pwm_left= 3;
const uint8_t digital_left_1 = 4;
const uint8_t digital_left_2 = 5;
const uint8_t pwm_right = 6;
const uint8_t digital_right_1 = 7;
const uint8_t digital_right_2 = 8;
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial serial_bt(10,11);


void setup() {
  pinMode(pwm_left, OUTPUT);
  pinMode(digital_left_1, OUTPUT);
  pinMode(digital_left_2, OUTPUT);
  pinMode(pwm_right, OUTPUT);
  pinMode(digital_right_1, OUTPUT);
  pinMode(digital_right_2, OUTPUT);
  
  analogWrite(pwm_left, 255);
  digitalWrite(digital_left_1, HIGH);
  digitalWrite(digital_left_2, LOW);
  analogWrite(pwm_right, 255);
  digitalWrite(digital_right_1, HIGH);
  digitalWrite(digital_right_2, LOW);
}

void loop() {
}


/*
const uint8_t pwm_left= 5;
const uint8_t digital_left_1 = 3;
const uint8_t digital_left_2 = 4;
const uint8_t pwm_right = 6;
const uint8_t digital_right_1 = 7;
const uint8_t digital_right_2 = 8;


void setup() {
  pinMode(pwm_left, OUTPUT);
  pinMode(digital_left_1, OUTPUT);
  pinMode(digital_left_2, OUTPUT);
  pinMode(pwm_right, OUTPUT);
  pinMode(digital_right_1, OUTPUT);
  pinMode(digital_right_2, OUTPUT);
  
  analogWrite(pwm_left, 255);
  digitalWrite(digital_left_1, HIGH);
  digitalWrite(digital_left_2, LOW);
  analogWrite(pwm_right, 255);
  digitalWrite(digital_right_1, HIGH);
  digitalWrite(digital_right_2, LOW);*/

  /*#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial serial_bt(10,11);


void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando");
  serial_bt.begin(9600);
}

void loop() {
  if (serial_bt.available()) {
    Serial.write(serial_bt.read());
  }
  if(Serial.available()) {
    serial_bt.write(Serial.read());
  }
}
*/