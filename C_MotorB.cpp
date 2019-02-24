#include "functionM.h"

C_MotorB::C_MotorB()
{
}

C_MotorB::C_MotorB(uint8_t I1, uint8_t I2, uint8_t V)
{
  IN1 = I1;
  IN2 = I2;
  Vr_pin = V;
}

void C_MotorB::setupPin()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  SerialUSB.print("in1: ");
  SerialUSB.print(IN1);
  SerialUSB.print(" |in2: ");
  SerialUSB.print(IN2);
  SerialUSB.print(" |vr: ");
  SerialUSB.println(Vr_pin);
}

void C_MotorB::driveMotor()
{
  uint8_t *pn1;
  uint8_t *pn2;
  double *ppwm;

  pn1 = &IN1;
  pn2 = &IN2;
  ppwm = &pwm;
  int tp = this->pwm;

  //if (!(diffError == 0 && error == 0))
  // {
  if (*ppwm > 0)
  {
    tp += BASE_POWER;
    //SerialUSB.print(" |PWM++  ");
    if (tp > MAX_SPEED)
      tp = MAX_SPEED;
    if (*ppwm > MAX_SPEED)
    {
      *ppwm = MAX_SPEED;
    }
    analogWrite(*pn1, tp);
    analogWrite(*pn2, 0);
  }
  else
  {
    *ppwm = abs(*ppwm); //+BASE_POWER;
    tp = abs(tp) + BASE_POWER;
    //SerialUSB.print(" |PWM--  ");
    if (*ppwm > MAX_SPEED)
    {
      *ppwm = MAX_SPEED;
    }
    if (tp > MAX_SPEED)
      tp = MAX_SPEED;
    analogWrite(*pn1, 0);
    analogWrite(*pn2, tp);
  }
  // }

  // SerialUSB.print(" |Set degree: ");
  // SerialUSB.print(ana2Deg(input));
  // SerialUSB.print(" |Degree: ");
  // SerialUSB.print(ana2Deg(vr_value));
  // SerialUSB.print(" |error: ");
  // SerialUSB.print(error);
  // SerialUSB.print(" |pwm: ");
  // SerialUSB.println(*ppwm);
}

void C_MotorB::info()
{
  SerialUSB.print("This is B4 version.Analog pin : ");
  SerialUSB.println(this->Vr_pin);
}
