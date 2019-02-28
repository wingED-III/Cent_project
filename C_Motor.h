#include "functionM.h"

#ifndef C_Motor_h
#define C_Motor_h

class C_Motor
{
protected:
  uint8_t IN1;
  uint8_t IN2;
  uint8_t EN;
  uint8_t Vr_pin;

  double Kp;
  double Kd = 0.000625;
  double Ki = 0.03;
  double sumErr = 0;
  double input = ANALOG_START;
  double preError = 0;
  double vr_value = 255;
  double error = 0;
  double pwm = 0;
  int offset = 0;

public:
  C_Motor();
  C_Motor(uint8_t N1, uint8_t IN2, uint8_t EN, uint8_t Vr);
  void setupPin();
  void setConstant(double Kp);
  void calculate(double input);
  void calD(double degree);
  void driveMotor();
  void m_update();
  void info();
  double getPwm();
  void setPwm(double x);
  int getAna();
  double getDeg();
  void setOffset(int x);
  void show();
  void reset_I();
  void sum();
};

#endif
