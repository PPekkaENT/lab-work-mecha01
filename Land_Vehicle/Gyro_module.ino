#include <Math.h>

void calibrateGyro() {
  int i;
  float sum=0;
  pinMode(gyroPin, INPUT);
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
  return;
}

void calculateAngle() {
  sensorValue = analogRead(gyroPin);
  angularVelocity =((double)(sensorValue-reference_Value)*4930.0)/1023.0/0.67; //get the angular velocity
  time1 = millis();
  angle = (double) (angularVelocity+lastVelocity)/2*(time1-time0);
  time0 = time1;
  Serial.print(angle);
  Serial.println(" deg");
  Serial.println(" ");
  return;
}
