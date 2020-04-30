#include "application.h"
#include "light.h"

int ledRed = D1;
int ledGreen = D3;
int ledBlue = D2;

void Light::flash() {
  pinMode(D1, OUTPUT);
  for (int i = 0; i < 3; i++) {
    digitalWrite(D1, HIGH);
    delay(100);
    digitalWrite(D1, LOW);
    delay(200);
  }
}



//
//
//   pinMode(ledRed, OUTPUT);
//   pinMode(ledGreen, OUTPUT);
//   pinMode(ledBlue, OUTPUT);

// void setColor(int red, int green, int blue)
// {
//   analogWrite(ledRed, red);
//   analogWrite(ledGreen, green);
//   analogWrite(ledBlue, blue);
// }
