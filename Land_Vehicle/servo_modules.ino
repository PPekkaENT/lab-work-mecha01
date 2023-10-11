void initServos() {
  // attaches the servo on pin 6 to the servo object 
  servoBrake.attach(6);  
  // 55 degrees = neutral position
  servoBrake.write(55);
  // attaches the servo on pin 10 to the servo object 
  servoTurn.attach(10); 
  // 70 degrees = neutral position  
  servoTurn.write(70);
  return;
}

void brakeSystem() {
  // set brake strength here
  servoBrake.write(73);  
}

// turn left 
void Test_Load_Left() {
  servoTurn.write(100);
  return; 

}
// turn right
void Test_Load_Right() {
  servoTurn.write(40);
  return; 
}

//Stop the motors
void clean_Output() {
  servoTurn.write(70);
  return;
}

// go straight
void go_straight() {
  servoTurn.write(70);
  return;
}
