#include <Servo.h>

Servo ESC;     // create servo object to control the ESC
int state = 0;

void setup() {
  // Attach the ESC on pin 9
  ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  Serial.begin(9600);
}

void loop() {

  if(Serial.available()>0) {
    // read command 1 byte
    state = Serial.read();
    // timeout?
  }
  // input 1
  if(state == 49) {
    ESC.write(1000);
    Serial.println("MIN");
  }
  // input 2
  if(state == 50) {
    ESC.write(2000);
    Serial.println("MAX"); 
  }
}
