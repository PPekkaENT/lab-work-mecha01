void initBldc() {
  ESC.attach(9,1000,2000);
  // set motor power to 0%
  return;
}
void bldcPower() {
  int i = 0;
  i = map(vehicle.power, 0, 100, 1000, 2000);
  //  i = map(vehicle.power, 0, 100, 90, 180);
  // error detection
  if(i < 1000 || i > 2000) {i = 1000;}
  ESC.writeMicroseconds(i);
  return;
}