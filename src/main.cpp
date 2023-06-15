#include <Arduino.h>
#include <OLED_I2C.h>

#define echo 2
#define trig 3
 
int distance;

OLED display(A4, A5, A4);

extern uint8_t SmallFont[];



void setup() {

  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  display.begin();

}


void loop() {

  digitalWrite(trig, 0);
  delayMicroseconds(2);

  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);

  distance = pulseIn(echo, 1) / 58;

  display.clrScr();
  display.setFont(SmallFont);
  display.print("Distance (in cm):", CENTER, 20);
  display.printNumI(distance, CENTER, 30);
  display.update();
}