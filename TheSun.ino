#include <Servo.h>

Servo myservo; // servo variable
const int buttonPin = 9; // copper wire is Pin 9
const int lightSensor = A0;
int sensorVal; //photoresistor
int buttonVal;

void setup() {
  myservo.attach(2); // servo is Pin 2
  pinMode(buttonPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  buttonVal = digitalRead(buttonPin);
  sensorVal = analogRead(lightSensor);

  if (buttonVal == LOW) {
    myservo.write(0); // nothing happens
  }
  else {
    myservo.write (90); // servo turns/Icarus flies
  }

  if (sensorVal >= 650); {
    myservo.write (180);
  }
}
