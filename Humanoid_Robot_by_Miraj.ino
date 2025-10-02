#include <Servo.h>
Servo head;
Servo rh1;
Servo rh2;
Servo rh3;
Servo rl1;
Servo rl2;
Servo rl3;
Servo rl4;
Servo rl5;
Servo lh1;
Servo lh2;
Servo lh3;
Servo ll1;
Servo ll2;
Servo ll3;
Servo ll4;
Servo ll5;

String voice;


void setup() {
  Serial.begin(9600);
  Serial.println("GPIO test!");

  head.attach(28);
  rh1.attach(30);
  rh2.attach(31);
  rh3.attach(32);
  rl1.attach(33);
  rl2.attach(34);
  rl3.attach(35);
  rl4.attach(36);
  rl5.attach(37);
  lh1.attach(38);
  lh2.attach(39);
  lh3.attach(40);
  ll1.attach(41);
  ll2.attach(42);
  ll3.attach(43);
  ll4.attach(44);
  ll5.attach(45);
  stand_straight();
}

void loop() {
  while (Serial.available()) {
    delay(10);
    char c = Serial.read();
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println(voice);
    if ((voice == "stop") or (voice == "stand")) {
      stand_straight();
    }
    if (voice == "say hi") {
      say_hi();
    }
    if (voice == "shake hand") {
      shake_hand();
    }
    if (voice == "hands up") {
      hands_up();
    }
    if (voice == "hands down") {
      hands_down();
    }
    if (voice == "right bicep") {
      right_bicep();
    }
    if (voice == "left bicep") {
      left_bicep();
    }
    if (voice == "double biceps") {
      double_biceps();
    }
    if (voice == "bow") {
      do_bow();
    }
    if (voice == "sit down") {
      sit_down();
    }
    if (voice == "stand up") {
      stand_up();
    }
    if (voice == "dab") {
      do_dab();
    }
  }
  voice = "";
}

//********************stand straight********************//
void stand_straight() {
  head.write(90);
  rh1.write(0);
  rh2.write(0);
  rh3.write(20);
  rl1.write(90);
  rl2.write(150);
  rl3.write(30);
  rl4.write(30);
  rl5.write(90);

  lh1.write(180);
  lh2.write(180);
  lh3.write(160);
  ll1.write(90);
  ll2.write(30);
  ll3.write(150);
  ll4.write(150);
  ll5.write(90);
}

//********************say hi********************//
void say_hi() {
  for (int i = 0; i <= 180; i++) {
    rh1.write(0 + i);
    if (i <= 90) {
      rh2.write(0 + i);
    }
    if (i <= 40) {
      rh3.write(20 + i);
    }
    delay(15);
  }
  for (int i = 1; i <= 3; i++) {
    for (int i = 0; i <= 60; i++) {
      rh3.write(60 + i);
      delay(15);
    }
    for (int i = 0; i <= 60; i++) {
      rh3.write(120 - i);
      delay(15);
    }
  }
  for (int i = 0; i <= 180; i++) {
    rh1.write(180 - i);
    if (i <= 90) {
      rh2.write(90 - i);
    }
    if (i <= 40) {
      rh3.write(60 - i);
    }
    delay(15);
  }
}

//********************shake hand********************//
void shake_hand() {
  for (int i = 0; i <= 40; i++) {
    rh1.write(0 + i);
    delay(10);
  }
  for (int i = 0; i <= 3; i++) {
    for (int i = 0; i <= 30; i++) {
      rh1.write(40 + i);
      delay(15);
    }
    for (int i = 0; i <= 30; i++) {
      rh1.write(70 - i);
      delay(15);
    }
  }
  for (int i = 0; i <= 40; i++) {
    rh1.write(40 - i);
    delay(10);
  }
}

//********************hands up********************//
void hands_up() {
  for (int i = 0; i <= 180; i++) {
    rh1.write(0 + i);
    lh1.write(180 - i);
    delay(15);
  }
}

//********************hands down********************//
void hands_down() {
  for (int i = 0; i <= 180; i++) {
    rh1.write(180 - i);
    lh1.write(0 + i);
    delay(15);
  }
}

//********************right bicep********************//
void right_bicep() {
  for (int i = 0; i <= 180; i++) {
    rh1.write(0 + i);
    if (i <= 90) {
      rh2.write(0 + i);
    }
    if (i <= 60) {
      head.write(90 - i);
    }
    delay(15);
  }
  for (int i = 0; i <= 120; i++) {
    rh3.write(20 + i);
    delay(15);
  }
  delay(3000);
  for (int i = 0; i <= 120; i++) {
    rh3.write(140 - i);
    delay(15);
  }
  for (int i = 0; i <= 180; i++) {
    rh1.write(180 - i);
    if (i <= 90) {
      rh2.write(90 - i);
    }
    if (i <= 60) {
      head.write(30 + i);
    }
    delay(15);
  }
}

//********************left bicep********************//
void left_bicep() {
  for (int i = 0; i <= 180; i++) {
    lh1.write(180 - i);
    if (i <= 90) {
      lh2.write(180 - i);
    }
    if (i <= 60) {
      head.write(90 + i);
    }
    delay(15);
  }
  for (int i = 0; i <= 120; i++) {
    lh3.write(160 - i);
    delay(15);
  }
  delay(3000);
  for (int i = 0; i <= 120; i++) {
    lh3.write(40 + i);
    delay(15);
  }
  for (int i = 0; i <= 180; i++) {
    lh1.write(0 + i);
    if (i <= 90) {
      lh2.write(90 + i);
    }
    if (i <= 60) {
      head.write(150 - i);
    }
    delay(15);
  }
}

//********************double biceps********************//
void double_biceps() {
  for (int i = 0; i <= 180; i++) {
    lh1.write(180 - i);
    rh1.write(0 + i);
    if (i <= 90) {
      lh2.write(180 - i);
      rh2.write(0 + i);
    }
    delay(15);
  }
  for (int i = 0; i <= 120; i++) {
    lh3.write(160 - i);
    rh3.write(20 + i);
    delay(15);
  }
  delay(3000);
  for (int i = 0; i <= 120; i++) {
    lh3.write(40 + i);
    rh3.write(140 - i);
    delay(15);
  }
  for (int i = 0; i <= 180; i++) {
    lh1.write(0 + i);
    rh1.write(180 - i);
    if (i <= 90) {
      lh2.write(90 + i);
      rh2.write(90 - i);
    }
    delay(15);
  }
}

//********************do bow********************//
void do_bow() {
  for (int i = 0; i <= 10; i++) {
    ll2.write(30 + (i * 2));
    rl2.write(150 - (i * 2));

    ll4.write(150 + i);
    rl4.write(30 - i);
    delay(100);
  }
  delay(3000);
  for (int i = 0; i <= 10; i++) {
    ll2.write(50 - (i * 2));
    rl2.write(130 + (i * 2));
    ll4.write(160 - i);
    rl4.write(20 + i);
    delay(100);
  }
}

//********************sit down********************//
void sit_down() {
  for (int i = 0; i <= 60; i++) {
    if (i <= 30) {
      lh2.write(180 - i);
      rh2.write(0 + i);
      lh1.write(180 - i);
      rh1.write(0 + i);
    }
    if (i % 2 == 0) {
      rh3.write(20 + i / 2);
      lh3.write(160 - i / 2);
    }
    rl2.write(150 - i);
    ll2.write(30 + i);
    rl3.write(30 + (i * 2));
    ll3.write(150 - (i * 2));
    rl4.write(30 + i);
    ll4.write(150 - i);

    delay(100);
  }
}

//********************stand up********************//
void stand_up() {
  for (int i = 0; i <= 60; i++) {
    if (i <= 30) {
      lh2.write(150 + i);
      rh2.write(30 - i);
      lh1.write(150 + i);
      rh1.write(30 - i);
    }
    if (i % 2 == 0) {
      rh3.write(50 - i / 2);
      lh3.write(130 + i / 2);
    }
    rl2.write(90 + i);
    ll2.write(90 - i);
    rl3.write(150 - (i * 2));
    ll3.write(30 + (i * 2));
    rl4.write(90 - i);
    ll4.write(90 + i);
    delay(100);
  }
}

//********************dab********************//
void do_dab() {
  for (int i = 0; i <= 90; i++) {
    lh2.write(180 - i);
    rh1.write(0 + i);
    if (i <= 70) {
      rh3.write(20 + i);
    }
    if (i <= 20) {
      lh3.write(160 + i);
    }
    if (i % 10 == 0) {
      rl2.write(150 - (i / 10));
      ll2.write(30 + (i / 10));
    }
    delay(15);
  }
  delay(5000);
  for (int i = 0; i <= 90; i++) {
    lh2.write(90 + i);
    rh1.write(90 - i);
    if (i <= 70) {
      rh3.write(90 - i);
    }
    if (i <= 20) {
      lh3.write(180 - i);
    }
    if (i % 10 == 0) {
      rl2.write(141 + (i / 10));
      ll2.write(39 - (i / 10));
    }
    delay(15);
  }
}
