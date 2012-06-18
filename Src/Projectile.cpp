#include "Projectile.h"
#include "Interface.h"

void Projectile::Update () {
  if (mInterface->ProjectileHitsEnemy(this))
    KillMe();
  Vector2f dir(mTarget.x - mPosition.x, mTarget.y - mPosition.y);
  float norm = dir.Magnitude();
  if (norm < mSpeed)
    KillMe();
  dir.Scale(1.0/norm);
  mPosition.Update(mSpeed, dir);
}

void Projectile::Draw () {
  int x = mPosition.x, y = mPosition.y;
  mDrawingClass->DrawFilledCircle(x, y, 2, 0, 255, 0);
}

void Projectile::KillMe () {
  mInterface->KillProjectile(this);
}
