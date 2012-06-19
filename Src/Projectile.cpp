#include "Projectile.h"
#include "Interface.h"

void Projectile::Update () {
  if (mInterface->ProjectileHitsEnemy(this)) {
    KillMe();
    return;
  }
  Vector2f dir(mTarget.x - mPosition.x, mTarget.y - mPosition.y);
  if (dir.Dot(mDirection) < 0) {
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
