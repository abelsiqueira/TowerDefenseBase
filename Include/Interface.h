#ifndef interface_h
#define interface_h

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

    void CreateEnemy (EnemyType, float, float);
    void CreateTower (TowerType, float, float);

    Enemy* GetEnemyInRange (Vector2f, float);
    void CreateProjectile (ProjectileType, Vector2f, Vector2f);
  private:
    Vector2i mWindowSize;
    std::list <Enemy*> mListOfEnemies;
    std::list <Tower*> mListOfTowers;

    DrawingClass *mDrawingClass;
};

#endif
