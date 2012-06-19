#ifndef skeleton_h
#define skeleton_h

#include "Enemy.h"

const float ConstSkeletonSpeed  = 2.0;
const int   ConstSkeletonDamage =   1;
const int   ConstSkeletonHealth =  10;
const float ConstSkeletonBound  = 7.0;

class Skeleton : public Enemy {
  public:
    Skeleton (float x = 0, float y = 0) : Enemy(x, y, ConstSkeletonSpeed,
        ConstSkeletonDamage, ConstSkeletonHealth, ConstSkeletonBound) {};
    ~Skeleton () {};

    void Update ();
    void Draw ();
  private:
};

#endif
