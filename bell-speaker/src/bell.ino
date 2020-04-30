// This #include statement was automatically added by the Particle IDE.
SYSTEM_THREAD(ENABLED);

#include "io/dinger.h"
#include "io/speaker.h"
#include "io/hammer.h"
#include "io/light.h"

#define OFF 0,0,0
#define PEACH 200,50,5
#define RED 255,0,0
#define WHITE 200,255,255
#define GREEN 0,255,0
#define BLUE 0,0,255


int i;
int j;

int buttonPin1 = D6;
boolean silentMode = false;

int volume = 30;

Light light;
IDinger *dinger;

void setup() {

  if (true) {
    dinger = new Speaker();
  } else {
    dinger = new Hammer();
  }

  dinger->setVolume(volume);

  pinMode( buttonPin1 , INPUT_PULLUP);
  Particle.function("newmessage", new_message);

  Serial.begin(115200);
  Serial1.begin(9600);
  delay(500);


  Serial.println("Setup complete!");
}


int new_message(String command) {
  Serial.println("CloudFunction: new_message started");
  notifyUser();
  return 0;
}

void notifyUser() {
  if(silentMode) {
    light.flash();
  } else {
    dinger->playDing();
    light.flash();
  }
  // Dont allow more then 2 notify a second
  delay(2000);
}

void loop() {
    int buttonState = digitalRead( buttonPin1 );
    if( buttonState == LOW )
    {
        notifyUser();
    }
}
