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
