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
