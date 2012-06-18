#include "Interface.h"

void Interface::Update () {
  std::list <Enemy*>::iterator p = mListOfEnemies.begin(),
    pEnd = mListOfEnemies.end();
  while (p != pEnd) {
    (*p)->Update();
    p++;
  }
  std::list <Tower*>::iterator q = mListOfTowers.begin(),
    qEnd = mListOfTowers.end();
  while (q != qEnd) {
    (*q)->Update();
    q++;
  }
}

void Interface::Draw () {
  std::list <Enemy*>::iterator p = mListOfEnemies.begin(),
    pEnd = mListOfEnemies.end();
  while (p != pEnd) {
    (*p)->Draw();
    p++;
  }
  std::list <Tower*>::iterator q = mListOfTowers.begin(),
    qEnd = mListOfTowers.end();
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
      mListOfEnemies.push_back(aux);
      break;
  }
}

void Interface::CreateTower (TowerType tt, float x, float y) {
  switch(tt) {
    case TT_LightTower:
      LightTower *aux = new LightTower(x, y);
      aux->SetDrawingClass(mDrawingClass);
      mListOfTowers.push_back(aux);
      break;
  }
}
