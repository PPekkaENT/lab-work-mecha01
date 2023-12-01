// Include library files
#include <Servo.h>
#include <IRSendRev.h>

// Digital pins [2-5,8,9,11]
// hall sensor pin/interruptPin
const int hallPin = 2;
// LED pin
const int ledPin = 3;
// D05 IR receiver
const int IR_Receiver=5;
// IR reflective nr.1
const int irPin = 4;
const int pinI1=8;     // motor 1 pin1
const int pinI2=11;    //motor 1 pin2
const int speedpinA=9; //EA(PWM)to control the motor_1 speed

// Variables
// array for ir receiver data
unsigned char dta[20];
// go command
bool goCmd = false; 
// IR reflective sensor states
int irState = 1;
int irDetection = false;

bool detected = false;
int speed = 175;

void setup() {
  pinMode(pinI1,OUTPUT); //set to output
  pinMode(pinI2,OUTPUT);
  pinMode(speedpinA,OUTPUT);

  //bldcPower();
  // remote controller
  IR.Init(IR_Receiver);
  Serial.begin(9600);
  Serial.println("init over");
  // delay
  delay(1000);
  // hall sensor
  attachInterrupt(digitalPinToInterrupt(hallPin), hallInterrupt, CHANGE);
}

void loop() {

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
  (goCmd) ? motorSpeed(speed) : motorSpeed(0);
}

void hallInterrupt() {
  if( digitalRead(hallPin) == LOW){
    digitalWrite(ledPin,HIGH);
    detected = true;
    detachInterrupt(digitalPinToInterrupt(hallPin));
  }
}

void motorSpeed(int val)
{
  analogWrite(speedpinA,val);    
  digitalWrite(pinI1,HIGH);
  digitalWrite(pinI2,LOW);
  return;
}
