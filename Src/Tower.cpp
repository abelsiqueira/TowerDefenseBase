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
  int x = mPosition.x, y = mPosition.y;
  mDrawingClass->DrawCircle(x, y, mRange, 150, 150, 150, 1);
}
