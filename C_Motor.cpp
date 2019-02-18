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

  SerialUSB.print("in1: ");
  SerialUSB.print(this->IN1);
  SerialUSB.print(" |in2: ");
  SerialUSB.print(this->IN2);
  SerialUSB.print(" |en: ");
  SerialUSB.print(this->EN);
  SerialUSB.print(" |vr: ");
  SerialUSB.println(this->Vr_pin);
}

void C_Motor::setConstant(double Kp)
{
  this->Kp = Kp;
}

void C_Motor::calculate(double input) //input in analog range
{
  this->vr_value = analogRead(this->Vr_pin);

  if (input > ANALOG_LIMIT_MAX) // limit
    input = ANALOG_LIMIT_MAX;
  else if (input < ANALOG_LIMIT_MIN)
    input = ANALOG_LIMIT_MIN;

  this->input = input;
  this->error = calError(this->input, this->vr_value);
  this->diffError = this->error - this->preError;

  this->pwm = (this->Kp * Mmap(this->error, -1023, 1023, MAX_SPEED, -MAX_SPEED));
}

void C_Motor::driveMotor()
{
  uint8_t *pn1;
  uint8_t *pn2;
  double *ppwm;

  pn1 = &this->IN1;
  pn2 = &this->IN2;
  ppwm = &this->pwm;
  int tp = this->pwm;
  if (!(this->diffError == 0 && this->error == 0))
  {
    {
      if (*ppwm < 0)
      {
        *ppwm = abs(*ppwm); //+ BASE_POWER;
        tp = abs(tp) + BASE_POWER_A;
        if (tp > MAX_SPEED)
          tp = MAX_SPEED;

        if (*ppwm > MAX_SPEED)
        {
          *ppwm = MAX_SPEED;
        }
        digitalWrite(*pn1, 1);
        digitalWrite(*pn2, 0);
      }
      // else if (*ppwm == 0)
      // {
      //   digitalWrite(*pn1, 0);
      //   digitalWrite(*pn2, 0);
      //   analogWrite(this->EN, 0);
      // }
      else
      {
       // *ppwm += BASE_POWER;
        if (*ppwm > MAX_SPEED)
        {
          *ppwm = MAX_SPEED;
        }

        tp += BASE_POWER_A;
        if (tp > MAX_SPEED)
          tp = MAX_SPEED;

        digitalWrite(*pn1, 0);
        digitalWrite(*pn2, 1);
      }
      //analogWrite(this->EN, *ppwm);
      analogWrite(this->EN, tp);
    }
  }
  // if (this->vr_value > ANALOG_LIMIT_MAX || this->vr_value < ANALOG_LIMIT_MIN)
  // {

  //   digitalWrite(*pn1, 0);
  //   digitalWrite(*pn2, 0);
  //   analogWrite(this->EN, 0);
  // }
  // else
  // {
  //   digitalWrite(*pn1, 1);
  //   digitalWrite(*pn2, 1);
  // }
  // SerialUSB.print("in1: ");
  // SerialUSB.print(*pn1);
  // SerialUSB.print(" |in2: ");
  // SerialUSB.print(*pn2);
  SerialUSB.print(" |Set point: ");
  SerialUSB.print(input);
  SerialUSB.print(" |Analog: ");
  SerialUSB.print(vr_value);
  SerialUSB.print(" |error: ");
  SerialUSB.print(error);
  SerialUSB.print(" |pwm: ");
  SerialUSB.println(this->pwm);
}

void C_Motor::m_update()
{
  this->preError = this->error;
}

void C_Motor::info()
{
  SerialUSB.print("This is B2 version.Analog pin : ");
  SerialUSB.println(this->Vr_pin);
}

double C_Motor::getPwm(){
  return this->pwm;
}