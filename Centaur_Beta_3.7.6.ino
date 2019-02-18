#include <functionM.h>
#include <Scheduler.h>

Pins r_pins[8] = {
  {5, 4, NOT_USE, A7}, //B4
  {24, 22, 2, A6},     //B2
  {36, 34, 12, A1},
  {11, 10, NOT_USE, A0},
  {7, 6, NOT_USE, A5},
  {28, 26, 3, A4},
  {30, 32, 13, A3},
  {9, 8, NOT_USE, A2},
};


C_Motor cmotor[4];
C_MotorB cmotorB[4];

int Buttons[4] = {37, 35, 33, 31};

C_Robot cent = C_Robot();

void setup()
{
  while (!Serial);
  SerialUSB.begin(9600);
  SerialUSB.setTimeout(500);

  for (int i = 0, j = 0, k = 0; i < 8; i++)
  {
    if (i < 4)
    {
      pinMode(Buttons[i], OUTPUT);
      digitalWrite(Buttons[i], 0);
    }
    SerialUSB.print(i);
    if (r_pins[i].pwm == 99)
    {
      cmotorB[j] = C_MotorB(r_pins[i].in1, r_pins[i].in2, r_pins[i].vr);
      cmotorB[j].setupPin();
      cmotorB[j].setConstant(Ksets[i]);
      j++;
    }
    else
    {

      cmotor[k] = C_Motor(r_pins[i].in1, r_pins[i].in2, r_pins[i].pwm, r_pins[i].vr);
      cmotor[k].setupPin();
      cmotor[k].setConstant(Ksets[i]);
      k++;
    }
  }
  //  Scheduler.startLoop(loop2);
  //  Scheduler.startLoop(loop3);
  //  Scheduler.startLoop(loop4);

  cent.m0 = cmotorB[0];
  cent.m1 = cmotor[0];
  cent.m2 = cmotor[1];
  cent.m3 = cmotorB[1];
  cent.m4 = cmotorB[2];
  cent.m5 = cmotor[2];
  cent.m6 = cmotor[3];
  cent.m7 = cmotorB[3];

  cent.m0.info();
  cent.m1.info();

  delay(2000);
}
double x = 45;
int posIn = Deg2ana(x);
int posOut = Deg2ana(x);
//int beta[10] = {20, 45, 45, 70, 40, 50, 35, 25, 20, 20},
//               alpha[10] = {20, 20, 30, 40, 70, 50, 50, 60, 50, 20};
int beta[10] = {90, 45, 90, 45, 90, 45, 90, 45, 90, 45},
               alpha[10] = {90, 45, 90, 45, 90, 45, 90, 45, 90, 45};

unsigned long t = millis();
void loop()
{
  for (x = 45; x <= 90; x += 0.1)
  {
    int y = Deg2ana(x);
    cent.m0.calculate(y);
    cent.m1.calculate(y);
    cent.m2.calculate(y);
    cent.m3.calculate(y);
    cent.m4.calculate(y);
    cent.m5.calculate(y);
    cent.m6.calculate(y);
    cent.m7.calculate(y);

    SerialUSB.print("No 0 ");
    cent.m0.driveMotor();
    SerialUSB.print("No 1 ");
    cent.m1.driveMotor();
    SerialUSB.print("No 2 ");
    cent.m2.driveMotor();
    SerialUSB.print("No 3 ");
    cent.m3.driveMotor();
    SerialUSB.print("No 4 ");
    cent.m4.driveMotor();
    SerialUSB.print("No 5 ");
    cent.m5.driveMotor();
    SerialUSB.print("No 6 ");
    cent.m6.driveMotor();
    SerialUSB.print("No 7 ");
    cent.m7.driveMotor();

    if (cent.m0.getPwm() > 25) {
      digitalWrite(Buttons[0], HIGH);
    }
    else {
      digitalWrite(Buttons[0], 0);
    }
    if (cent.m1.getPwm() > 25) {
      digitalWrite(Buttons[1], HIGH);
    }
    else {
      digitalWrite(Buttons[1], 0);
    }
    if (cent.m4.getPwm() > 25) {
      digitalWrite(Buttons[2], HIGH);
    }
    else {
      digitalWrite(Buttons[2], 0);
    }
    if (cent.m5.getPwm() > 25) {
      digitalWrite(Buttons[3], HIGH);
    }
    else {
      digitalWrite(Buttons[3], 0);
    }

    cent.m0.m_update();
    cent.m1.m_update();
    cent.m2.m_update();
    cent.m3.m_update();
    cent.m4.m_update();
    cent.m5.m_update();
    cent.m6.m_update();
    cent.m7.m_update();
    SerialUSB.println(x);
    delay(5);
  }
  for (x = 90; x > 45; x -= 0.1)
  {
    int y = Deg2ana(x);
    cent.m0.calculate(y);
    cent.m1.calculate(y);
    cent.m2.calculate(y);
    cent.m3.calculate(y);
    cent.m4.calculate(y);
    cent.m5.calculate(y);
    cent.m6.calculate(y);
    cent.m7.calculate(y);

    SerialUSB.print("No 0 ");
    cent.m0.driveMotor();
    SerialUSB.print("No 1 ");
    cent.m1.driveMotor();
    SerialUSB.print("No 2 ");
    cent.m2.driveMotor();
    SerialUSB.print("No 3 ");
    cent.m3.driveMotor();
    SerialUSB.print("No 4 ");
    cent.m4.driveMotor();
    SerialUSB.print("No 5 ");
    cent.m5.driveMotor();
    SerialUSB.print("No 6 ");
    cent.m6.driveMotor();
    SerialUSB.print("No 7 ");
    cent.m7.driveMotor();

    if (cent.m0.getPwm() > 25) {
      digitalWrite(Buttons[0], HIGH);
    }
    else {
      digitalWrite(Buttons[0], 0);
    }
    if (cent.m1.getPwm() > 25) {
      digitalWrite(Buttons[1], HIGH);
    }
    else {
      digitalWrite(Buttons[1], 0);
    }
    if (cent.m4.getPwm() > 25) {
      digitalWrite(Buttons[2], HIGH);
    }
    else {
      digitalWrite(Buttons[2], 0);
    }
    if (cent.m5.getPwm() > 25) {
      digitalWrite(Buttons[3], HIGH);
    }
    else {
      digitalWrite(Buttons[3], 0);
    }

    cent.m0.m_update();
    cent.m1.m_update();
    cent.m2.m_update();
    cent.m3.m_update();
    cent.m4.m_update();
    cent.m5.m_update();
    cent.m6.m_update();
    cent.m7.m_update();
    SerialUSB.println(x);
    delay(5);
  }
}
