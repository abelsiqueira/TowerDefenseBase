#ifndef entity_h
#define entity_h

#include "Vector2.h"

/* class Entity
 *
 * This is the class for all entities: Tower and Enemies
 */

class Entity {
  public:
    Entity (float x = 0, float y = 0) : mPosition(x, y) {};
    virtual ~Entity() {};
  protected:
    Vector2f mPosition;
};

#endif
