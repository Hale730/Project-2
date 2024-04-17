#include <Servo.h>

Servo myservo; // servo variable
const int buttonPin = 9; // copper wire is Pin 9
const int lightSensor = A2;
int sensorVal; //photoresistor
int buttonVal = 0;
int lastButtonVal = 0;

bool flight = false;

void setup() {
  myservo.attach(2); // servo is Pin 2
  pinMode(buttonPin, INPUT); 
  Serial.begin(9600);
  myservo.write(180);
}

void loop() {
  buttonVal = digitalRead(buttonPin);
  sensorVal = analogRead(lightSensor);

  if (buttonVal != lastButtonVal) {
    // if the state has changed, increment the counter
    if (buttonVal == LOW) {
      myservo.write(180); // nothing happens
    } else {
      myservo.write (90); // servo turns/Icarus flies
      flight = true;

    }
  }
  if (flight == true && sensorVal >= 750) {
      myservo.write (0);
    }
   

   Serial.println(sensorVal);
}
