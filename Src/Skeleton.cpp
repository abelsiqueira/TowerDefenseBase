#include "Skeleton.h"

void Skeleton::Update () {
  Enemy::Update();
}

void Skeleton::Draw () {
  Enemy::Draw();
  mDrawingClass->DrawFilledCircle(mPosition.x, mPosition.y, mBound, 255, 150, 150);
}
