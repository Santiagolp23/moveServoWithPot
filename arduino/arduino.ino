#include <Servo.h>

Servo myservo; 

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int pos;  

void setup() {
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  myservo.attach(9);
}

void loop() {
    // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(0);
  // add the reading to the total:
  total += readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;
  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ... go to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  pos = total / numReadings;
  Serial.println(pos);

  // maps the pot min max values to the ones accepted by the pot:
  pos = map(pos, 0, 1023, 0, 180); 
  myservo.write(pos);
  delay(5); // for stability

}
