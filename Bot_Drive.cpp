#include "Bot_Drive.h"

  Drive::Drive() {
 	this -> Motor_Right1 = 0;
	this -> Motor_Right1_pwm = 0;		 
  	this -> Motor_Right2 = 0;
  	this -> Motor_Right2_pwm = 0;
	this -> Motor_Left1 = 0;
	this -> Motor_Left1_pwm = 0;	 
  	this -> Motor_Left2 = 0;
  	this -> Motor_Left2_pwm = 0;	 
}
void Drive::TwoWheelDrive(int motorPinR1,int motorPinR2, int pwmPinR1,int motorPinL1,int motorPinL2, int pwmPinL1){
	Motor_Right1 = motorPinR1;
	Motor_Right1_pwm = pwmPinR1;		 
  	Motor_Right2 = motorPinR2;
	Motor_Left1 = motorPinL1;
	Motor_Left1_pwm = pwmPinL1;	 
  	Motor_Left2 = motorPinL2;	 
	pinMode(Motor_Right1,OUTPUT);
	pinMode(Motor_Right1_pwm,OUTPUT);
	pinMode(Motor_Right2,OUTPUT);
	pinMode(Motor_Left1,OUTPUT);
	pinMode(Motor_Left1_pwm,OUTPUT);
	pinMode(Motor_Left2,OUTPUT);

	
}
void Drive::FourWheelDrive(int motorPinR1, int pwmPinR1,int motorPinR2, int pwmPinR2,int motorPinL1, int pwmPinL1,int motorPinL2, int pwmPinL2){
	Motor_Right1 = motorPinR1;
	Motor_Right1_pwm = pwmPinR1;		 
  	Motor_Right2 = motorPinR2;
  	Motor_Right2_pwm = pwmPinR2;
	Motor_Left1 = motorPinL1;
	Motor_Left1_pwm = pwmPinL1;	 
  	Motor_Left2 = motorPinL2;
  	Motor_Left2_pwm = pwmPinL2;	 
	pinMode(Motor_Right1,OUTPUT);
	pinMode(Motor_Right1_pwm,OUTPUT);
	pinMode(Motor_Right2,OUTPUT);
	pinMode(Motor_Right2_pwm,OUTPUT);
	pinMode(Motor_Left1,OUTPUT);
	pinMode(Motor_Left1_pwm,OUTPUT);
	pinMode(Motor_Left2,OUTPUT);
	pinMode(Motor_Left2_pwm,OUTPUT);			
}
  
  void Drive::rightMotor(int motorSpeed) {
  	
    if (motorSpeed > 0)                                 //if the motor should drive forward (positive speed)
    {

      digitalWrite(Motor_Right1, HIGH);
	  digitalWrite(Motor_Right2, LOW);                            							 //set pin 1 to high
                           
    }
    else if (motorSpeed < 0)                            //if the motor should drive backward (negative speed)
    {
      digitalWrite(Motor_Right1, LOW);
	  digitalWrite(Motor_Right2, HIGH);                        //set pin 1 to low
                           
    }
    else                                                //if the motor should stop
    {
      digitalWrite(Motor_Right1, LOW);
	  digitalWrite(Motor_Right2, LOW);   //set pin 1 to low
                             
    }
   
    
       analogWrite(Motor_Right1_pwm, abs(motorSpeed));                									//now that the motor direction is set, drive it at the entered speed
  }
    
  void Drive::leftMotor(int motorSpeed) {
    if (motorSpeed > 0)                                 //if the motor should drive forward (positive speed)
    {

      digitalWrite(Motor_Left1, HIGH);
	  digitalWrite(Motor_Left2, LOW);                            							 //set pin 1 to high
                           
    }
    else if (motorSpeed < 0)                            //if the motor should drive backward (negative speed)
    {
      digitalWrite(Motor_Left1, LOW);
	  digitalWrite(Motor_Left2, HIGH);                        //set pin 1 to low
                           
    }
    else                                                //if the motor should stop
    {
      digitalWrite(Motor_Left1, LOW);
	  digitalWrite(Motor_Left2, LOW);   //set pin 1 to low
                             
    }
   
    
       analogWrite(Motor_Left1_pwm, abs(motorSpeed));
                     //now that the motor direction is set, drive it at the entered speed
  }
  
  void Drive::forward(int myTime){
  leftMotor(255);
  rightMotor(255);
  delay(myTime);
  leftMotor(0);
  rightMotor(0);
}
void Drive::forward(int myTime,int speed){
  leftMotor(speed);
  rightMotor(speed);
  delay(myTime);
  leftMotor(0);
  rightMotor(0);
}

void Drive::forward(){
	leftMotor(255);
  rightMotor(255);
}

void Drive::reverse(int myTime){
  leftMotor(-255);
  rightMotor(-255);
  delay(myTime);
  leftMotor(0);
  rightMotor(0);
}
void Drive::turnRight(int myTime){
  leftMotor(255);
  rightMotor(100);
  delay(myTime);
  leftMotor(0);
  rightMotor(0);

}
void Drive::turnLeft(int myTime){
  leftMotor(100);
  rightMotor(255);
  delay(myTime);
  leftMotor(0);
  rightMotor(0);

}

void Drive::pivotLeft(int myTime){
  leftMotor(0);
  rightMotor(255);
  delay(myTime);
  leftMotor(0);
  rightMotor(0);

}
void Drive::pivotLeft(float radius, float angle, int revolutions_per_second) {
	float arch_length = angle *(3.14/180) * radius;
	float radians = arch_length/radius;
	float degrees = radians *(360/(2*3.14));
	float revolutions = degrees/360;
	float time = revolutions/revolutions_per_second;
	int time_in_ms = (int)time * 1000;
	leftMotor(0);
  	rightMotor(255);
  	delay(time_in_ms);
  	leftMotor(0);
  	rightMotor(0);
}
void Drive::Stop(int myTime){
  leftMotor(0);
  rightMotor(0);
  delay(myTime);
 
}

void Drive::pivotRight(int myTime){
  leftMotor(255);
  rightMotor(0);
  delay(myTime);
  leftMotor(0);
  rightMotor(0);

}

void Drive::pivotRight(float radius, float angle, int revolutions_per_second) {
	float arch_length = angle *(3.14/180) * radius;
	float radians = arch_length/radius;
	float degrees = radians *(360/(2*3.14));
	float revolutions = degrees/360;
	float time = revolutions/revolutions_per_second;
	int time_in_ms = (int)time * 1000;
	leftMotor(255);
  	rightMotor(0);
  	delay(time_in_ms);
  	leftMotor(0);
  	rightMotor(0);
}

void Drive::spinRight(int myTime){
  leftMotor(-255);
  rightMotor(255);
  delay(myTime);
  leftMotor(0);
  rightMotor(0);

}

void Drive::spinLeft(int myTime){
  leftMotor(255);
  rightMotor(-255);
  delay(myTime);
  leftMotor(0);
  rightMotor(0);

}

void Drive::figure8(){
  turnRight(8000);
  turnLeft(8000);
}

void Drive::circle(int dir){
  if( dir > 0){
 turnRight(1000);
  }
  else{
    turnLeft(1000);
  }
}

void Drive::Square(){
  for(int i =0; i < 4; ++i){
      forward(2000);
      spinRight(850);
  }
}
void Drive::randomWander(int randNumber){
  forward(randNumber);
  Stop(100);
  turnRight(randNumber);
  Stop(100);
}
  



