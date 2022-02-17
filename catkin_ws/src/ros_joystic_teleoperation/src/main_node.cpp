#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include "std_msgs/String.h"
#include <wiringPi.h>
#include <cmath>
#include <stdio.h>

int UP_DOWN_AXIS_STICK_LEFT = 1;
int UP_DOWN_AXIS_STICK_RIGHT = 3;

int pin_PWM_right = 1;
int pin_forward_right = 11;
int pin_backward_right = 10;

int pin_PWM_left = 23;
int pin_forward_left = 13;
int pin_backward_left = 12;

int DIGITAL_OUT_MODE = 1;
int PWM_MODE = 2;

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
	
	double left_value_double = joy->axes[UP_DOWN_AXIS_STICK_LEFT];
	int left_value = (int)(round(1023.0 * left_value_double));
	if (left_value == 0) {
		pwmWrite(pin_PWM_left, 0);
		digitalWrite(pin_forward_left, 0);
		digitalWrite(pin_backward_left, 0);
	} else {
		int left_value_abs = abs(left_value);
		pwmWrite(pin_PWM_left, left_value_abs);
		if (left_value > 0) {
			digitalWrite(pin_forward_left, 1);
			digitalWrite(pin_backward_left, 0);
		} else {
			digitalWrite(pin_forward_left, 0);
			digitalWrite(pin_backward_left, 1);
		}
	}
	
	double right_value_double = joy->axes[UP_DOWN_AXIS_STICK_RIGHT];
	int right_value = (int)(round(1023.0 * right_value_double));
	if (right_value == 0) {
		pwmWrite(pin_PWM_right, 0);
		digitalWrite(pin_forward_right, 0);
		digitalWrite(pin_backward_right, 0);
	} else {
		int right_value_abs = abs(right_value);
		pwmWrite(pin_PWM_right, right_value_abs);
		if (right_value > 0) {
			digitalWrite(pin_forward_right, 1);
			digitalWrite(pin_backward_right, 0);
		} else {
			digitalWrite(pin_forward_right, 0);
			digitalWrite(pin_backward_right, 1);
		}
	}
	
  
}


int main(int argc, char **argv)
{
 
	ros::init(argc, argv, "main_node");

	wiringPiSetup();

  
	// set digital output mode:
	pinMode(pin_forward_right, DIGITAL_OUT_MODE);
	pinMode(pin_backward_right, DIGITAL_OUT_MODE);
	pinMode(pin_forward_left, DIGITAL_OUT_MODE);
	pinMode(pin_backward_left, DIGITAL_OUT_MODE);

  
	
	// set PWM mode:
	pinMode(pin_PWM_right, PWM_MODE);
	pinMode(pin_PWM_left, PWM_MODE);

  

	// set digital input mode:
	//pinMode(pin_encoder_right, wiringpi.GPIO.INPUT);
	//pullUpDnControl(pin_encoder_right, wiringpi.GPIO.PUD_UP);
	//pinMode(pin_encoder_left, wiringpi.GPIO.INPUT);
	//pullUpDnControl(pin_encoder_left, wiringpi.GPIO.PUD_UP);

	ros::NodeHandle nh;
	ros::Subscriber joy_sub = nh.subscribe<sensor_msgs::Joy>("joy", 10, joyCallback);

	ros::spin();

	return 0;
}
