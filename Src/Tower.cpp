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
#include "Tower.h"
#include "Interface.h"
#include <iostream>

void Tower::Update () {
  bool canAttack = false;
  mAttackCount += mSpeed;
  if (mAttackCount > ConstAttackThreshold) {
    mAttackCount -= ConstAttackThreshold;
    canAttack = true;
  }
  if (!canAttack)
    return;

  Enemy *pEnemy = mInterface->GetEnemyInRange(mPosition, mRange);
  if (pEnemy == 0)
    return;

  mInterface->CreateProjectile(mPType, mPosition, pEnemy->GetPosition());
}

void Tower::Draw () {
//  int x = mPosition.x, y = mPosition.y;
//  mDrawingClass->DrawCircle(x, y, mRange, 25, 25, 25, 1);
}
