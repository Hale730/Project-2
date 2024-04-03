const int lightSensor = A0;
const int ledPin = 13;

int sensorVal;        //Photoresistor
int ledBrightness;

// When lights are on, sensorVal ~ 630+
// When lights are off, sensorVal ~ 200-
// So, ranges should be LEDs on < sensorVal=300 < LEDs off

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorVal = analogRead(lightSensor);

  if (sensorVal >= 300) {
      ledPin = HIGH;
    }
  }
