#include <AFMotor.h>

bool DEBUG = false;
char BT; 


AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// AF_DCMotor motor1(1);
// AF_DCMotor motor2(2);
// AF_DCMotor motor3(3);
// AF_DCMotor motor4(4);


void setup(){
  Serial.begin(9600);
  // Stop();
}


void loop() {
  if (Serial.available()>0) {
    BT=Serial.read();
    Stop();
    if (DEBUG) Serial.print(BT+"\n");

    switch(BT){
      
      case 'F' :
        forward();
        // if (DEBUG) Serial.print("forward\n");
      break;
      
      case 'B' :
        back();
        // if (DEBUG) Serial.print("backward\n");
      break;  
      
      case 'L' :
        left();
        // if (DEBUG) Serial.print("left\n");
      break;  
      
      case 'R' :
        right();
        // if (DEBUG) Serial.print("right\n");
      break;  
      
      default:
        // Stop();
      break;
  }
 }

}

void forward()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
  motor4.setSpeed(255);
  motor4.run(FORWARD); 
}

void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void left()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(FORWARD); 
  motor4.setSpeed(255); 
  motor4.run(FORWARD); 
}

void right()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD);
  motor2.setSpeed(255); 
  motor2.run(FORWARD);
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
} 

void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}
