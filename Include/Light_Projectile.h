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
#ifndef light_projectile_h
#define light_projectile_h

#include "Projectile.h"

const float ConstLightProjectileSpeed  = 5.0;
const int   ConstLightProjectileDamage =   1;

class LightProjectile : public Projectile {
  public:
    LightProjectile (Vector2f origin, Vector2f target) : Projectile(origin, 
        target, ConstLightProjectileSpeed, ConstLightProjectileDamage) {}
    ~LightProjectile () {};

    void Update ();
    void Draw ();
  protected:
};

#endif
