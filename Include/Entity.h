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
#ifndef entity_h
#define entity_h

#include "Vectors.h"
#ifndef GraphicLibrary
#include "DummyDraw.h"
#elif GraphicLibrary == ALLEGRO
#include "AllegroDraw.h"
#endif

/* class Entity
 *
 * This is the class for all entities: Tower and Enemies
 */

const int ConstAttackThreshold = 1000;

class DrawingClass;
class Interface;

class Entity {
  public:
    Entity (float x = 0, float y = 0) : mPosition(x, y) {};
    Entity (Vector2f v) : mPosition(v) {};
    virtual ~Entity() {};

    Vector2f GetPosition () { return mPosition; }

    void SetDrawingClass (DrawingClass *d) { mDrawingClass = d; }
    void SetInterface (Interface *i) { mInterface = i; }
    virtual void Update () = 0;
    virtual void Draw () = 0;
  protected:
    Vector2f mPosition;
    Interface* mInterface;
    DrawingClass* mDrawingClass;

    virtual void KillMe () { throw("Dont call this"); }
};

#endif
