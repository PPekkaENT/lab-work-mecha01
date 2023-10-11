#include <Math.h>
int gyroPin = A0;             // declare the input pin for the analog gyro

float reference_Value=0;
int sensorValue = 0;            // variable to store the value coming from the analog gyro
double angularVelocity;
// custom test -->
double angle = 0;
double lastVelocity = 0;
unsigned long time0 = 0;
unsigned long time1 = 0;


void setup() {
  int i;
  float sum=0;
  pinMode(gyroPin, INPUT);
  Serial.begin(9600);
  Serial.println("Please do not rotate it before calibrate!");
  Serial.println("Get the reference value GYRO:");
  
  for(i=0;i<1000;i++)
  {
      // read the value from the sensor:
      sensorValue = analogRead(gyroPin);
      sum += sensorValue;
      delay(2);
  }
  reference_Value = sum/1000.0;
  Serial.println(reference_Value);
  Serial.println("Gyroscope ready!");
}

void loop() {
  sensorValue = analogRead(gyroPin);
  angularVelocity =((double)(sensorValue-reference_Value)*4930.0)/1023.0/0.67; //get the angular velocity
  time1 = millis();
  angle = (double) (angularVelocity+lastVelocity)/2*(time1-time0);
  time0 = time1;
  lastVelocity = angularVelocity;
  Serial.print(angularVelocity);
  Serial.println("deg/s");
  Serial.println(" ");
  Serial.print(angle);
  Serial.println(" deg");
  Serial.println(" ");
  delay(100);
}