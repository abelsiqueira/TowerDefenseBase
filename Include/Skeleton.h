#ifndef skeleton_h
#define skeleton_h

#include "Enemy.h"

const float ConstSkeletonSpeed  = 0.3;
const int   ConstSkeletonDamage =   1;
const int   ConstSkeletonHealth =  15;
const float ConstSkeletonBound  = 7.0;
const int   ConstSkeletonReward =   5;

class Skeleton : public Enemy {
  public:
    Skeleton (Vector2f target, float x = 0, float y = 0) : Enemy(target, x, y, 
        ConstSkeletonSpeed, ConstSkeletonDamage, ConstSkeletonHealth, 
        ConstSkeletonBound, ConstSkeletonReward) {};
    ~Skeleton () {};

    void Update ();
    void Draw ();
  private:
};

#endif
