#include <Servo.h>  

// Servo motors
Servo servoBrake;
Servo servoTurn;
// BLDC motor/ESC (Servo object)
Servo ESC;
// the number of test runs
int testNumber = 0;
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
  ESC.attach(9,1000,2000);
  servoBrake.attach(6);  
  // 55 degrees = neutral position
  servoBrake.write(vehicle.brakeNeutral);
  servoTurn.attach(10); 
  // 70 degrees = neutral position  
  servoTurn.write(vehicle.neutral);
}

void loop() {
  int i = 0;

  if(testNumber > 0) {return ;}
  i = map(vehicle.power, 0, 100, 1000, 2000);
  ESC.writeMicroseconds(i);
  // power on for 4 sec.
  delay(4000);
  // brake on for 3 sec.
  servoBrake.write(vehicle.brakePower);
  ESC.writeMicroseconds(1000);
  delay(3000);
  // test the brake with the power on
  // ESC.writeMicroseconds(1000);
  // brake off and back to neutral position
  servoBrake.write(vehicle.brakeNeutral);
  ++testNumber;
}
