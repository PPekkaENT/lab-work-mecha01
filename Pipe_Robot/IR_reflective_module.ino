bool checkIRstates() {
  // line detected
  bool lined = false;
  ir1State = digitalRead(irPin1);
  ir2State = digitalRead(irPin2);
  lined = (ir1State || ir2State) ? false : true;
  return lined;
}
