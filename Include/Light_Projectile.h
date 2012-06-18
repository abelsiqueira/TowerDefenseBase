#ifndef light_projectile_h
#define light_projectile_h

#include "Projectile.h"

const float ConstLightProjectileSpeed  = 10.0;
const int   ConstLightProjectileDamage =    2;

class LightProjectile : public Projectile {
  public:
    LightProjectile (Vector2f origin, Vector2f target) : Projectile(origin, 
        target, ConstLightProjectileSpeed, ConstLightProjectileDamage) {}
    ~LightProjectile () {};

    void Update ();
    void Draw ();
  protected:
};

#endif
