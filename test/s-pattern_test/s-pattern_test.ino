#include <Servo.h>

Servo servoTurn;
// BLDC motor/ESC (Servo object)
Servo ESC;
struct Robot{
  int power;
  int brakeNeutral;
  int brakePower;
  int neutral;
  int rightTurn;
  int leftTurn;
};
Robot vehicle = {20, 55, 73, 70, 40, 100};

void setup() {
  int i = 0;

  ESC.attach(9,1000,2000);
  servoTurn.attach(10); 
  // 70 degrees = neutral position  
  servoTurn.write(vehicle.neutral);
  delay(50);
  i = map(vehicle.power, 0, 100, 1000, 2000);
  // default power 20 %
  ESC.writeMicroseconds(i);
}

void loop() {
  // go straight
  delay(2000);
  // go left
  servoTurn.write(vehicle.leftTurn);
  delay(2000);
  // go right
  servoTurn.write(vehicle.rightTurn);
  delay(2000);
  servoTurn.write(vehicle.neutral);
  delay(50);
}
