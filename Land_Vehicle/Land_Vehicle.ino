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
// get ultrasonic sensors distance 
void getDistance();

void setup() {
  initServos();
  initBldc();
  delay(100);
  bldcPower();
  Serial.begin(9600);
}

void loop() {
  int power = vehicle.power;
  //Serial.print("Current power: ");
  //Serial.println(power);
  getDistance();
  Serial.println(ultraDistance);

  // Braking
  if(ultraDistance < 32 && vehicle.power == 0) 
  {
    servoBrake.write(vehicle.brakePower);
  } else {
    servoBrake.write(vehicle.brakeNeutral);
  }
  /*
  if(ultraDistance < 30 && vehicle.power == 0) 
  {
    // set brake to neutral
    servoBrake.write(vehicle.brakeNeutral);
  }
  */
  // power and direction
  vehicle.power = (checkIRstates()) ? 16 : 0;
  if(ultraDistance < 32 ) {vehicle.power = 0;}
  if(power != vehicle.power) {bldcPower();}
}
