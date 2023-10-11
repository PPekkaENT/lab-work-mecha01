#include <Servo.h>  
Servo myservo;  

// brake strength: positive angle 55 deg --->

void setup() {
  // attaches the servo on pin 10 to the servo object 
  myservo.attach(6);  
  // 55 degrees = neutral position
  myservo.write(55);
}

void loop() {
  delay(1000);
  // brake on
  myservo.write(73);
  delay(500);
  // brake off and back to neutral position
  myservo.write(55);
}
