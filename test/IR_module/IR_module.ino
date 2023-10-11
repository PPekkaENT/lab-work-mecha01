#include <Servo.h>  
Servo myservo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 
int angle = 0; 

// left
const int irPin1 = 4;
// center
const int irPin2 = 5;
// right
const int irPin3 = 7;
int ir1State = 0;
int ir2State = 0;
int ir3State = 0;

// servo

void setup() {
  // attaches the servo on pin 10 to the servo object
  myservo.attach(10);   
  myservo.write(70);
}

void loop() {
  ir1State = digitalRead(irPin1);
  ir2State = digitalRead(irPin2);
  ir3State = digitalRead(irPin3);
  
  if((ir1State != 0)&(ir2State == 0)&(ir3State == 0)){
    //if(ir1State != 1){
    Test_Load_Left();

    }
  if((ir1State == 0)&(ir2State != 0)&(ir3State == 0)){
    //if(ir2State != 1){
    go_straight();
    
    }
  if((ir1State == 0)&(ir2State == 0)&(ir3State != 0)){
    //if(ir3State != 1){
      Test_Load_Right();
      
    }
  if((ir1State != 1)&(ir2State != 1)&(ir3State != 1))
  {
    clean_Output();
    }
}

// turn left 
void Test_Load_Left()
{
  myservo.write(100); 

}
// turn right
void Test_Load_Right()
{
  myservo.write(40); 

}

//Stop the motors
void clean_Output()
{
  myservo.write(70);
}

// go straight
void go_straight()
{
  myservo.write(70);
}
