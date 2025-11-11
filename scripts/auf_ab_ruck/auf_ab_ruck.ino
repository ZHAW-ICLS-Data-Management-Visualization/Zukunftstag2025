#include <Servo.h>

Servo servo1;  // Linker Servo
Servo servo2;  // Mittlerer Servo (Stift)
Servo servo3;  // Rechter Servo

void setup() {
  // Servos mit den Arduino-Pins verbinden
  servo1.attach(4);  // Linker Servo an Pin 4
  servo2.attach(6);  // Stift-Servo an Pin 6
  servo3.attach(8);  // Rechter Servo an Pin 8

  servo1.write(90+10);
  servo2.write(170);
  servo3.write(90-10);
}

void loop() {
    servo2.write(170); 
    delay(500);

    servo1.write(90+10);
    servo3.write(90-10);
    delay(1000);

    servo2.write(120);
    delay(5000);

     servo1.write(90+50);
    servo3.write(90-50);
    delay(1000);
}