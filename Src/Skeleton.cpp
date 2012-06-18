#include "Skeleton.h"

void Skeleton::Update () {
  Enemy::Update();
}

void Skeleton::Draw () {
  mDrawingClass->DrawFilledCircle(mPosition.x, mPosition.y, 7, 255, 150, 150);
}
