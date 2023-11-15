// Include library files
#include <Servo.h>
#include <IRSendRev.h>

// Digital pins [2-6,8]
// hall sensor pin/interruptPin
const int hallPin = 2;
// LED pin
const int ledPin = 3;
// D05 IR receiver
const int IR_Receiver=5;
// IR reflective nr.1
//const int irPin = 4;
// servo06 = D06
// BLDC = D08

// Variables
// Servo motors
// Servo servo06;
// BLDC motor/ESC (Servo object)
Servo ESC;
// array for ir receiver data
unsigned char dta[20];
// go command
bool goCmd = false; 
// IR reflective sensor states
//int irState = 0;

struct Robot{
  int power;
};
Robot robot = {0};

// Define protypes here if any tabs

void setup() {
  // initialize BLDC
  ESC.attach(8,1000,2000);
  // attaches the servo on pin 6 to the servo object (braking) 
  //servo06.attach(6);
  //servo06.write(); 
  bldcPower();
  // remote controller
  IR.Init(IR_Receiver);
  Serial.begin(9600);
  Serial.println("init over");
  // hall sensor
  attachInterrupt(digitalPinToInterrupt(hallPin), func1, FALLING);
  // delay
  delay(1000);
  
}

void loop() {

  int power = robot.power;
  if(IR.IsDta())
  {
    IR.Recv(dta);
    Serial.println(dta[8]);
    // on cmd
    if(dta[8] == 176)
    {
      goCmd = true;
    }
    // off cmd
    if(dta[8] == 248)
    {
      goCmd = false;
    }
  }
  robot.power = (goCmd) ? 10 : 0;
  if(power != robot.power) {bldcPower();}  
}

void bldcPower() {
  int i = 0;
  i = map(robot.power, 0, 100, 1000, 2000);
  // error handling
  if(i < 1000 || i > 2000) {i = 1000;}
  ESC.writeMicroseconds(i);
  return;
  
}

void func1() {
  digitalWrite(ledPin,HIGH);
  return;
}

/*bool checkIRstates() {
  // line detected
  bool lined = false;
  ir1State = digitalRead(irPin);
  lined = (ir1State || ir2State) ? false : true;
  return lined;
}*/
