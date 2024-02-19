#include <VarSpeedServo.h>

VarSpeedServo servo1, servo2, servo3, servo4;
int c = 0;
void setup() {
  Serial.begin(9600);
  //servo1.attach(3);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);


  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);


  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo3.write(90);
}

void loop() {
  //Serial.println(digitalRead(A2));
  if (digitalRead(A0) == 0 && digitalRead(A1) == 0 && digitalRead(A2) == 1 && digitalRead(A3) == 0 && digitalRead(A4) == 0) {
    digitalWrite(3, HIGH);
    digitalWrite(11, HIGH);
    thang();
    Serial.println("thang");
  } else if (digitalRead(A0) == 0 && digitalRead(A1) == 0 && digitalRead(A2) == 1 && digitalRead(A3) == 1 && digitalRead(A4) == 0) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    phai();
    Serial.println("phai");
  } else if (digitalRead(A0) == 0 && digitalRead(A1) == 0 && digitalRead(A2) == 1 && digitalRead(A3) == 1 && digitalRead(A4) == 1) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    phai();
    Serial.println("phai1");
  } else if (digitalRead(A0) == 0 && digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 1 && digitalRead(A4) == 1) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    phai();
    Serial.println("phai2");
  } else if (digitalRead(A0) == 0 && digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 1 && digitalRead(A4) == 0) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    phai();
    Serial.println("phai3");
  } else if (digitalRead(A0) == 0 && digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 0 && digitalRead(A4) == 1) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    phai();
    Serial.println("phai4");
  } else if (digitalRead(A0) == 0 && digitalRead(A1) == 1 && digitalRead(A2) == 1 && digitalRead(A3) == 0 && digitalRead(A4) == 0) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    trai();
    Serial.println("trai");
  } else if (digitalRead(A0) == 1 && digitalRead(A1) == 1 && digitalRead(A2) == 1 && digitalRead(A3) == 0 && digitalRead(A4) == 0) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    trai();
    Serial.println("trai1");
  } else if (digitalRead(A0) == 1 && digitalRead(A1) == 1 && digitalRead(A2) == 0 && digitalRead(A3) == 0 && digitalRead(A4) == 0) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    trai();
    Serial.println("trai2");
  } else if (digitalRead(A0) == 0 && digitalRead(A1) == 1 && digitalRead(A2) == 0 && digitalRead(A3) == 0 && digitalRead(A4) == 0) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    trai();
    Serial.println("trai3");
  } else if (digitalRead(A0) == 1 && digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 0 && digitalRead(A4) == 0) {
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    trai();
    Serial.println("trai4");
  } else if (digitalRead(A0) == 1 && digitalRead(A1) == 1 && digitalRead(A2) == 1 && digitalRead(A3) == 1 && digitalRead(A4) == 1) {
    dung();
    delay(3000);
    Serial.println("dung");
    if (c == 0) {
      digitalWrite(9, HIGH);
     
      //delay(500);
      c = 1;
    } else if (c == 1) {
      digitalWrite(9, LOW);
      
      //delay(500);
      c = 0;
    }
    digitalWrite(3, 1);
    digitalWrite(11, 1);
    thang();
    delay(10);

  } else {
    dung();
  }
  delay(50);
}
void thang() {
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
}
void trai() {
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
}
void phai() {
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
}

void dung() {
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
}
