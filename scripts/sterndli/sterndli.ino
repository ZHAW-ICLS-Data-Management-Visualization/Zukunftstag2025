#include <Servo.h>

Servo servo1;  // Linker Servo
Servo servo2;  // Mittlerer Servo (Stift)
Servo servo3;  // Rechter Servo

void setup() {
  // Servos mit den Arduino-Pins verbinden
  servo1.attach(4);  // Linker Servo an Pin 4
  servo2.attach(6);  // Stift-Servo an Pin 6
  servo3.attach(8);  // Rechter Servo an Pin 8

  servo1.write(90);
  servo2.write(120);
  servo3.write(90);
}

void loop() {

// stern wie von hand
int ecken[5][2] = {
    {135, 75},
    {110, 55},
    {150, 60},
    {105, 85},
    {120, 35}
  };
  
  for (int e=0; e<=4; e=e+1) {
    servo1.write(ecken[e][0]);
    servo3.write(ecken[e][1]);
    delay(1000);

    if (e==0) {
      delay(1000);
      servo2.write(160);
      delay(1000);
    }
    if (e==4) {
      servo1.write(ecken[0][0]);
      servo3.write(ecken[0][1]);
      delay(1000);
      servo2.write(120);
      delay(1000);
    }
  }

}