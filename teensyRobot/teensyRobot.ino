const int nbrSwitches                  = 2;
const int bumpSwitchPins[nbrSwitches]  = {24,33};
const int switchPin                    = 5; 
const int ledPin                       = 13;
const int leftMotorPins[]              = {27,30,32}; // marked wheel 1 on board
const int rightMotorPins[]             = {20,6,25};  // marked wheel 2 on board  (6 & 20 swapped in final brd)

// encoder pins
const int wheel_1QeiAPin = 29;  //external interrupt 0 used for wheel 1 encoder channel A
const int wheel_1QeiBPin = 31;  //wheel 1 encoder channel B input
const int wheel_2QeiAPin = 28;  //external interrupt 1 used for wheel 2 encoder channel A
const int wheel_2QeiBPin = 26;  //wheel 2 encoder channel B input

int wheel_1QeiCounts; //quadrature encoder counter variables
int wheel_2QeiCounts; //quadrature encoder counter variables


#include "HUBeeBMDWheel.h"

HUBeeBMDWheel motor1Wheel;
HUBeeBMDWheel motor2Wheel;

void setup() {     
  Serial.begin(9600);
  
  pinMode(wheel_1QeiAPin, INPUT_PULLUP);
  pinMode(wheel_2QeiAPin, INPUT_PULLUP);
  pinMode(wheel_1QeiBPin, INPUT_PULLUP);
  pinMode(wheel_2QeiBPin, INPUT_PULLUP);
  
  pinMode(switchPin,INPUT);           
  motor1Wheel.setupPins(leftMotorPins[0],leftMotorPins[1],leftMotorPins[2]); 
  motor2Wheel.setupPins(rightMotorPins[0],rightMotorPins[1],rightMotorPins[2]);

  attachInterrupt(wheel_1QeiAPin, QEI_wheel_1, CHANGE);
  attachInterrupt(wheel_2QeiAPin, QEI_wheel_2, CHANGE);
  
}

// the loop routine runs over and over again forever:
void loop() {

//  Serial.println(wheel_1QeiCounts);
  
  delay(10);

  while (abs(wheel_1QeiCounts) <= 200){
    delay(1);
    drive(0, 200);
    Serial.println(wheel_1QeiCounts);
    Serial.println(wheel_2QeiCounts);
  }
  stopRobot();
  delay(2000);

    while (abs(wheel_1QeiCounts) <= 260){
    delay(1);
    slightTurn(0, 200, 50);
    Serial.println(wheel_1QeiCounts);
    Serial.println(wheel_2QeiCounts);
  }
  
  stopRobot();
  delay(2000);

  while (abs(wheel_1QeiCounts) <= 460){
    delay(1);
//    slightTurn(0, 100, 50);
    drive(0, 200);
    Serial.println(wheel_1QeiCounts);
    Serial.println(wheel_2QeiCounts);
  }
  
  stopRobot();
  delay(2000);


}

void drive(int robotDirection, int robotSpeed){
  
  motor1Wheel.setDirectionMode(robotDirection);
  motor2Wheel.setDirectionMode(not(robotDirection));
  motor1Wheel.setMotorPower(robotSpeed);
  motor2Wheel.setMotorPower(robotSpeed);

}

void robotTurn(int robotDirection, int robotSpeed){
 
  motor1Wheel.setDirectionMode(robotDirection);
  motor2Wheel.setDirectionMode(not(robotDirection));
  motor1Wheel.setMotorPower(robotSpeed);  //0 - 255 
  motor2Wheel.setMotorPower(robotSpeed);  //0 - 255
}

void slightTurn( int robotDirection, int spWh1, int spWh2){
 
  motor1Wheel.setDirectionMode(robotDirection);
  motor2Wheel.setDirectionMode(not(robotDirection));
  motor1Wheel.setMotorPower(spWh1);  //0 - 255 
  motor2Wheel.setMotorPower(spWh2);  //0 - 255
}


void stopRobot(){
  motor2Wheel.stopMotor();
  motor1Wheel.stopMotor();
}

  void QEI_wheel_1() 
  {
    if(digitalRead(wheel_1QeiAPin))
    {
      if(digitalRead(wheel_1QeiBPin))
      {
        wheel_1QeiCounts--;
        return;
      }
      wheel_1QeiCounts++;
      return;
    }
    if(digitalRead(wheel_1QeiBPin))
    {
      wheel_1QeiCounts++;
      return;
    }
    wheel_1QeiCounts--;
  }

  void QEI_wheel_2() 
  {
    if(digitalRead(wheel_2QeiAPin))
    {
      if(digitalRead(wheel_2QeiBPin))
      {
        wheel_2QeiCounts--;
        return;
      }
      wheel_2QeiCounts++;
      return;
    }
    if(digitalRead(wheel_2QeiBPin))
    {
      wheel_2QeiCounts++;
      return;
    }
    wheel_2QeiCounts--;
  }







