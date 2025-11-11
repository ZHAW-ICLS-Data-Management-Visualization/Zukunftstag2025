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
  // von oben nach unten
  for (int i=0; i<=50; i=i+1) {
    servo1.write(90+i);
    servo3.write(90-i);
    delay(30);

    if (i==0) {
      delay(1000);
      servo2.write(170); 
      delay(1000);
    }
  }
  servo2.write(120);
  delay(500);
}