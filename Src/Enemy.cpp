#include "Enemy.h"

void Enemy::Update () {

}

void Enemy::Draw () {
  int x = mPosition.x, y = mPosition.y;
  mDrawingClass->DrawCircle(x, y, 50, 255, 255, 255, 1);
}
