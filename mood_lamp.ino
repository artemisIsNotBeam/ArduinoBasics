const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int potenPin = 0;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // The potentiometer returns a number from 0-1024
  // representing how far the knob is turned.
  int val = analogRead(potenPin);
  Serial.println(val);
  if(val < 256) {
    // sets color to red
    setColor(255, 0, 0);
  } else if (val < 512) {
    // sets color to green
    setColor(0, 255, 0);
  } else if (val < 768) {
    // sets color to blue
    setColor(0, 0, 255);
  } else {
    // shifts through the cycles
    for(int i = 0; i < 255; i++) {
      setColor(i, 255-i, 0);
      delay(10);
    }
    for(int i = 0; i < 255; i++) {
      setColor(255-i, 0, i);
      delay(10);
    }
    for(int i = 0; i < 255; i++) {
      setColor(0, i, 255-i);
      delay(10);
    }
  }
}

void setColor(int redVal, int greenVal, int blueVal) {
  // sets red, green, and blue values to create colors
  // on the LED
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}
