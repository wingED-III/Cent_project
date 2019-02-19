#include "functionM.h"

C_Robot::C_Robot()
{
}

void C_Robot::R_Cal(int a, int b, int c, int d, int e, int f, int g, int h)
{
  this->m0.calculate(a);
  this->m1.calculate(b);
  this->m2.calculate(c);
  this->m3.calculate(d);
  this->m4.calculate(e);
  this->m5.calculate(f);
  this->m6.calculate(g);
  this->m7.calculate(h);
}
void C_Robot::R_drive()
{
    SerialUSB.print("No 0 ");
    this->m0.driveMotor();
    SerialUSB.print("No 1 ");
    this->m1.driveMotor();
    SerialUSB.print("No 2 ");
    this->m2.driveMotor();
    SerialUSB.print("No 3 ");
    this->m3.driveMotor();
    SerialUSB.print("No 4 ");
    this->m4.driveMotor();
    SerialUSB.print("No 5 ");
    this->m5.driveMotor();
    SerialUSB.print("No 6 ");
    this->m6.driveMotor();
    SerialUSB.print("No 7 ");
    this->m7.driveMotor();
}
void C_Robot::R_update()
{
    this->m0.m_update();
    this->m1.m_update();
    this->m2.m_update();
    this->m3.m_update();
    this->m4.m_update();
    this->m5.m_update();
    this->m6.m_update();
    this->m7.m_update();
}