#ifndef skeleton_h
#define skeleton_h

#include "Enemy.h"

const float ConstSkeletonSpeed  = 0.3;
const int   ConstSkeletonDamage =   1;
const int   ConstSkeletonHealth =  10;
const float ConstSkeletonBound  = 7.0;

class Skeleton : public Enemy {
  public:
    Skeleton (Vector2f target, float x = 0, float y = 0) : Enemy(target, x, y, 
        ConstSkeletonSpeed, ConstSkeletonDamage, ConstSkeletonHealth, 
        ConstSkeletonBound) {};
    ~Skeleton () {};

    void Update ();
    void Draw ();
  private:
};

#endif
