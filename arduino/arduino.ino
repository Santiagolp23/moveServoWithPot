#include <Servo.h>

Servo myservo; 
int pos;  

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  int pos = analogRead(0);
  Serial.println(pos);
  pos = map(pos, 0, 1023, 0, 180);
  myservo.write(pos);
  delay(100);

}
