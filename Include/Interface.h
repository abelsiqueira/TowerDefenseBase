#ifndef interface_h
#define interface_h

#include "Vector2.h"
#include "Towers.h"
#include "Enemies.h"
#include "Projectiles.h"
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

    void CreateEnemy      (EnemyType, float, float);
    void CreateTower      (TowerType, float, float);
    void CreateProjectile (ProjectileType, Vector2f, Vector2f);

    Enemy* GetEnemyInRange (Vector2f, float);
    bool ProjectileHitsEnemy (Projectile*);

    void KillEnemy (Enemy *);
    void KillTower (Tower *);
    void KillProjectile (Projectile *);
  private:
    Vector2i mWindowSize;
    std::list <Enemy*>      mListOfEnemies;
    std::list <Tower*>      mListOfTowers;
    std::list <Projectile*> mListOfProjectiles;

    std::list <Entity*> mGarbageCollector;

    DrawingClass *mDrawingClass;
};

#endif
