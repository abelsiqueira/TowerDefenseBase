#ifndef tower_h
#define tower_h

#include "Entity.h"
#include "Projectile.h"

enum TowerType {
  LightTower
};

class Tower : public Entity {
  public:
    Tower (float x = 0, float y = 0, float range = 0, float speed = 0, 
        int damage = 0, ProjectileType pt = PT_None) : Entity(x, y), mRange(range), 
        mSpeed(speed), mDamage(damage), mPType(pt) {};
    virtual ~Tower () {};

    virtual void Update () = 0;
    virtual void Draw () const = 0;
  protected:
    float mRange, mSpeed;
    int mDamage;

    ProjectileType mPType;
};

#endif
