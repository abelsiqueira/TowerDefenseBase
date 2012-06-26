#ifndef light_tower_h
#define light_tower_h

#include "Tower.h"

const float ConstLightTowerRange  = 150.0;
const float ConstLightTowerSpeed  =  50.0;
const int   ConstLightTowerDamage =   2;
const int   ConstLightTowerCost   =  30;

class LightTower : public Tower {
  public:
    LightTower (float x, float y) : Tower(x, y, ConstLightTowerRange,
        ConstLightTowerSpeed, ConstLightTowerDamage, ConstLightTowerCost,
        PT_LightProjectile) {};
    LightTower (Interface *interface, float x, float y) : Tower(x, y, ConstLightTowerRange,
        ConstLightTowerSpeed, ConstLightTowerDamage, ConstLightTowerCost,
        PT_LightProjectile) {
      mInterface = interface;
    };
    ~LightTower () {};

    void Update ();
    void Draw ();
  protected:
};

#endif
