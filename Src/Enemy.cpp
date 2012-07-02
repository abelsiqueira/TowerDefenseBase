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
#include "Enemy.h"
#include "Interface.h"

void Enemy::Update () {
  Vector2f direction(mTarget);
  direction.Update(-1, mPosition);
  float norm = direction.Magnitude();
  if (norm < mSpeed) {
    KillMe();
    return;
  }
  if (mPath.empty()) {
    return;
  }
  direction = *mPath.begin();
  direction.Update(-1, mPosition);
  norm = direction.Magnitude();
  if (norm < mSpeed) {
    mPath.pop_front();
    return;
  }
  mPosition.Update(mSpeed/norm, direction);
}

void Enemy::Draw () {
  int x = mPosition.x, y = mPosition.y;
  float life = -mBound + 2*mBound*((float) mHealth)/((float) mMaxHealth);
  mDrawingClass->DrawFilledRectangle(x - mBound, y - mBound - 10, x + mBound, 
      y - mBound - 5, 255, 0, 0);
  mDrawingClass->DrawFilledRectangle(x - mBound, y - mBound - 10, x + life, 
      y - mBound - 5, 0, 255, 0);
}

bool Enemy::CollideWithProjectile (Projectile *projectile) {
  if (mHealth <= 0)
    return false;
  Vector2f point = projectile->GetPosition();
  float d = point.Distance(mPosition);
  if (d <= mBound + 1) {
    Damage(projectile->GetDamage());
    return true;
  }
  return false;
}

void Enemy::Damage (int damage) {
  mHealth -= damage;
  if (mHealth <= 0)
    KillMe();
}

void Enemy::KillMe () {
  mInterface->KillEnemy(this);
}
