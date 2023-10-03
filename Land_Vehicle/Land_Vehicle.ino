// include library files
#include <Servo.h>
#include <Math.h>

// analog pins
// gyro
int gyroPin = A4;

// digital pins

// variables
float reference_Value=0;
int sensorValue = 0;        
double angularVelocity;
double angle = 0;
double lastVelocity = 0;
unsigned long time0 = 0;
unsigned long time1 = 0;

// define protypes
// gyro functions
void calibrateGyro();
void calculateAngle();
// BLDC motor functions

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
}

void loop() {
  calculateAngle();
  delay(50);
}
