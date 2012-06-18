#ifndef light_tower_h
#define light_tower_h

#include "Tower.h"

const float ConstLightTowerRange  = 150.0;
const float ConstLightTowerSpeed  =  30.0;
const int   ConstLightTowerDamage =   2;

class LightTower : public Tower {
  public:
    LightTower (float x, float y) : Tower(x, y, ConstLightTowerRange,
        ConstLightTowerSpeed, ConstLightTowerDamage, PT_LightProjectile) {};
    ~LightTower () {};

    void Update ();
    void Draw ();
  protected:
};

#endif
