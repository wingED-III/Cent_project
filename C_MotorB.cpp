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

  Serial.print("in1: ");
  Serial.print(IN1);
  Serial.print(" |in2: ");
  Serial.print(IN2);
  Serial.print(" |vr: ");
  Serial.println(Vr_pin);
}

void C_MotorB::driveMotor()
{
  uint8_t *pn1;
  uint8_t *pn2;
  double *ppwm;

  pn1 = &IN1;
  pn2 = &IN2;
  ppwm = &pwm;

  if (!(diffError == 0 && error == 0))
  {
    {
      if (*ppwm > 0)
      {
        Serial.print(" |PWM++  ");

        if (*ppwm > MAX_SPEED)
        {
          *ppwm = MAX_SPEED;
        }
        analogWrite(*pn1, *ppwm);
        analogWrite(*pn2, 0);
      }
      // else if (*ppwm == 0)
      // {
      //     analogWrite(*pn1, 1);
      //     analogWrite(*pn2, 1);
      // }
      else
      {
        *ppwm = abs(*ppwm);
        Serial.print(" |PWM--  ");
        if (*ppwm > MAX_SPEED)
        {
          *ppwm = MAX_SPEED;
        }
        analogWrite(*pn1, 0);
        analogWrite(*pn2, *ppwm);
      }
    }
  }
  // else
  // {
  //     analogWrite(*pn1, 255);
  //     analogWrite(*pn2, 255);
  // }
  //  Serial.print("in1: ");
  //  Serial.print(*pn1);
  //  Serial.print(" |in2: ");
  //  Serial.print(*pn2);

  Serial.print(" |Set point: ");
  Serial.print(input);
  Serial.print(" |Analog: ");
  Serial.print(vr_value);
  Serial.print(" |error: ");
  Serial.print(error);
  Serial.print(" |pwm: ");
  Serial.println(*ppwm);
}
