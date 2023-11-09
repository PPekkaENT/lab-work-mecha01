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
// BLDC = D08

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

// Define protypes here if any tabs

void setup() {
  // initialize BLDC
  ESC.attach(9,1000,2000);
  // attaches the servo on pin 6 to the servo object (braking) 
  servo06.attach(6);
  //servo06.write();
  // attaches the servo on pin 10 to the servo object 
  servo010.attach(10); 
  //servoTurn.write();  
  bldcPower();
  // delay for ESC to start
  delay(1000);
}

void loop() {
}

void bldcPower() {
  int i = 0;
  i = map(robot.power, 0, 100, 1000, 2000);
  // error handling
  if(i < 1000 || i > 2000) {i = 1000;}
  ESC.writeMicroseconds(i);
  return;
}

bool checkIRstates() {
  // line detected
  bool lined = false;
  ir1State = digitalRead(irPin1);
  ir2State = digitalRead(irPin2);
  lined = (ir1State || ir2State) ? false : true;
  return lined;
}
