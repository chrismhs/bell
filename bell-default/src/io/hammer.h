#include "dinger.h"

class Hammer: public IDinger {
  public:
    void setVolume(int volume);
    void playDing();
};
