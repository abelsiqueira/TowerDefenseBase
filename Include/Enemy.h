#ifndef enemy_h
#define enemy_h

#include "Entity.h"
#include "Projectile.h"
#include <list>

enum EnemyType {
  ET_Skeleton
};

class Enemy : public Entity {
  public:
    Enemy (Vector2f target, float x = 0, float y = 0, float speed = 0, 
        int damage = 1, int health = 1, float bound = 1, int reward = 0) : 
        Entity(x, y), mSpeed(speed), mDamage(damage), mHealth(health), 
        mMaxHealth(health), mReward(reward), mBound(bound), mTarget(target) {};
    virtual ~Enemy () {};

    virtual void Update ();
    virtual void Draw ();

    bool CollideWithProjectile (Projectile *);
    void Damage (int);
    void SetPath (std::list<Vector2f>::iterator begin,
        std::list<Vector2f>::iterator end) {
      mPath.assign(begin, end);
    }
  protected:
    float mSpeed;
    int mDamage, mHealth, mMaxHealth, mReward;
    float mBound;
    Vector2f mTarget;
    std::list <Vector2f> mPath;

    void KillMe ();
};

#endif
