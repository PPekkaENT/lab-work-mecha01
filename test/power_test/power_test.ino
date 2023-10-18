#include <Servo.h>
#include <Ultrasonic.h>

//Init an Ultrasonic object 
Ultrasonic ultrasonic(2,3); 

int Distance=0;  
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
Robot vehicle = {20, 55, 75, 70, 40, 100};

void setup() {
  int i = 0;

  ESC.attach(9,1000,2000);
  servoBrake.attach(6);  
  // 55 degrees = neutral position
  servoBrake.write(vehicle.brakeNeutral);
  servoTurn.attach(10); 
  // 70 degrees = neutral position  
  servoTurn.write(vehicle.neutral);

  i = map(vehicle.power, 0, 100, 1000, 2000);
  ESC.writeMicroseconds(i);
}

void loop() {
  //get the current distance;
  Distance=ultrasonic.Ranging(CM);
  // stop test after 15 s or object is closer than 10 cm
  if(millis() > 17000) {return;}
  if(millis() > 15000 || Distance < 10)
  {
    ESC.writeMicroseconds(1000);
    servoBrake.write(vehicle.brakePower); 
    delay(2000);
    servoBrake.write(vehicle.brakeNeutral);
  }
}
