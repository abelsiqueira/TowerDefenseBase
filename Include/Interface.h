#ifndef interface_h
#define interface_h

#ifndef GraphicLibrary
#include "DummyDraw.h"
#elif GraphicsLibrary == ALLEGRO
#include "AllegroDraw.h"
#endif

#include "Vector2.h"
#include "Towers.h"
#include "Enemies.h"
#include <list>

class Interface {
  public:
    Interface (int w = 1000, int h = 800) : mWindowSize(w, h), 
      mListOfEnemies(), mListOfTowers(), 
      mDrawingClass(new DrawingClass(w, h, this)) { }
    ~Interface () {};

    void Update ();
    void Draw ();
    void Run ();

    DrawingClass *Drawing () { return mDrawingClass; }
  private:
    Vector2i mWindowSize;
    std::list <Enemy*> mListOfEnemies;
    std::list <Tower*> mListOfTowers;

    DrawingClass *mDrawingClass;
};

#endif
