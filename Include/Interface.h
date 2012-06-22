#ifndef interface_h
#define interface_h

#include "Vector2.h"
#include "Towers.h"
#include "Enemies.h"
#include "Projectiles.h"
#include <list>

typedef std::list <Enemy*> Wave;
typedef unsigned int uint;

const uint ConstFps = 180;
const float ConstTileSize = 30.0;

class Interface {
  public:
    Interface (int w = 1000, int h = 800) : mWindowSize(w, h), mHome(w, h/2),
      mListOfEnemies(), mListOfTowers(), 
      mDrawingClass(new DrawingClass(w, h, this)) { 
        mFramesBetweenWaves = 6*ConstFps;
        mFramesBetweenEnemies = ConstFps;
    }
    ~Interface ();

    void Update ();
    void Draw ();
    void Run ();

    DrawingClass *Drawing () { return mDrawingClass; }

    void CreateEnemy      (uint, EnemyType, float, float);
    void CreateEnemy      (uint, EnemyType);
    void CreateEnemy      (EnemyType, float, float);
    void CreateEnemy      (EnemyType);
    void CreateTower      (TowerType, float, float);
    void CreateProjectile (ProjectileType, Vector2f, Vector2f);

    Enemy* GetEnemyInRange (Vector2f, float);
    bool ProjectileHitsEnemy (Projectile*);

    void KillEnemy (Enemy *);
    void KillTower (Tower *);
    void KillProjectile (Projectile *);

    void AddToPath (Vector2f p) {
      mPath.push_back(p);
    }
    void AddToPath (float x, float y) {
      Vector2f aux(x,y);
      mPath.push_back(aux);
    }
  private:
    Vector2i mWindowSize;
    Vector2f mHome;
    int mFramesBetweenWaves, mFramesBetweenEnemies;

    std::list <Enemy*>      mListOfEnemies;
    std::list <Tower*>      mListOfTowers;
    std::list <Projectile*> mListOfProjectiles;

    std::list < Wave > mWaves;
    std::list <Enemy*> mEnemiesToBeCreated;

    std::list <Entity*> mGarbageCollector;
    std::list <Vector2f> mPath;

    DrawingClass *mDrawingClass;

    void CleanTheGarbageCollector ();
};

#endif
