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
#ifndef light_tower_h
#define light_tower_h

#include "Tower.h"

const float ConstLightTowerRange  = 150.0;
const float ConstLightTowerSpeed  =  50.0;
const int   ConstLightTowerDamage =   2;
const int   ConstLightTowerCost   =  60;

class LightTower : public Tower {
  public:
    LightTower (float x, float y) : Tower(x, y, ConstLightTowerRange,
        ConstLightTowerSpeed, ConstLightTowerDamage, ConstLightTowerCost,
        PT_LightProjectile) {};
    LightTower (Interface *interface, float x, float y) : Tower(x, y, ConstLightTowerRange,
        ConstLightTowerSpeed, ConstLightTowerDamage, ConstLightTowerCost,
        PT_LightProjectile) {
      mInterface = interface;
    };
    ~LightTower () {};

    void Update ();
    void Draw ();
  protected:
};

#endif
