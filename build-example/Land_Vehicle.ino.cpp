#include <Arduino.h>

// Include library files
#include <Servo.h>
#include <Math.h>
#include <Ultrasonic.h>

// Analog pins

// Digital pins: [2-6,7,9,10]
// Left IR reflective
const int irPin1 = 4;
// Center IR reflective
const int irPin2 = 5;
// Right IR reflective
const int irPin3 = 7;
// servoBrake = D06
// servoTurn = D10
// ultrasonic = D02&D03
// BLDC = D09

// Variables
// Servo motors
Servo servoBrake;
Servo servoTurn;
// BLDC motor/ESC (Servo object)
Servo ESC;
// Ultrasonic object 
Ultrasonic ultrasonic(2,3);
// IR states
int ir1State = 0;
int ir2State = 0;
int ir3State = 0;
// ultrasonic distance
int ultraDistance = 0;
// A robot object to control the movement of the vehicle
// default values Robot vehicle{};
struct Robot{
  int power;
  int brakeNeutral;
  int brakePower;
  int neutral;
  int rightTurn;
  int leftTurn;
};
Robot vehicle = {20, 55, 73, 70, 40, 100};

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
// get ultrasonic sensors distance 
void getDistance();


void setup();

void loop();

void setup() {
  initServos();
  initBldc();
  delay(100);
  bldcPower();
}

void loop() {
  int power = vehicle.power;

  getDistance();
  if(ultraDistance < 40 && vehicle.power != 0) 
  {
    servoBrake.write(vehicle.brakePower);
  }
  if(ultraDistance < 30 && vehicle.power == 0) 
  {
    // set brake to neutral
    servoBrake.write(vehicle.brakeNeutral);
  }

  // power and direction
  vehicle.power = (checkIRstates()) ? 20 : 0;
  if(ultraDistance < 30 ) { vehicle.power = 0;}
  if(power != vehicle.power) { bldcPower(); }
}

void initBldc() {
  ESC.attach(9,1000,2000);
  // set motor power to 0%
  return;
}
void bldcPower() {
  int i = 0;
  i = map(vehicle.power, 0, 100, 1000, 2000);
  //  i = map(vehicle.power, 0, 100, 90, 180);
  // error detection
  if(i < 1000 || i > 2000) {i = 1000;}
  ESC.writeMicroseconds(i);
  return;
}

bool checkIRstates() {
  ir1State = digitalRead(irPin1);
  ir2State = digitalRead(irPin2);
  ir3State = digitalRead(irPin3);
  
  if((ir1State != 0)&(ir2State == 0)&(ir3State == 0)){
    //if(ir1State != 1){
    Test_Load_Left();
    return true;
  }
  if((ir1State == 0)&(ir2State != 0)&(ir3State == 0)) {
    //if(ir2State != 1){
    go_straight();
    return true;
  } 
  if((ir1State == 0)&(ir2State == 0)&(ir3State != 0)) {
    //if(ir3State != 1){
    Test_Load_Right();
    return true;
  }
  if((ir1State != 1)&(ir2State != 1)&(ir3State != 1)) {
    clean_Output();
    return false;
  }
  if((ir1State != 0)&(ir2State != 0)&(ir3State != 0)) {
    clean_Output();
    return false;
  }
}

void initServos() {
  // attaches the servo on pin 6 to the servo object 
  servoBrake.attach(6);  
  // 55 degrees = neutral position
  servoBrake.write(vehicle.brakeNeutral);
  // attaches the servo on pin 10 to the servo object 
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

void getDistance()
{
  //get the current distance;
  ultraDistance=ultrasonic.Ranging(CM);
  return;
}