#include "Enemy.h"
#include "Interface.h"

void Enemy::Update () {

}

void Enemy::Draw () {
  int x = mPosition.x, y = mPosition.y;
  float s = 7;
  float life = -s + 2*s*((float) mHealth)/((float) mMaxHealth);
  mDrawingClass->DrawFilledRectangle(x - s, y - s - 10, x + s, y - s - 5, 255, 0, 0);
  mDrawingClass->DrawFilledRectangle(x - s, y - s - 10, x + life, y - s - 5, 0, 255, 0);
}

bool Enemy::CollideWithProjectile (Projectile *projectile) {
  Vector2f point = projectile->GetPosition();
  float d = point.Distance(mPosition);
  if (d < 50) {
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
