#include"functionM.h"
#include "constantM.h"

double Mmap(int x, double oldL, double oldH , double newH, double newL) {
  double range = (newH - newL) / (oldH - oldL);
  return ((x - oldL) * range) + newL;
}

double ana2Deg(int x) {
  const double nr = 1023;
  const double oldR = 360;
  return x * (oldR / nr);
}


double Deg2ana(int x) {
  const double nr = 1023;
  const double oldR = 360;
  return x * (nr / oldR);
}

double calError(double expect, double realVal) {
  double rt = expect - realVal;
  if (abs(rt) < ACCEPT_ERROR)
    return 0;
  else
    return rt;
}
