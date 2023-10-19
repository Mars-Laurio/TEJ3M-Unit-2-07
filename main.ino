/*
 * Created by: Mars Laurio
 * Created on: Oct 2023
 * 
 * Turns servo when reaches a certain distance.
 */
 
#include <Servo.h>

Servo servoNumber1;
const int trigPin = 9;
const int echoPin = 10;



float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servoNumber1.attach(8);
  servoNumber1.write(0);                                                                                                                                                                                                                                                           
}
 
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  if(distance < 50) {
    servoNumber1.write(180);
    print("Object Found")
  }
    else{
      servoNumber1.write(0);
  }
  Serial.println(distance);
  delay(100);
}