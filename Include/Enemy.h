#ifndef enemy_h
#define enemy_h

class Enemy : public Entity {
  public:
    Enemy (float x = 0, float y = 0, float speed = 0, int damage = 1) :
      Entity(x, y), mSpeed(speed), mDamage(damage) {};
    virtual ~Enemy () {};
  private:
    float mSpeed;
    int mDamage;
};

#endif
