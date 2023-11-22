# PID-Firmware-Implementation

Overview
This repository contains a simple implementation of a Proportional-Integral-Derivative (PID) controller in C++ for an STM32F4 microcontroller.

**Files**
* PID.h: Header file containing the PID class definition and declarations.
* PID.cpp: C++ file implementing the PID class methods.

**Features**
* Proportional, Integral, and Derivative terms for precise control.
* Anti-windup logic to prevent integrator windup.
* Implementation suitable for STM32F4 microcontroller.

**Usage**
* Include the Files:
* Add the PID.h and PID.cpp files to your STM32F4 project.
* Instantiate PID Controller:
* Create an instance of the PID class in your code.

* #include "PID.h"
* PID Pid;

**Configure PID Parameters:**

* Pid.Kp = 0.1;
* Pid.Ki = 0.1;
* Pid.Kd = 0.1;

**Update PID:**
* Call the Update method in your control loop to compute the control output.
* float setpoint =  desired_value;
* float measurement = current_value;
* float output = myPID.Update(setpoint, measurement);

**Additional Notes:**
* The implementation includes anti-windup logic to prevent integrator windup.
* Ensure that the timing parameters (T and tau) are appropriately set for your system.
