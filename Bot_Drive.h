
#include <Arduino.h>
#ifndef BOT_DRIVE_H
#define BOT_DRIVE_H

class Drive{
  private:
  	int Motor_Right1;
	int Motor_Right1_pwm;		 
  	int Motor_Right2;	
  	int Motor_Right2_pwm;	
	int Motor_Left1;
	int Motor_Left1_pwm;		 
  	int Motor_Left2;	
  	int Motor_Left2_pwm;	
  public:
  	
	Drive();
	void FourWheelDrive(int motorPinR1, int pwmPinR1,int motorPinR2, int pwmPinR2,int motorPinL1, int pwmPinL1,int motorPinL2, int pwmPinL2);
	void TwoWheelDrive(int motorPinR1,int motorPinR2, int pwmPinR1,int motorPinL1,int motorPinL2, int pwmPinL1);
	void Right(int motorPin,  int pwmPin);
	void Left(int motorPin, int pwmPin);
	void rightMotor(int motorSpeed);
	void leftMotor(int motorSpeed);
	void forward(int myTime);
	void forward();
	void forward(int myTime, int speed);
	void reverse(int myTime);
	void turnRight(int myTime);	
	void turnLeft(int myTime);
	void pivotLeft(int myTime);
	void pivotLeft(float radius, float angle, int revolutions_per_second);
	void Stop(int myTime);
	void pivotRight(float radius, float angle, int revolutions_per_second);
	void pivotRight(int myTime);
	void spinRight(int myTime);
	void spinLeft(int myTime);
	void figure8();
	void circle(int dir);
	void Square();
	void randomWander(int randNumber);
	
};

#endif
