#include "Skeleton.h"

void Skeleton::Update () {

}

void Skeleton::Draw () {
  mDrawingClass->DrawFilledCircle(mPosition.x, mPosition.y, 10, 255, 150, 150);
}
