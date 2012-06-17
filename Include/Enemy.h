#ifndef enemy_h
#define enemy_h

#include "Entity.h"

class Enemy : public Entity {
  public:
    Enemy (float x = 0, float y = 0, float speed = 0, int damage = 1) :
      Entity(x, y), mSpeed(speed), mDamage(damage) {};
    virtual ~Enemy () {};

    virtual void Update ();
    virtual void Draw () const;
  protected:
    float mSpeed;
    int mDamage;
};

#endif
