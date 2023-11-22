#include "PID.h"

PID::PID() 
{
	integrator = 0.0f;
	prevError = 0.0f;
	differentiator = 0.0f;
	prevMeasurement = 0.0f;
	out = 0.0f;
}

float PID::Update(float setpoint, float measurement) 
{
	float error = setpoint - measurement;

	float proportional = Kp * error;

	integrator = integrator + 0.5f * Ki * T * (error + prevError);

	if(integrator > limMaxInt) 
	{
		integrator = limMaxInt;
	}
	else if(integrator < limMinInt) 
	{
		integrator = limMinInt;
	}

   differentiator = -(2.0f * Kd * (measurement - prevMeasurement)
           + (2.0f * tau - T) * differentiator)
           / (2.0f * tau + T);

   out = proportional + integrator + differentiator;

   if(out > limMax) 
   {
	   out = limMax;
   }
   else if(out < limMin) 
   {
	   out = limMin;
   }

  prevError = error;

  prevError = measurement;

  return out;
}
