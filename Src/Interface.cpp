#include "Interface.h"

typedef std::list <Enemy*>::iterator EnemyIterator;
typedef std::list <Tower*>::iterator TowerIterator;

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
}

void Interface::Draw () {
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
}

void Interface::Run () {
  mDrawingClass->Run();
}

void Interface::CreateEnemy (EnemyType et, float x, float y) {
  switch(et) {
    case ET_Skeleton:
      Skeleton *aux = new Skeleton(x, y);
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
