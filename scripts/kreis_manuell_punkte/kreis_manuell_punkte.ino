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
   // kreis ab int kreispunkte[23][2]
  // 140, 40 ist der kritische punkt, was weiter gespreizt wird, zerstört den roboter
  // die werte der kreispunkte für die servos gehen von 60 bis 120
  int kreispunkte[23][2] = {
    {90, 90}, {95, 80}, {100, 70}, {105, 60}, {110, 50}, {115, 40},
    {120, 40}, {125, 40}, {130, 50}, {135, 60}, {140, 70}, {145, 80},
    {150, 90}, {145, 100}, {140, 110}, {135, 120}, {130, 120}, {125, 120},
    {120, 110}, {115, 100}, {110, 90}, {105, 80}, {100, 70}
  };
  for (int k=0; k<23; k=k+1) {
    if (k==0) {
      delay(1000);
      servo2.write(170); 
      delay(1000);
    }
    servo1.write(kreispunkte[k][0]);
    servo3.write(kreispunkte[k][1]);
    delay(200);
  }
}