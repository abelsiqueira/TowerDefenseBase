/* Copyright 2012 - Abel Soares Siqueira
 * 
 * This file is part of TowerDefenseBase.
 * 
 * TowerDefenseBase is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * TowerDefenseBase is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with TowerDefenseBase.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "Light_Tower.h"
#include "Interface.h"
#include <iostream>

void LightTower::Update () {
  Tower::Update();
}

void LightTower::Draw () {
  Tower::Draw();

  int halfSide = mInterface->GetTileSize()/2-2;
  float x0 = mPosition.x - halfSide, y0 = mPosition.y - halfSide;
  float x1 = mPosition.x + halfSide, y1 = mPosition.y + halfSide;
  mDrawingClass->DrawFilledRectangle(x0, y0, x1, y1, 0, 255, 255);
}
