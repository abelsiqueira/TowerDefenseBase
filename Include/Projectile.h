#ifndef projectile_h
#define projectile_h

enum ProjectileTypes {
  PT_Example1,
  PT_Example2
};

class Projectile : public Entity {
  public:
    Projectile (float x, float y, float tx, float ty, float speed = 0) :
      Entity(x, y), mTarget(tx, ty), mSpeed(speed) {};
    virtual ~Projectile () {};
  protected:
    Vector2f mTarget;
    float mSpeed;
};

#endif
