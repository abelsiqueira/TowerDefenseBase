#ifndef projectile_h
#define projectile_h

#include "Entity.h"

enum ProjectileType { PT_None, PT_LightProjectile };

class Projectile : public Entity {
  public:
    Projectile (float x, float y, float tx, float ty, float speed = 0, 
        int damage = 1) : Entity(x, y), mTarget(tx, ty), mSpeed(speed),
        mDamage(damage), mDirection(tx - x, ty - y) { 
      mDirection.Normalize();
    };
    Projectile (Vector2f origin, Vector2f target, float speed = 0, int damage = 1) : 
        Entity(origin), mTarget(target), mSpeed(speed), mDamage(damage),
        mDirection(target.x - origin.x, target.y - origin.y) {
      mDirection.Normalize();
    };
    virtual ~Projectile () {};

    int GetDamage () { return mDamage; }
    virtual void Update ();
    virtual void Draw ();
  protected:
    Vector2f mTarget;
    float mSpeed;
    int mDamage; 
    Vector2f mDirection;

    void KillMe ();
};

#endif
