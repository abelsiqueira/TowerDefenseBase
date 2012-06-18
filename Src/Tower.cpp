#include "Tower.h"

void Tower::Update () {

}

void Tower::Draw () {
  int x = mPosition.x, y = mPosition.y;
  mDrawingClass->DrawRectangle(x - 50, y - 50, x + 50, y + 50, 255, 255, 255, 1);
}
