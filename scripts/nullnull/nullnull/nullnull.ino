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
  servo2.write(90);
  servo3.write(90);
}

void loop() {
 


}