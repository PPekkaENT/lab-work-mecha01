// Include libraries
#include <Servo.h>
#include <Math.h>
#include <Ultrasonic.h>

// Digital pins: [2-8,10]
// Ultrasonic sensor 
Ultrasonic ultrasonic(2,3);
// Left IR sensor
const int irPin1 = 4;
// Center IR sensor
const int irPin2 = 5;
// Right IR sensor
const int irPin3 = 7;
// BLDC = D08
// servoBrake = D06
// servoTurn = D10

// Variables
// Servo motors
Servo servoBrake;
Servo servoTurn;
// Servo object ESC
Servo ESC;
// IR states
int ir1State = 0;
int ir2State = 0;
int ir3State = 0;
// ultrasonic distance
int ultraDistance = 0;
// A robot object to control the movement of the vehicle
// default Robot vehicle{};
struct Robot{
  int power;
  int brakeNeutral;
  int brakePower;
  int neutral;
  int rightTurn;
  int leftTurn;
};
Robot vehicle = {16, 55, 80, 70, 60, 80};

// Define protypes
// #servo_modules.ino
// Initialize the servos
void initServos();
// Servo direction control functions 
void Test_Load_Left();
void Test_Load_Right();
void clean_Output();
void go_straight(); 

// #BLDC_module.ino
// Initialize BLDC
void initBldc();
void bldcPower();

// #IR_reflective_module.ino
// check IR states and make decisions about direction control 
bool checkIRstates();

// #ultrasonic_module.ino
// get the ultrasonic sensors distance 
void getDistance();

void setup() {
  initServos();
  initBldc();
  bldcPower();
  delay(1000);
}

void loop() {
  int power = vehicle.power;
  getDistance();
  // Braking
  // the brake is in neutral by default
  (ultraDistance < 35 && vehicle.power == 0) ? servoBrake.write(vehicle.brakePower) : 
    servoBrake.write(vehicle.brakeNeutral);

  if (ultraDistance > 100)
  {
    vehicle.power = (checkIRstates()) ? 16 : 0;
  }
  else
  {
    vehicle.power = (checkIRstates()) ? 13 : 0;
  }
  if(ultraDistance < 35 ) {vehicle.power = 0;}
  if(power != vehicle.power) {bldcPower();}
}

void initBldc() {
  ESC.attach(8,1000,2000);
  return;
}
void bldcPower() {
  int i = 0;
  i = map(vehicle.power, 0, 100, 1000, 2000);
  // error handling
  if(i < 1000 || i > 2000) {i = 1000;}
  ESC.writeMicroseconds(i);
  return;
}

bool checkIRstates() {
  int sum = 0;
  ir1State = digitalRead(irPin1);
  ir2State = digitalRead(irPin2);
  ir3State = digitalRead(irPin3);
  sum = ir1State + ir2State + ir3State;

  if((ir1State == 1)&(ir2State == 0)&(ir3State == 0)){
    Test_Load_Left();
    return true;
  }
  if(ir2State == 1 && sum < 3) {
    go_straight();
    return true;
  } 
  if((ir1State == 0)&(ir2State == 0)&(ir3State == 1)) {
    Test_Load_Right();
    return true;
  }
  if((ir1State != 1)&(ir2State != 1)&(ir3State != 1)) {
    clean_Output();
    return true;
  }
  if((ir1State != 0)&(ir2State != 0)&(ir3State != 0)) {
    clean_Output();
    return false;
  }
}

void getDistance()
{
  // get the current distance;
  ultraDistance = ultrasonic.Ranging(CM);
  return;  
}

void initServos() {
  // attach the servo object on pin 6 
  servoBrake.attach(6);  
  // 55 degrees = neutral position
  servoBrake.write(vehicle.brakeNeutral);
  // attach the servo object on pin 10
  servoTurn.attach(10); 
  // 70 degrees = neutral position  
  servoTurn.write(vehicle.neutral);
  return;
}

// turn left 
void Test_Load_Left() {
  servoTurn.write(vehicle.leftTurn);
  return; 

}
// turn right
void Test_Load_Right() {
  servoTurn.write(vehicle.rightTurn);
  return; 
}

// Stop the motors
void clean_Output() {
  servoTurn.write(vehicle.neutral);
  return;
}

// go straight
void go_straight() {
  servoTurn.write(vehicle.neutral);
  return;
}
