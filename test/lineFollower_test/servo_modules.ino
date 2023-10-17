void initServos() {
  // attaches the servo on pin 6 to the servo object 
  servoBrake.attach(6);  
  // 55 degrees = neutral position
  servoBrake.write(vehicle.brakeNeutral);
  // attaches the servo on pin 10 to the servo object 
  servoTurn.attach(10); 
  // 70 degrees = neutral position  
  servoTurn.write(vehicle.neutral);
  return;
}

// turn left 
void Test_Load_Left() {
  servoTurn.write(vehicle.leftTurn);
  return; 

}
// turn right
void Test_Load_Right() {
  servoTurn.write(vehicle.rightTurn);
  return; 
}

// Stop the motors
void clean_Output() {
  servoTurn.write(vehicle.neutral);
  return;
}

// go straight
void go_straight() {
  servoTurn.write(vehicle.neutral);
  return;
}
