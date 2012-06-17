#ifndef skeleton_h
#define skeleton_h

#include "Enemy.h"

const float SkeletonSpeed  = 2.0;
const int   SkeletonDamage = 1;

class Skeleton : public Enemy {
  public:
    Skeleton (float x = 0, float y = 0) : Enemy(x, y, SkeletonSpeed,
        SkeletonDamage) {};
    ~Skeleton () {};

    void Update ();
    void Draw () const;
  private:
};

#endif
