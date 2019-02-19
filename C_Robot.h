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
  C_Robot();
  void R_Cal(int a, int b, int c, int d, int e, int f, int g, int h);
  void R_drive();
  void R_update();
};

#endif