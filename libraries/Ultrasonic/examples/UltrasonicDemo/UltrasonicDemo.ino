#include <Ultrasonic.h>
Ultrasonic ultrasonic(2,3);//Init an Ultrasonic object
int Distance;
void setup() {
Serial.begin(9600);
}

void loop()
{
 Distance=ultrasonic.Ranging(CM);//get the current result;
 delay(100);
 Serial.print("the distance is ");
 Serial.println(Distance);
 delay(1000);
}




