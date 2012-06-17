#ifndef projectile_h
#define projectile_h

enum ProjectileType {
  PT_LightProjectile
};

class Projectile : public Entity {
  public:
    Projectile (float x, float y, float tx, float ty, float speed = 0) :
      Entity(x, y), mTarget(tx, ty), mSpeed(speed) {};
    virtual ~Projectile () {};

    virtual void Update ();
    virtual void Draw () const;
  protected:
    Vector2f mTarget;
    float mSpeed;
};

#endif
