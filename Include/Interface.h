#ifndef interface_h
#define interface_h

#include "Vectors.h"
#include "Towers.h"
#include "Enemies.h"
#include "Projectiles.h"
#include "Definitions.h"
#include <list>

typedef std::list <Enemy*> Wave;
typedef unsigned int uint;

const uint ConstFps = 180;

class Interface {
  public:
    Interface (int w = 1280, int h = 720) : mWindowSize(w, h), mHome(w, h/2),
      mListOfEnemies(), mListOfTowers() {
        mFramesBetweenWaves = 15*ConstFps;
        mFramesBetweenEnemies = ConstFps;
        mWaveTimer = mFramesBetweenWaves;
        mEnemyTimer = 0;
        mTileSize = h/20.0;
        mMapSize.x = w - 5*mTileSize;
        mMapSize.y = h;
        mDrawingClass = new DrawingClass(w, h, this);
        mInsertingTower = false;
        mNextTower = 0;
    }
    ~Interface ();

    void Update ();
    void Draw ();
    void Keyboard (KeyCode);
    void Mouse (MouseCode);
    void Run ();
    void InsertTower (KeyCode);

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
    float GetTileSize () { return mTileSize; }
  private:
    Vector2i mWindowSize, mMapSize;
    Vector2f mHome;
    int mFramesBetweenWaves, mFramesBetweenEnemies;
    int mWaveTimer, mEnemyTimer;
    float mTileSize;
    bool mInsertingTower;
    int mNextTower;

    std::list <Enemy*>      mListOfEnemies;
    std::list <Tower*>      mListOfTowers;
    std::list <Projectile*> mListOfProjectiles;

    std::list < Wave > mWaves;
    std::list <Enemy*> mEnemiesToBeCreated;

    std::list <Entity*> mGarbageCollector;
    std::list <Vector2f> mPath;

    DrawingClass *mDrawingClass;

    void CleanTheGarbageCollector ();
    void DrawHud ();
};

#endif
