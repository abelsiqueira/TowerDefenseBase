#ifndef light_tower_h
#define light_tower_h

#include "Tower.h"

const float LightTowerRange  =  5.0;
const float LightTowerSpeed  = 10.0;
const int   LightTowerDamage =  2.0;

class LightTower : public Tower {
  public:
    LightTower (float x, float y) : Tower(x, y, LightTowerRange,
        LightTowerSpeed, LightTowerDamage, PT_LightProjectile) {};
    ~LightTower () {};

    void Update ();
    void Draw ();
  protected:
};

#endif
