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
#include "Projectile.h"
#include "Interface.h"

void Projectile::Update () {
  if (mInterface->ProjectileHitsEnemy(this)) {
    KillMe();
    return;
  }
  Vector2f dir(mTarget.x - mPosition.x, mTarget.y - mPosition.y);
  if ( (dir.Dot(mDirection) < 0) && (dir.SqrMagnitude() > mSpeed) ) {
    KillMe();
    return;
  }
  mPosition.Update(mSpeed, mDirection);
}

void Projectile::Draw () {
  int x = mPosition.x, y = mPosition.y;
  mDrawingClass->DrawFilledCircle(x, y, 2, 0, 255, 0);
}

void Projectile::KillMe () {
  mInterface->KillProjectile(this);
}
