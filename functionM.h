#include "Arduino.h"
#include "constantM.h"

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

const double Ksets[8] = {4, 4, 4, 4,
                         4, 4, 4, 4};