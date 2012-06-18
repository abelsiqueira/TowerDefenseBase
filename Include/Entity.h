#ifndef entity_h
#define entity_h

#include "Vector2.h"
#ifndef GraphicLibrary
#include "DummyDraw.h"
#elif GraphicLibrary == ALLEGRO
#include "AllegroDraw.h"
#endif

/* class Entity
 *
 * This is the class for all entities: Tower and Enemies
 */

class DrawingClass;

class Entity {
  public:
    Entity (float x = 0, float y = 0) : mPosition(x, y) {};
    virtual ~Entity() {};

    void SetDrawingClass (DrawingClass *d) { mDrawingClass = d; }
  protected:
    Vector2f mPosition;
    DrawingClass* mDrawingClass;
};

#endif
