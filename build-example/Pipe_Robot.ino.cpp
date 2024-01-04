// Include libraries
#include <Servo.h>
#include <IRSendRev.h>

// Digital pins [2-5,8,9,11]
// hall sensor pin/interruptPin
const int hallPin = 2;
// LED pin
const int ledPin = 3;
// IR sensor
const int irPin = 4;
// D05 IR receiver
const int IR_Receiver=5;
// DC motor pin1
const int pinI1=8;   
// PWM to control the motor speed
const int speedpinA=9;
// DC motor pin2
const int pinI2=11;

// Variables
// array for ir receiver data
unsigned char dta[20];
// go command
bool goCmd = false; 
// IR reflective sensor states
int irState = 1;
// IR sensors target detection
int irDetection = false;
// status to determine if magnet is detected
bool detected = false;
// default motor speed
int speed = 175;

void setup();
void loop();
void hallInterrupt();
void motorSpeed(int val);

void setup() {
  pinMode(pinI1,OUTPUT);
  pinMode(pinI2,OUTPUT);
  pinMode(speedpinA,OUTPUT);
  // remote controller
  IR.Init(IR_Receiver);
  Serial.begin(9600);
  Serial.println("init over");
  // delay
  delay(1000);
  // attach interruptpin
  attachInterrupt(digitalPinToInterrupt(hallPin), hallInterrupt, CHANGE);
}

void loop() {

  // interpretation of remote control data
  if(IR.IsDta())
  {
    IR.Recv(dta);
    Serial.println(dta[8]);
    // on command
    if(dta[8] == 176)
    {
      goCmd = true;
    }
    // off command
    if(dta[8] == 248)
    {
      goCmd = false;
    }
  }
  // executed if a magnet is detected
  if (detected)
  {
    delay(250);
    motorSpeed(0);
    detected = false;
    irDetection = true;
    speed = 255;
    delay(3000);
    digitalWrite(ledPin,LOW);
    motorSpeed(speed);  
    delay(15000);
  }
  // detect the end condition
  if(irDetection)
  {
    irState = digitalRead(irPin);
    if(irState)
    {
      irDetection = false;
      delay(200);
      goCmd = false;
    }

  }
  // remote controller logic to control the on/off-state
  (goCmd) ? motorSpeed(speed) : motorSpeed(0);
}

// interrupt function
void hallInterrupt() {
  if( digitalRead(hallPin) == LOW){
    digitalWrite(ledPin,HIGH);
    detected = true;
    detachInterrupt(digitalPinToInterrupt(hallPin));
  }
}

// set the motor speed
void motorSpeed(int val)
{
  analogWrite(speedpinA,val);    
  digitalWrite(pinI1,HIGH);
  digitalWrite(pinI2,LOW);
  return;
}
