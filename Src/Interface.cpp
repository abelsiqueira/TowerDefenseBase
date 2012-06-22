#include "Interface.h"

typedef std::list <Enemy*>::iterator EnemyIterator;
typedef std::list <Tower*>::iterator TowerIterator;
typedef std::list <Projectile*>::iterator ProjectileIterator;

void Interface::Update () {
  EnemyIterator p = mListOfEnemies.begin(), pEnd = mListOfEnemies.end();
  while (p != pEnd) {
    (*p)->Update();
    p++;
  }
  TowerIterator q = mListOfTowers.begin(), qEnd = mListOfTowers.end();
  while (q != qEnd) {
    (*q)->Update();
    q++;
  }
  ProjectileIterator r = mListOfProjectiles.begin(), rEnd = mListOfProjectiles.end();
  while (r != rEnd) {
    (*r)->Update();
    r++;
  }
  std::list <Entity*>::iterator iter;
  while (!mGarbageCollector.empty()) {
    iter = mGarbageCollector.begin();
    mListOfEnemies.remove((Enemy*)*iter);
    mListOfTowers.remove((Tower*)*iter);
    mListOfProjectiles.remove((Projectile*)*iter);
    delete *iter;
    mGarbageCollector.pop_front();
  }
}

void Interface::Draw () {
  //Grid draw
  EnemyIterator p = mListOfEnemies.begin(),
    pEnd = mListOfEnemies.end();
  while (p != pEnd) {
    (*p)->Draw();
    p++;
  }
  TowerIterator q = mListOfTowers.begin(), qEnd = mListOfTowers.end();
  while (q != qEnd) {
    (*q)->Draw();
    q++;
  }
  ProjectileIterator r = mListOfProjectiles.begin(), rEnd = mListOfProjectiles.end();
  while (r != rEnd) {
    (*r)->Draw();
    r++;
  }
}

void Interface::Run () {
  mDrawingClass->Run();
}

void Interface::CreateEnemy (EnemyType et, float x, float y) {
  switch(et) {
    case ET_Skeleton:
      Skeleton *aux = new Skeleton(mHome, x, y);
      aux->SetDrawingClass(mDrawingClass);
      aux->SetInterface(this);
      mListOfEnemies.push_back(aux);
      break;
  }
}

void Interface::CreateTower (TowerType tt, float x, float y) {
  switch(tt) {
    case TT_LightTower:
      LightTower *aux = new LightTower(x, y);
      aux->SetDrawingClass(mDrawingClass);
      aux->SetInterface(this);
      mListOfTowers.push_back(aux);
      break;
  }
}

Enemy* Interface::GetEnemyInRange (Vector2f position, float range) {
  Enemy *p = 0;
  EnemyIterator iter = mListOfEnemies.begin(), iterEnd = mListOfEnemies.end();
  Vector2f enemyPosition;

  while (iter != iterEnd) {
    enemyPosition = (*iter)->GetPosition();
    if (enemyPosition.Distance(position) <= range) {
      p = *iter;
      break;
    }
    iter++;
  }
  return p;
}

void Interface::CreateProjectile (ProjectileType pt, Vector2f origin, Vector2f target) {
  switch (pt) {
    case PT_None:
      break;
    case PT_LightProjectile:
      LightProjectile *aux = new LightProjectile(origin, target);
      aux->SetDrawingClass(mDrawingClass);
      aux->SetInterface(this);
      mListOfProjectiles.push_back(aux);
      break;
  }
}

void Interface::KillEnemy (Enemy *enemy) {
  EnemyIterator iter = mListOfEnemies.begin(),
                     iterEnd = mListOfEnemies.end();

  while (iter != iterEnd) {
    if (enemy == *iter) {
      mGarbageCollector.push_back(*iter);
      return;
    }
    iter++;
  }
}

void Interface::KillTower (Tower *tower) {
  TowerIterator iter = mListOfTowers.begin(),
                     iterEnd = mListOfTowers.end();

  while (iter != iterEnd) {
    if (tower == *iter) {
      mGarbageCollector.push_back(*iter);
      return;
    }
    iter++;
  }
}

void Interface::KillProjectile (Projectile *projectile) {
  ProjectileIterator iter = mListOfProjectiles.begin(),
                     iterEnd = mListOfProjectiles.end();

  while (iter != iterEnd) {
    if (projectile == *iter) {
      mGarbageCollector.push_back(*iter);
      return;
    }
    iter++;
  }
}

bool Interface::ProjectileHitsEnemy (Projectile *projectile) {
  EnemyIterator iter = mListOfEnemies.begin(),
                iterEnd = mListOfEnemies.end();

  while (iter != iterEnd) {
    if ((*iter)->CollideWithProjectile(projectile))
      return true;
    iter++;
  }
  return false;
}
