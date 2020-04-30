#include <DFPlayer.h>
#include "speaker.h"

DFPlayer dfPlayer;

void Speaker::setVolume(int volume) {
  dfPlayer.setVolume(volume);
}

void Speaker::playDing() {
  dfPlayer.playTrack(1);
  // delay(3000);
}
