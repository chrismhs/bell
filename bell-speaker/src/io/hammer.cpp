#include "application.h"
#include "hammer.h"

void Hammer::setVolume(int volume) {
  // cant set the volume on a hammer
}

void Hammer::playDing() {
  pinMode(D0, OUTPUT);

  // strike hammer for 50ms
  digitalWrite(D0, HIGH);
  delay(50);
  digitalWrite(D0, LOW);

  // delay(500); // give to time dzing
}
