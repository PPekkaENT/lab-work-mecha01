bool checkIRstates() {
  int sum = 0;
  ir1State = digitalRead(irPin1);
  ir2State = digitalRead(irPin2);
  ir3State = digitalRead(irPin3);
  sum = ir1State + ir2State + ir3State;

  if((ir1State == 1)&(ir2State == 0)&(ir3State == 0)){
    Test_Load_Left();
    return true;
  }
  if(ir2State == 1 && sum < 3) {
    go_straight();
    return true;
  } 
  if((ir1State == 0)&(ir2State == 0)&(ir3State == 1)) {
    Test_Load_Right();
    return true;
  }
  if((ir1State != 1)&(ir2State != 1)&(ir3State != 1)) {
    clean_Output();
    return true;
  }
  if((ir1State != 0)&(ir2State != 0)&(ir3State != 0)) {
    clean_Output();
    return false;
  }
}
