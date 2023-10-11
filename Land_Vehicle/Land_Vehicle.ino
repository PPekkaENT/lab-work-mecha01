// Include library files
#include <Servo.h>
#include <Math.h>
#include <Ultrasonic.h>

// Analog pins

// Digital pins: [2,3,4,5,6,7,10]
// Left IR reflective
const int irPin1 = 4;
// Center IR reflective
const int irPin2 = 5;
// Right IR reflective
const int irPin3 = 7;
// servoBrake = 6
// servoTurn = 10
// ultrasonic = 2&3

// Variables
// Servo objects
Servo servoBrake;
Servo servoTurn;
// Ultrasonic object 
Ultrasonic ultrasonic(2,3);
// IR states
int ir1State = 0;
int ir2State = 0;
int ir3State = 0;
// ultrasonic distance
int ultraDistance=0;

// Define protypes
// Initialize the servos #servo_modules.ino
void initServos(); 
// check IR states and make decisions about direction control #IR_reflective_module.ino
void checkIRstates();
// Use brake #servo_modules.ino
void brakeSystem();
// Servo direction control functions #servo_modules.ino
void Test_Load_Left();
void Test_Load_Right();
void clean_Output();
void go_straight();
//Get ultrasonic sensors distance
void getDistance();

void setup() {
  initServos();
}

void loop() {
  getDistance();
  checkIRstates();
  // if(ultaDistance < 80 && ir2State) { brakesystem();} etc.
}
