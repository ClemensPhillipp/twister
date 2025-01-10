#include <Servo.h>
int GSM1 = 3;
int pause_time = 5000;
int ground_time = 5000;
int air_time = 10000;
int max_speed =50;
#define In1 5
#define In2 6
Servo servo;

int pos = 180;
int maxpos = 90;
void setup() {
  servo.attach(9);
  servo.write(pos);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(GSM1, OUTPUT);
}

void loop() {
  delay(pause_time);
  startSpin();
  delay(ground_time);

  for (int i = pos; i >= maxpos; i -= 1) {
    servo.write(i);
    delay(50);
  }

  delay(air_time);
  for (int i = maxpos; i <= pos; i += 1) {                                                                                                         
    servo.write(i);
    delay(50);
  }
  delay(ground_time);
  stopSpin();
}

void startSpin() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for (int i = 0; i <= max_speed; i += 5) {
    analogWrite(GSM1, i);
    delay(80);
  }
}

void stopSpin() {
  for (int i = max_speed; i >= 0; i -= 5) {
    analogWrite(GSM1, i);
    delay(80);
  }
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
}