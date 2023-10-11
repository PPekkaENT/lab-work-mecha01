#include <Ultrasonic.h>

//Init an Ultrasonic object 
Ultrasonic ultrasonic(2,3); 

int Distance=0;
 
void setup() {
  Serial.begin(9600);
}

void loop()
{
  //get the current distance;
  Distance=ultrasonic.Ranging(CM);
  Serial.println(Distance);
  delay(100);
}
