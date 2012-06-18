#include "Light_Tower.h"

void LightTower::Update () {

}

void LightTower::Draw () {
  int halfSide = 15;
  float x0 = mPosition.x - halfSide, y0 = mPosition.y - halfSide;
  float x1 = mPosition.x + halfSide, y1 = mPosition.y + halfSide;
  mDrawingClass->DrawFilledRectangle(x0, y0, x1, y1, 0, 255, 255);
}
