void initBldc() {
  ESC.attach(8,1000,2000);
  return;
}
void bldcPower() {
  int i = 0;
  i = map(vehicle.power, 0, 100, 1000, 2000);
  // error handling
  if(i < 1000 || i > 2000) {i = 1000;}
  ESC.writeMicroseconds(i);
  return;
}
