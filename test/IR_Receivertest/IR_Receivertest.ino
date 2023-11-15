#include <IRSendRev.h>
// D05
int IR_Receiver=5;
unsigned char dta[20];
bool goCmd = false; 

void setup()
{ 
  IR.Init(IR_Receiver);
  Serial.begin(9600);
  Serial.println("init over");
  // delay
  delay(1000);
}

void loop()
{
  if(IR.IsDta())
  {
    IR.Recv(dta);
    Serial.println(dta[8]);
    //Serial.println(dta[6]);
    if(dta[8] == 176)
    {
      goCmd = true;
    }
    if(dta[8] == 248)
    {
      goCmd = false;
    }
  } 
}
