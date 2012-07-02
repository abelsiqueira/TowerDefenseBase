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
#ifndef tower_h
#define tower_h

#include "Entity.h"
#include "Projectile.h"

enum TowerType {
  TT_LightTower
};

class Enemy;

class Tower : public Entity {
  public:
    Tower (float x = 0, float y = 0, float range = 0, float speed = 0, 
        int damage = 0, int cost = 0, ProjectileType pt = PT_None) : Entity(x, y), mRange(range), 
        mSpeed(speed), mDamage(damage), mCost(cost), mPType(pt), 
        mAttackCount(ConstAttackThreshold) {};
    virtual ~Tower () {};

    virtual void Update ();
    virtual void Draw ();
  protected:
    float mRange, mSpeed;
    int mDamage, mCost;

    ProjectileType mPType;

    int mAttackCount;
};

#endif
