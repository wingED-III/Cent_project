/*
  version 0
  P Tunning
*/
#include "Arduino.h"

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
    double diffError;
    double input = ANALOG_START;
    double preError = 0;
    double vr_value;
    double error = 0;
    double pwm = 0;

  public:
    C_Motor();
    C_Motor(uint8_t N1, uint8_t IN2, uint8_t EN, uint8_t Vr);
    void setupPin();
    void setConstant(double Kp);
    void calculate(double input);
    void driveMotor();
    void m_update();
};

#endif
