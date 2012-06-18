#ifndef enemy_h
#define enemy_h

#include "Entity.h"

enum EnemyType {
  ET_Skeleton
};

class Enemy : public Entity {
  public:
    Enemy (float x = 0, float y = 0, float speed = 0, int damage = 1) :
      Entity(x, y), mSpeed(speed), mDamage(damage) {};
    virtual ~Enemy () {};

    virtual void Update () = 0;
    virtual void Draw () = 0;
  protected:
    float mSpeed;
    int mDamage;
};

#endif
