#ifndef interface_h
#define interface_h

#ifndef GraphicLibrary
#include "DummyDraw.h"
#endif

#include "Vector2.h"
#include "Towers/Towers.h"
#include "Enemies/Enemies.h"
#include <list>

class Interface {
  public:
    Interface (int w = 1000, int h = 800) : WindowSize(w, h) {};
    ~Interface () {};

    void Update ();
    void Draw () const;
  private:
    Vector2i WindowSize;
    std::list <Enemy*> ListOfEnemies;
    std::list <Tower*> ListOfTowers;
};

#endif
