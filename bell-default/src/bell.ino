// This #include statement was automatically added by the Particle IDE.
SYSTEM_THREAD(ENABLED);

#include "io/dinger.h"
#include "io/hammer.h"
#include "io/light.h"

#define OFF 0,0,0
#define PEACH 200,50,5
#define WHITE 200,255,255

#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255

int i;
int j;

int buttonPin = D6;

Light light;
IDinger *dinger;

void setup() {
  dinger = new Hammer();

  pinMode(buttonPin, INPUT_PULLUP);
  Particle.function("trigger", trigger);

  Serial.begin(9600);

  delay(500);

  Serial.println("Setup complete!");
}


int trigger(String colour) {
  Serial.println("CloudFunction: new_message started");
  Serial.println(colour);

  int red;
  int green;
  int blue;

  if (colour == "red") {
    red = 255;
    green = 0;
    blue = 0;
  } else if (colour == "blue") {
    red = 0;
    green = 0;
    blue = 255;
  } else {
    red = 0;
    green = 255;
    blue = 0;
  }

  notifyUser(red, green, blue);
  return 0;
}

void notifyUser(int red, int green, int blue) {
  dinger->playDing();

  light.setColor(red, green, blue);
  delay(200);

  light.flash();

  // Dont allow more then 2 notify a second
  delay(2000);
}

void loop() {
  // int buttonState = digitalRead(buttonPin);
  // if(buttonState == LOW) {
  //   notifyUser(RED);
  // }
}
