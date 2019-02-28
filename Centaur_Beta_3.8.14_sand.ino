#include <Centaur.h>

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

unsigned long t;
unsigned long now;
unsigned long ts;
void setup()
{
  while (!Serial);
  SerialUSB.begin(115200);
  SerialUSB.setTimeout(500);

  for (int i = 0, j = 0, k = 0; i < 8; i++)
  {
    if (i < 4)
    {
      pinMode(Buttons[i], OUTPUT);
      digitalWrite(Buttons[i], 0);
    }
    SerialUSB.print(i);
    if (r_pins[i].pwm == NOT_USE)
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

  cent.m0 = cmotorB[0];
  cent.m1 = cmotor[0];
  cent.m2 = cmotor[1];
  cent.m3 = cmotorB[1];
  cent.m4 = cmotorB[2];
  cent.m5 = cmotor[2];
  cent.m6 = cmotor[3];
  cent.m7 = cmotorB[3];

  // cent.m0.info();
  //  cent.m1.info();
  while (millis() < 5100 ) {
    SerialUSB.println(4000 - millis());
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(Buttons[j], HIGH);
    }
    delay(100);
    for (int j = 0; j < 4; j++) {
      digitalWrite(Buttons[j], LOW);
    }
    delay(100);
  }

  int dstate[8] = {LIFT, LIFT, LIFT, LIFT,
                   LIFT , LIFT ,  LIFT, LIFT
                  };
  //  int ttt[8] = {150, 150, 150, 150,
  //                150 , 150 , 150, 150
  //               };
  //
  //  setpos(dstate, 2000);
  //  alpos(ttt);

  while (1) {
        view(1);
        setpos(dstate, 2500);
    //    dstate[0] = 150;
    //    dstate[1] = 150;
    //    dstate[2] = 150;
    //    dstate[3] = 150;
    //
    //    view(2);
    //    setpos(dstate, 2000, 3.0);
    //
    //    view(3);
    //    dstate[0] = 10;
    //    dstate[1] = 10;
    //
    //    setpos(dstate, 2000, 1.5);
    //    view(4);
    //    dstate[1] = 170;
    //    dstate[0] = 5;
    //    setpos(dstate, 2000, 0.5);
    //
    //    dstate[0] = 110;
    //    dstate[1] = 180;
    //    view(5);
    //    setpos(dstate, 2000, 0.5);
    //
    //    dstate[2] = 10;
    //    dstate[3] = 10;
    //
    //    view(6);
    //    setpos(dstate, 2000, 1.0);
    //
    //    view(7);
    //    dstate[2] = 140;
    //    dstate[3] = 5;
    //    setpos(dstate, 2000, 0.5);
    //
    //    view(8);
    //    dstate[2] = 170;
    //    dstate[3] = 80;
    //
    //    setpos(dstate, 2000, 0.5);
    //    cent.reset_I();
    //    view(9);
    //    dstate[4] = 120;
    //    dstate[5] = 120;
    //    dstate[6] = 140;
    //    dstate[7] = 140;
    //    setpos(dstate, 2000, 1.0);
    //
    //    view(10);
    //    dstate[1] = 90;
    //    dstate[2] = 90;
    //    dstate[4] = 60;
    //    dstate[7] = 60;
    //    dstate[5] = 150;
    //    dstate[6] = 150;
    //    setpos(dstate, 3000, 0.3);
    //
    //    view(11);
    //    dstate[0] = 35;
    //    dstate[1] = 45;
    //    dstate[2] = 35;
    //    dstate[3] = 35;
    //    setpos(dstate, 2000 , 0.25);
    //
    //    view(12);
    //    dstate[4] = 30;
    //    dstate[5] = 120;
    //    setpos(dstate, 2000, 1.0);
    //
    //    view(12);
    //    dstate[4] = 45;
    //    dstate[5] = 45;
    //    setpos(dstate, 2000, 0.5);

    //    view(13);
    //    dstate[4] = 95;
    //    dstate[5] = 155;
    //    setpos(dstate, 2000 , 0.5);
    //
    //    view(14);
    //    dstate[4] = 105;
    //    dstate[5] = 165;
    //    setpos(dstate, 2000 , 0.5);
    //
    //
    //    view(15);
    //    dstate[6] = 45;
    //    dstate[7] = 45;
    //    setpos(dstate, 1500 , 1.0);
    //
    //    view(16);
    //
    //    dstate[6] = 145;
    //    dstate[7] = 125;
    //    setpos(dstate, 1500 , 1.0);
    //
    //    view(17);
    //    dstate[4] = 120;
    //    dstate[5] = 120;
    //    dstate[6] = 120;
    //    dstate[7] = 120;
    //    setpos(dstate, 1500 , 1.0);
    //
    //
    //    view(18);
    //    dstate[0] = 120;
    //    dstate[1] = 120;
    //    dstate[2] = 120;
    //    dstate[3] = 120;
    //
    //    setpos(dstate, 2000 , 0.5);
    //    cent.reset_I();
    //    view(19);
    //    dstate[4] = 55;
    //    dstate[5] = 55;
    //    dstate[6] = 55;
    //    dstate[7] = 55;
    //    setpos(dstate, 2000 , 1.0);
    //
    //    view(20);
    //    dstate[0] = 45;
    //    dstate[1] = 45;
    //    setpos(dstate, 2000 , 0.5);
    //
    //
    //    view(21);
    //    dstate[0] = 5;
    //    dstate[1] = 160;
    //    setpos(dstate, 2000 , 0.5);
    //
    //
    //    view(22);
    //    dstate[0] = 100;
    //    setpos(dstate, 2000 , 0.5);
    //
    //    view(23);
    //    dstate[2] = 10;
    //    dstate[3] = 10;
    //    setpos(dstate, 2000 , 0.5);
    //
    //    view(24);
    //    dstate[2] = 140;
    //    dstate[3] = 5;
    //    setpos(dstate, 2000 , 0.5);
    //
    //    view(25);
    //    dstate[2] = 150;
    //    dstate[3] = 100;
    //    setpos(dstate, 2000 , 0.5);
    //
    //
    //    view(26);
    //    dstate[4] = 130;
    //    dstate[5] = 130;
    //    dstate[6] = 140;
    //    dstate[7] = 140;
    //    setpos(dstate, 2000 , 1.0);
    //
    //
    //    view(27);
    //    dstate[1] = 100;
    //    dstate[2] = 100;
    //    dstate[4] = 60;
    //    dstate[7] = 60;
    //    dstate[5] = 150;
    //    dstate[6] = 150;
    //    setpos(dstate, 3000 , 0.3);
    //
    //    view(28);
    //    dstate[1] = 10;
    //    dstate[0] = 10;
    //    setpos(dstate, 2000 , 1.5);
    //
    //    view(29);
    //    dstate[1] = 170;
    //    dstate[0] = 5;
    //    setpos(dstate, 2000 , 0.5);
    //
    //
    //    view(30);
    //    dstate[2] = 10;
    //    dstate[3] = 10;
    //    setpos(dstate, 2000 , 1.5);
    //
    //
    //    view(31);
    //    dstate[2] = 180;
    //    dstate[3] = 5;
    //    setpos(dstate, 2000 , 0.5);
    //
    //
    //    view(32);
    //    dstate[1] = 100;
    //    dstate[0] = 100;
    //    dstate[2] = 100;
    //    dstate[3] = 100;
    //    setpos(dstate, 2000 , 0.5);
    //
    //
    //
    //    view(33);
    //    dstate[4] = 45;
    //    dstate[5] = 45;
    //    setpos(dstate, 2000 , 0.5);
    //
    //
    //
    //    view(34);
    //    dstate[4] = 100;
    //    dstate[5] = 100;
    //    setpos(dstate, 2000 , 0.5);
    //
    //    view(35);
    //    dstate[6] = 45;
    //    dstate[7] = 45;
    //    setpos(dstate, 2000 , 0.5);
    //
    //    view(36);
    //    dstate[6] = 100;
    //    dstate[7] = 100;
    //    setpos(dstate, 2000 , 0.5);

    view(37);
    dstate[1] = 140;
    dstate[0] = 140;
    dstate[2] = 140;
    dstate[3] = 140;
    setpos(dstate, 2000 , 0.5);

    view(38);
    dstate[1] = 45;
    dstate[0] = 45;
    setpos(dstate, 2000 , 0.5);

    view(39);
    dstate[1] = 150;
    dstate[0] = 45;
    setpos(dstate, 2000 , 0.5);
    
    view(40);
    dstate[1] = 170;
    dstate[0] = 120;
    setpos(dstate, 2000 , 0.5);


     view(41);
    dstate[2] = 45;
    dstate[3] = 45;
    setpos(dstate, 2000 , 0.5);

    view(42);
    dstate[2] = 150;
    dstate[3] = 45;
    setpos(dstate, 2000 , 0.5);
    
    view(43);
    dstate[2] = 170;
    dstate[3] = 120;
    setpos(dstate, 2000 , 0.5);
    alpos(dstate, 0.5);
  }
  cent.R_getLastpos();
}


void loop()
{
  now = millis();
  cent.R_still();
  cent.R_drive();
  cent.R_update();
  if (now - ts > 100) {
    ts = now;
    cent.R_show();
  }
}
#define POSTIME 2750
void setpos(int Xdeg[8]) {   //set pos
  cent.R_getLastpos();
  t = millis();
  ts = t;
  now = t;
  while (now - t < POSTIME) {
    now = millis();
    cent.R_Transition(Xdeg);
    cent.R_drive();
    cent.R_update();
    if (now - ts > 50) {
      ts = now;
      cent.i_sum();
      cent.R_show();
    }
    delay(5);
  }
}
void setpos(int Xdeg[8], int interval) {
  cent.R_getLastpos();
  t = millis();
  ts = t;
  now = t;
  while (now - t < interval) {
    now = millis();
    cent.R_Transition(Xdeg);
    cent.R_drive();
    cent.R_update();
    if (now - ts > 50) {
      ts = now;
      cent.i_sum();
      cent.R_show();
    }
    delay(5);
  }
}
void setpos(int Xdeg[8], int interval, double changeRate) {
  cent.R_getLastpos();
  t = millis();
  ts = t;
  now = t;
  while (now - t < interval) {
    now = millis();
    cent.R_Transition(Xdeg, changeRate);
    cent.R_drive();
    cent.R_update();
    if (now - ts > 50) {
      ts = now;
      cent.i_sum();
      cent.R_show();
    }
    delay(5);
  }
}
void setpos(int Xdeg[8], double changeRate) {
  cent.R_getLastpos();
  t = millis();
  ts = t;
  now = t;
  while (now - t < POSTIME) {
    now = millis();
    cent.R_Transition(Xdeg, changeRate);
    cent.R_drive();
    cent.R_update();
    if (now - ts > 50) {
      ts = now;
      cent.i_sum();
      cent.R_show();
    }
    delay(5);
  }
}
void alpos(int Xdeg[8]) { //always keep pose
  cent.R_getLastpos();
  while (true) {
    now = millis();
    cent.R_Transition(Xdeg);
    cent.R_drive();
    cent.R_update();
    if (now - ts > 50) {
      ts = now;
      cent.i_sum();
      cent.R_show();
    }
    delay(5);
  }
}

void alpos(int Xdeg[8], double changeRate) {
  cent.R_getLastpos();
  while (true) {
    now = millis();
    cent.R_Transition(Xdeg, changeRate);
    cent.R_drive();
    cent.R_update();
    if (now - ts > 50) {
      ts = now;
      cent.i_sum();
      cent.R_show();
    }
    delay(5);
  }
}

void view(int x) {
  digitalWrite(Buttons[0], x & 1);
  digitalWrite(Buttons[1], x & 2);
  digitalWrite(Buttons[2], x & 4);
  digitalWrite(Buttons[3], x & 8);
}
