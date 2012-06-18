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
