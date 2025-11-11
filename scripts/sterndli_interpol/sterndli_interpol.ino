#include <Servo.h>

Servo servo1;  // Linker Servo
Servo servo2;  // Mittlerer Servo (Stift)
Servo servo3;  // Rechter Servo

const int STEPS = 40;
const int STEP_DELAY = 15; // ms
const int MOVE_DURATION = STEPS * STEP_DELAY;

// Globale Position des letzten Punktes
int lastX = 90;
int lastY = 90;

void setup() {
  Serial.begin(9600);

  servo1.attach(4);
  servo2.attach(6);
  servo3.attach(8);

  servo1.write(lastX);
  servo2.write(120);
  servo3.write(lastY);
}

// Interpolation zwischen zwei Koordinatenpunkten
void moveInSteps(int xStart, int yStart, int xEnd, int yEnd) {
  Serial.print("Bewege von (");
  Serial.print(xStart);
  Serial.print(", ");
  Serial.print(yStart);
  Serial.print(") nach (");
  Serial.print(xEnd);
  Serial.print(", ");
  Serial.print(yEnd);
  Serial.println(")");

  for (int i = 0; i <= STEPS; i++) {
    float t = i / float(STEPS);
    int x = round(xStart + t * (xEnd - xStart));
    int y = round(yStart + t * (yEnd - yStart));

    servo1.write(x);
    servo3.write(y);
    delay(STEP_DELAY);
  }

  // Update globale Position
  lastX = xEnd;
  lastY = yEnd;
}

void loop() {
  int ecken[5][2] = {
    {135, 75},
    {110, 55},
    {150, 60},
    {105, 85},
    {120, 35}
  };

  for (int e = 0; e <= 4; e++) {
    int xEnd = ecken[e][0];
    int yEnd = ecken[e][1];

    moveInSteps(lastX, lastY, xEnd, yEnd);
    delay(MOVE_DURATION);

    if (e == 0) {
      delay(MOVE_DURATION);
      Serial.println("Stift runter");
      servo2.write(160);
      delay(MOVE_DURATION);
    }

    if (e == 4) {
      moveInSteps(lastX, lastY, ecken[0][0], ecken[0][1]);
      delay(MOVE_DURATION);
      Serial.println("Stift hoch");
      servo2.write(120);
      delay(MOVE_DURATION);
    }
  }
}
