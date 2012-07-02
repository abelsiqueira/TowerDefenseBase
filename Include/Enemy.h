/* Copyright 2012 - Abel Soares Siqueira
 * 
 * This file is part of TowerDefenseBase.
 * 
 * TowerDefenseBase is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * TowerDefenseBase is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with TowerDefenseBase.  If not, see <http://www.gnu.org/licenses/>.
 */
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
    int GetReward () const { return mReward; }
  protected:
    float mSpeed;
    int mDamage, mHealth, mMaxHealth, mReward;
    float mBound;
    Vector2f mTarget;
    std::list <Vector2f> mPath;

    void KillMe ();
};

#endif
