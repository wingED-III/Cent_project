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
  pinMode(this->Vr_pin, INPUT);

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

void C_Motor::calD(double degree)
{
  this->calculate(Deg2ana(degree));
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
  //this->diffError = this->error - this->preError;

  this->pwm = (this->Kp * Mmap(this->error, -1023, 1023, 255, -255)) - (this->preError * this->Kd) + (this->sumErr * Ki);
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
  //if (!(this->diffError == 0 && this->error == 0))
  //{
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
  // }
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

double C_Motor::getPwm()
{
  return this->pwm;
}

double C_Motor::getDeg()
{
  this->vr_value = analogRead(this->Vr_pin);

  double x = ana2Deg(this->vr_value);
  // SerialUSB.print(x);
  // SerialUSB.print("  ");
  // SerialUSB.println(this->vr_value);
  return x;
}

void C_Motor::show()
{
  SerialUSB.print(" | I: ");
  SerialUSB.print(this->sumErr);
  SerialUSB.print(" |Set degree: ");
  SerialUSB.print(ana2Deg(input));
  SerialUSB.print(" |degree: ");
  SerialUSB.print(ana2Deg(vr_value));
  SerialUSB.print(" |error: ");
  SerialUSB.print(error);
  SerialUSB.print(" |pwm: ");
  SerialUSB.println(this->pwm);
}

int C_Motor::getAna()
{
  this->vr_value = analogRead(this->Vr_pin);
  //SerialUSB.println(this->vr_value);
  return analogRead(this->vr_value);
}

void C_Motor::sum()
{
  this->sumErr = this->sumErr + this->error;
  if (this->sumErr > MAX_SUM)
  {
    this->sumErr = MAX_SUM;
  }
  else if (this->sumErr < -MAX_SUM)
  {
    this->sumErr = -MAX_SUM;
  }
}

void C_Motor::setPwm(double x){
  this->pwm = x;
}