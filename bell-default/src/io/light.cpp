#include "application.h"
#include "light.h"

int ledRed = D2;
int ledGreen = D1;
int ledBlue = D3;

void Light::flash() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void Light::setColor(int red, int green, int blue)
{
  analogWrite(ledRed, red);
  analogWrite(ledGreen, green);
  analogWrite(ledBlue, blue);
}
