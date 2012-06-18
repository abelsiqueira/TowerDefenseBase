#include "Light_Tower.h"

void LightTower::Update () {

}

void LightTower::Draw () {
  float x0 = mPosition.x - 5, y0 = mPosition.y - 5;
  float x1 = mPosition.x + 5, y1 = mPosition.y + 5;
  mDrawingClass->DrawFilledRectangle(x0, y0, x1, y1, 0, 255, 255);
}
