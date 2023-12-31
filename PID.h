#ifndef PID_PID_H_
#define PID_PID_H_

#include "stm32f4xx_hal.h"

class PID
{
	public:
	PID();
	float Update(float setpoint, float measurement);
	
	public:
	float Kp;
	float Ki;
	float Kd;
	float limMin;
	float limMax;
	float T;
	float tau;

	private:
	float limMinInt = -255;
	float limMaxInt = 255;
	float integrator;
	float prevError;
	float differentiator;
	float prevMeasurement;
	float out;
};

#endif 
