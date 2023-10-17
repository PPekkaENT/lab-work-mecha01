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
// change the power & brakePower TODO: determine braking strength for [10, 15,20] %
Robot vehicle = {15, 55, 73, 70, 40, 100};

void setup() {
  int i = 0;
  ESC.attach(9,1000,2000);
  servoBrake.attach(6);  
  // 55 degrees = neutral position
  servoBrake.write(vehicle.brakeNeutral);
  servoTurn.attach(10); 
  // 70 degrees = neutral position  
  servoTurn.write(vehicle.neutral);
  Serial.begin(9600);
  delay(100);
  i = map(vehicle.power, 0, 100, 1000, 2000);
  // default 15 %
  ESC.writeMicroseconds(i);
}

void loop() {
  // 10 brake on, 11 brake off
  if(Serial.available())
  {
    int i = 0;
    i = Serial.parseInt();
    // brake on 
    if(i == 10)
    {
      servoBrake.write(vehicle.brakePower);
    }
    // brake off
    if(i == 11) 
    {
      servoBrake.write(vehicle.brakeNeutral);
    }
  }
}