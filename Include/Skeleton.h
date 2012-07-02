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
