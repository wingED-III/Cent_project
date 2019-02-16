#include "functionM.h"

C_Motor::C_Motor(uint8_t IN1, uint8_t IN2, uint8_t EN, uint8_t Vr)
{
  this->IN1 = IN1;
  this->IN2 = IN2;
  this->EN = EN;
  this->Vr_pin = Vr;
}

C_Motor::C_Motor()
{
}
void C_Motor::setupPin()
{
  pinMode(this->IN1, OUTPUT);
  pinMode(this->IN2, OUTPUT);
  pinMode(this->EN, OUTPUT);

  Serial.print("in1: ");
  Serial.print(this->IN1);
  Serial.print(" |in2: ");
  Serial.print(this->IN2);
  Serial.print(" |en: ");
  Serial.print(this->EN);
  Serial.print(" |vr: ");
  Serial.println(this->Vr_pin);
}

void C_Motor::setConstant(double Kp)
{
  this->Kp = Kp;
}

void C_Motor::calculate(double input) //input in analog range
{
  this->vr_value = analogRead(this->Vr_pin);
//
//  if (input > 900) // limit
//    input = 900;
//  else if (input < 200)
//    input = 200;

  this->input = input;
  this->error = calError(this->input, this->vr_value);
  this->diffError = this->error - this->preError;

  this->pwm = this->Kp * Mmap(this->error, -1023, 1023, MAX_SPEED, -MAX_SPEED);
}

void C_Motor::driveMotor()
{
  uint8_t *pn1;
  uint8_t *pn2;
  double *ppwm;

  pn1 = &this->IN1;
  pn2 = &this->IN2;
  ppwm = &this->pwm;

  if (!(this->diffError == 0 && this->error == 0))
  {
    {
      if (*ppwm < 0)
      {
        *ppwm = abs(*ppwm);
        if (*ppwm > MAX_SPEED)
        {
          *ppwm = MAX_SPEED;
        }
        digitalWrite(*pn1, 1);
        digitalWrite(*pn2, 0);
      }
      // else if (*ppwm == 0)
      // {
      //   digitalWrite(*pn1, 1);
      //   digitalWrite(*pn2, 1);
      // }
      else
      {
        if (*ppwm > MAX_SPEED)
        {
          *ppwm = MAX_SPEED;
        }
        digitalWrite(*pn1, 0);
        digitalWrite(*pn2, 1);
      }
      analogWrite(this->EN, *ppwm);
    }
  }
  // else
  // {
  //   digitalWrite(*pn1, 1);
  //   digitalWrite(*pn2, 1);
  // }
  Serial.print("in1: ");
  Serial.print(*pn1);
  Serial.print(" |in2: ");
  Serial.print(*pn2);
  Serial.print(" |pwm: ");
  Serial.println(*ppwm);
}

void C_Motor::m_update()
{
  this->preError = this->error;
}
