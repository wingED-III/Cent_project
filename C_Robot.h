#include "Arduino.h"

#ifndef C_Robot_h
#define C_Robot_h

class C_Robot
{
public:
  C_MotorB m0;
  C_Motor m1;
  C_Motor m2;
  C_MotorB m3;
  C_MotorB m4;
  C_Motor m5;
  C_Motor m6;
  C_MotorB m7;
  double d[8];

  C_Robot();
  void R_calD(int a, int b, int c, int d, int e, int f, int g, int h);
  void R_Cal(double a, double b, double c, double d, double e, double f, double g, double h);
  void R_getLastpos();
  void R_drive();
  void R_update();
  void R_Transition(int target[8]);
  void R_Transition(int target[8],double ch_rate);
  void R_Transition(double target[8]);
  void R_still();
  void R_show();
  void i_sum();
};

#endif