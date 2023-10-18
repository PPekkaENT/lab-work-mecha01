void getDistance()
{
  //get the current distance;

  int values[4] = {0,0,0,0};

  for (int i = 0; i < 4; ++i) 
  {
    values[i] = ultrasonic.Ranging(CM);
  }
  int maxVal = values[0];
  for (int i = 0; i < (sizeof(values) / sizeof(values[0])); ++i)
  {
    if (values[i] > maxVal) 
    {
      maxVal = values[i];
    }
  }
  ultraDistance = maxVal; 
  return;
}
