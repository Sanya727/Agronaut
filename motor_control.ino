int stepPins[4] = {2, 4, 6, 8};
int dirPins[4]  = {3, 5, 7, 9};

int stepDelay = 800; // SAFE speed

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(stepPins[i], OUTPUT);
    pinMode(dirPins[i], OUTPUT);
  }
}

void loop() {

  // All clockwise
  setDirection(HIGH, HIGH, HIGH, HIGH);
  runMotors(5000);

  // All anticlockwise
  setDirection(LOW, LOW, LOW, LOW);
  runMotors(5000);

  // M1, M2 anti | M3, M4 clock
  setDirection(LOW, LOW, HIGH, HIGH);
  runMotors(5000);

  // M3, M4 anti | M1, M2 clock
  setDirection(HIGH, HIGH, LOW, LOW);
  runMotors(5000);
}

void setDirection(bool m1, bool m2, bool m3, bool m4) {
  digitalWrite(dirPins[0], m1);
  digitalWrite(dirPins[1], m2);
  digitalWrite(dirPins[2], m3);
  digitalWrite(dirPins[3], m4);
}

void runMotors(unsigned long duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {
    stepAll();
  }
}

void stepAll() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(stepPins[i], HIGH);
  }
  delayMicroseconds(stepDelay);

  for (int i = 0; i < 4; i++) {
    digitalWrite(stepPins[i], LOW);
  }
  delayMicroseconds(stepDelay);
}