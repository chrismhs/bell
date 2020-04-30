#include "dinger.h"

class Speaker: public IDinger {
  public:
    void setVolume(int volume);
    void playDing();
};
