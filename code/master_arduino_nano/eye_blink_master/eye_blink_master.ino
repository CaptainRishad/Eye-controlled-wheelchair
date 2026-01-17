#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX, TX

int LF = 8;
int LR = 9;
int RF = 10;
int RR = 11;

void setup() {
  pinMode(LF, OUTPUT);
  pinMode(LR, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RR, OUTPUT);

  bluetooth.begin(9600);
  stopMotors();
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();

    switch (command) {
      case 'F':
        forward();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':
        stopMotors();
        break;
    }
  }
}

void forward() {
  digitalWrite(LF, HIGH);
  digitalWrite(LR, LOW);
  digitalWrite(RF, HIGH);
  digitalWrite(RR, LOW);
}

void left() {
  digitalWrite(LF, LOW);
  digitalWrite(LR, HIGH);
  digitalWrite(RF, HIGH);
  digitalWrite(RR, LOW);
}

void right() {
  digitalWrite(LF, HIGH);
  digitalWrite(LR, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RR, HIGH);
}

void stopMotors() {
  digitalWrite(LF, LOW);
  digitalWrite(LR, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RR, LOW);
}
