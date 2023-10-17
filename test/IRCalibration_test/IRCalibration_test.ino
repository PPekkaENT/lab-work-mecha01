// Left IR reflective
const int irPin1 = 4;
// Center IR reflective
const int irPin2 = 5;
// Right IR reflective
const int irPin3 = 7;
// IR states
int ir1State = 0;
int ir2State = 0;
int ir3State = 0;

void setup() {
}

void loop() {
  // adjust sensitivity to distinguish black line from the environment
  // STATE: 0 = LOW, STATE: 1 = HIGH
  ir1State = digitalRead(irPin1);
  ir2State = digitalRead(irPin2);
  ir3State = digitalRead(irPin3);
  Serial.print("LEFT STATE:");
  Serial.println(ir1State);
  Serial.print("CENTER STATE:");
  Serial.println(ir2State);
  Serial.print("RIGHT STATE:");
  Serial.println(ir3State);
  delay(1000);
}
