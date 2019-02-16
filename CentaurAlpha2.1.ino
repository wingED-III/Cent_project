#include "functionM.h"

Pins r_pins[8] = {
  {6, 7, 99, A0},//B4
  {8, 9, 99, A1},//B4
  {11, 12, 99, A2},
  {11, 12, 99, A3},
  {11, 12, 99, A4},
  {11, 12, 99, A5},
  {11, 12, 99, A6},
  {11, 12, 99, A7},
};

int Ksets[8] = {40, 40, 40, 40,
                40, 40, 40, 40
               };

C_Motor cmotor[4];
C_MotorB cmotorB[4] ;


void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(500);
  for (int i = 0; i < 4; i++)
  {
    cmotorB [i] = C_MotorB(r_pins[i].in1,  r_pins[i].in2, r_pins[i].vr);
    cmotorB[i].setupPin();
    cmotorB[i].setConstant(Ksets[i]);
  }
  for (int i = 4; i < 8; i++)
  {
    Serial.print(i);
    cmotor[i] = C_Motor(r_pins[i].in1, r_pins[i].in2, r_pins[i].pwm, r_pins[i].vr);
    cmotor[i].setupPin();
    cmotor[i].setConstant(Ksets[i]);
  }

  delay(2000);
}

double input[2] = {ANALOG_START, ANALOG_START};

int tmp = ANALOG_START;
int beta[10] = {20, 45, 45, 70, 40, 50, 35, 25, 20, 20},
               alpha[10] = {20, 20, 30, 40, 70, 50, 50, 60, 50, 20};

void loop()
{
  if (Serial.available() > 0) {
    tmp = Serial.parseInt();
    if (tmp > 0) {
      if (tmp < MIN_DEGREE) {
        tmp = MIN_DEGREE;
      }
      else if (tmp > LIMITED_DEGREE) {
        tmp = LIMITED_DEGREE;
      }

      input[0] = Deg2ana(tmp);
    }
    else {
      tmp = abs(tmp);
      if (tmp < MIN_DEGREE) {
        tmp = MIN_DEGREE;
      }
      else if (tmp > LIMITED_DEGREE) {
        tmp = LIMITED_DEGREE;
      }
      input[1] = Deg2ana(tmp);
    }
  }

  //  cmotor[0].calculate(500);
  //  cmotor[0].driveMotor();
  //  cmotor[0].m_update();
  //
  //  cmotorB[0].calculate(500);
  //  cmotorB[0].driveMotor();
  //  cmotorB[0].m_update();

  for (int i = 0; i < 2; i++)
  {
    cmotorB[i].calculate(input[i]);
    Serial.print(i);   Serial.print(" ");
    Serial.print(" | input raw: ");   Serial.print(input[i]);
    Serial.print(" | degree ");   Serial.print(tmp);
    Serial.print(" ");
    cmotorB[i].driveMotor();
    cmotorB[i].m_update();
  }

}
