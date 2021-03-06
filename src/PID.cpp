#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID(double Kp_, double Ki_, double Kd_) : Kp(Kp_), Ki(Ki_), Kd(Kd_) {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  //return 0.0;  // TODO: Add your total error calc here!
  double steer = -Kp * p_error - Kd * d_error - Ki * i_error;
  if (steer < -1) {
    steer = -1;
  }
  if (steer > 1) {
    steer = 1;
  }
  return steer; 
}