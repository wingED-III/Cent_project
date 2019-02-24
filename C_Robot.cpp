#include "functionM.h"

C_Robot::C_Robot()
{
}

void C_Robot::R_calD(int a, int b, int c, int d, int e, int f, int g, int h)
{
  this->R_Cal(Deg2ana(a), Deg2ana(b), Deg2ana(c), Deg2ana(d), Deg2ana(e), Deg2ana(f), Deg2ana(g), Deg2ana(h));
}

void C_Robot::R_Cal(double a, double b, double c, double d, double e, double f, double g, double h)
{
  //SerialUSB.println(a);
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

  this->m0.driveMotor();
  this->m1.driveMotor();
  this->m2.driveMotor();
  this->m3.driveMotor();
  this->m4.driveMotor();
  this->m5.driveMotor();
  this->m6.driveMotor();
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

void C_Robot::R_getLastpos()
{
  // for (uint8_t i = 0; i < 8; i++)
  // {
  //   d[i] = 90;
  //   SerialUSB.print(d[i]);
  //   SerialUSB.print("*");
  // }
  this->d[0] = ana2Deg(analogRead(A7));
  this->d[1] = this->m1.getDeg();
  this->d[2] = this->m2.getDeg();
  this->d[3] = this->m3.getDeg();
  this->d[4] = this->m4.getDeg();
  this->d[5] = this->m5.getDeg();
  this->d[6] = this->m6.getDeg();
  this->d[7] = this->m7.getDeg();
  // for (uint8_t i = 0; i < 8; i++)
  // {
  //   SerialUSB.print(d[i]);
  //   SerialUSB.print("-");
  // }
  //SerialUSB.println();
}
void C_Robot::R_Transition(int target[8])
{

  for (uint8_t i = 0; i < 8; i++)
  {
    // *p = target[i];
    // *p1 = this->d[i];
    if (target[i] > this->d[i])
    {
      this->d[i] += CHANGE_RATE;
    }
    else if (target[i] < this->d[i])
    {
      this->d[i] -= CHANGE_RATE_DOWN;
    }
  }
  for (uint8_t i = 0; i < 8; i++)
    // {
    //   SerialUSB.print(d[i]);
    //   SerialUSB.print(" ");
    // }
    // SerialUSB.println();
    //SerialUSB.println(target[0]);
    this->R_calD(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
}

void C_Robot::R_Transition(int target[8],double ch_rate)
{

  for (uint8_t i = 0; i < 8; i++)
  {
    // *p = target[i];
    // *p1 = this->d[i];
    if (target[i] > this->d[i])
    {
      this->d[i] += ch_rate;
    }
    else if (target[i] < this->d[i])
    {
      this->d[i] -= ch_rate;
    }
  }
  for (uint8_t i = 0; i < 8; i++)
    // {
    //   SerialUSB.print(d[i]);
    //   SerialUSB.print(" ");
    // }
    // SerialUSB.println();
    //SerialUSB.println(target[0]);
    this->R_calD(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
}
//overload  double
void C_Robot::R_Transition(double target[8])
{
  double *p;
  double *p1;
  for (uint8_t i = 0; i < 8; i++)
  {
    *p = target[i];
    *p1 = this->d[i];
    if (*p > *p1)
    {
      *p1 += CHANGE_RATE;
    }
    else if (*p < *p1)
    {
      *p1 -= CHANGE_RATE;
    }
  }
  this->R_calD(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
}
void C_Robot::R_still()
{
  this->R_Transition(this->d);
}

void C_Robot::R_show()
{
  SerialUSB.print("No 0 ");
  this->m0.show();
  SerialUSB.print("No 1 ");
  this->m1.show();
  SerialUSB.print("No 2 ");
  this->m2.show();
  SerialUSB.print("No 3 ");
  this->m3.show();
  SerialUSB.print("No 4 ");
  this->m4.show();
  SerialUSB.print("No 5 ");
  this->m5.show();
  SerialUSB.print("No 6 ");
  this->m6.show();
  SerialUSB.print("No 7 ");
  this->m7.show();
}

void C_Robot::i_sum()
{
  this->m0.sum();
  this->m1.sum();
  this->m2.sum();
  this->m3.sum();
  this->m4.sum();
  this->m5.sum();
  this->m6.sum();
  this->m7.sum();
}
