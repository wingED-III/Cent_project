#include "Arduino.h"
#include "constantM.h"
#include "C_Motor.h"
#include "C_MotorB.h"

double Mmap(int x, double oldL, double oldH, double newH, double newL);
double ana2Deg(int x);
double Deg2ana(int x);
double calError(double expect, double realVal);

struct Pins
{
  uint8_t in1;
  uint8_t in2;
  uint8_t pwm;
  uint8_t vr;
};

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
  C_Robot(){};
};


const int Ksets[8] = {20, 20, 80, 80,
                10, 40, 40, 20};