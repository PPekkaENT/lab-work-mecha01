// Include library files
#include <Servo.h>
#include <Math.h>

// Analog pins

// Digital pins:
// servo06 = D06
// servo010 = D10
// BLDC = D09

// Variables
// Servo motors
Servo servo06;
Servo servo010;
// BLDC motor/ESC (Servo object)
Servo ESC;

struct Robot{
  int power;
};
robot robot = {16};

// Define protypes

// #servo_modules.ino
// Initialize the servos
void initServos();
// Servo direction control functions 
/*void Test_Load_Left();
void Test_Load_Right();
void clean_Output();
void go_straight(); */

// #BLDC_module.ino
// Initialize BLDC
void initBldc();
void bldcPower();

void setup() {
  initServos();
  initBldc();
  delay(100);
  bldcPower();
}

void loop() {
}
