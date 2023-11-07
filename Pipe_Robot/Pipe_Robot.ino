// Include library files
#include <Servo.h>
#include <Math.h>

// Analog pins

// Digital pins [2,4-6,9,10]:
// hall sensor pin/interruptPin
const int hallPin = 2;
// IR reflective nr.1
const int irPin1 = 4;
// IR reflective nr.2
const int irPin2 = 5;
// servo06 = D06
// servo010 = D10
// BLDC = D09

// Variables
// Servo motors
Servo servo06;
Servo servo010;
// BLDC motor/ESC (Servo object)
Servo ESC;

// IR reflective sensor states
int ir1State = 0;
int ir2State = 0;

struct Robot{
  int power;
};
Robot robot = {16};

// Define protypes

// #servo_modules.ino
// Initialize the servos
void initServos();

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
