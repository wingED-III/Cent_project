#include "C_Motor.h"

#ifndef C_MotorB_h
#define C_MotorB_h

class C_MotorB : public C_Motor
{
  public:
    C_MotorB();
    C_MotorB(uint8_t N1, uint8_t IN2, uint8_t Vr);
    void driveMotor();
    void setupPin();
};

#endif
