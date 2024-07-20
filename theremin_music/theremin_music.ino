#include "arduino_secrets.h"

int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;
const int transistor = A0;
const int buzzer = 8;
int red = 11;
int green = 10;
int blue = 9;
int note;
int color;


void setup() {
  pinMode(transistor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  while (millis() < 5000)
  {
    sensorVal = analogRead(transistor);
    if (sensorVal > sensorHigh) {
    sensorHigh = sensorVal;
    }
    else if (sensorVal < sensorLow) {
    sensorLow = sensorVal;
    }
  }
  note = 0;
  color = 0;
}
void loop() {
  sensorVal = analogRead(transistor);
  note = map(sensorVal, sensorLow, sensorHigh, 50, 4000);
  color = sensorVal/4;
  setColor(255-color, color, 0);
  tone(buzzer, note);
  delay(10);
}

void setColor(int redVal, int greenVal, int blueVal) {
  analogWrite(red, redVal);
  analogWrite(green, greenVal);
  analogWrite(blue, blueVal);
}
