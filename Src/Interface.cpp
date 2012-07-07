/* Copyright 2012 - Abel Soares Siqueira
 * 
 * This file is part of TowerDefenseBase.
 * 
 * TowerDefenseBase is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * TowerDefenseBase is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with TowerDefenseBase.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "Interface.h"
#include <iostream>
#include <sstream>
#include <fstream>

typedef std::list <Enemy*>::iterator EnemyIterator;
typedef std::list <Tower*>::iterator TowerIterator;
typedef std::list <Projectile*>::iterator ProjectileIterator;

Interface::~Interface () {
  {
    EnemyIterator iter = mListOfEnemies.begin(), iterEnd = mListOfEnemies.end();
    while (iter != iterEnd) {
      mGarbageCollector.push_back(*iter);
      iter++;
    }
    iter = mEnemiesToBeCreated.begin();
    iterEnd = mEnemiesToBeCreated.end();
    while (iter != iterEnd) {
      mGarbageCollector.push_back(*iter);
      iter++;
    }
  }
  {
    TowerIterator iter = mListOfTowers.begin(), iterEnd = mListOfTowers.end();
    while (iter != iterEnd) {
      mGarbageCollector.push_back(*iter);
      iter++;
    }
  }
  {
    ProjectileIterator iter = mListOfProjectiles.begin(), iterEnd = mListOfProjectiles.end();
    while (iter != iterEnd) {
      mGarbageCollector.push_back(*iter);
      iter++;
    }
  }
  std::list<Wave>::iterator wIter = mWaves.begin(), wEnd = mWaves.end();
  while (wIter != wEnd) {
    EnemyIterator iter = wIter->begin(), iterEnd = wIter->end();
    while (iter != iterEnd) {
      mGarbageCollector.push_back(*iter);
      iter++;
    }
    wIter++;
  }
  CleanTheGarbageCollector();
  delete mDrawingClass;
}



void Interface::CleanTheGarbageCollector () {
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

void Interface::Update () {
  if (inMenu)
    return;
  mWaveTimer++; mEnemyTimer++;
  if ( (mWaveTimer > mFramesBetweenWaves) && (!mWaves.empty()) ) {
    EnemyIterator begin = mWaves.front().begin(),
                  end   = mWaves.front().end();
    mEnemiesToBeCreated.insert(mEnemiesToBeCreated.end(), begin, end);
    mWaves.pop_front();
    mWaveTimer -= mFramesBetweenWaves;
    mEnemyTimer = 0;
  }

  if ( (mEnemyTimer > mFramesBetweenEnemies) && (!mEnemiesToBeCreated.empty()) ) {
    mListOfEnemies.push_back(mEnemiesToBeCreated.front());
    mEnemiesToBeCreated.pop_front();
    mEnemyTimer -= mFramesBetweenEnemies;
  }

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
  CleanTheGarbageCollector();

  if ( (mWaves.empty()) && mEnemiesToBeCreated.empty() && mListOfEnemies.empty() )
    mDrawingClass->Done();
}

void Interface::Draw () {

  //Grid draw
  int numLines = mMapSize.x/mTileSize;
  int numColumns = mMapSize.y/mTileSize;
  Vector3i color(30, 30, 30);

  //Draw background per tile
  for (int i = 0; i < numLines; i++) {
    for (int j = 0; j < numColumns; j++) {
      float x = i*mTileSize, y = j*mTileSize;
      mDrawingClass->DrawBackground(x, y);
    }
  }
  //

  //Grid lines
/*   for (int i = 1; i <= numLines; i++) {
 *     mDrawingClass->DrawLine(i*mTileSize, 0, i*mTileSize, mMapSize.y, color, 1);
 *   }
 *   for (int j = 1; j <= numColumns; j++) {
 *     mDrawingClass->DrawLine(0, j*mTileSize, mMapSize.x, j*mTileSize, color, 1);
 *   }
 */
  //Grid lines

  //Draw path
  for (size_t k = 0; k < ConstHorizontalTiles*ConstVerticalTiles; k++) {
    char aux = mGrid[k];
    if (aux == 'o') {
      size_t i = k%ConstHorizontalTiles, j = k/ConstHorizontalTiles;
      mDrawingClass->DrawFilledRectangle(i*mTileSize, j*mTileSize, (i+1)*mTileSize,
          (j+1)*mTileSize, 139, 69, 19);
    }
  }
/*   std::list <Vector2f>::const_iterator iter = mPath.begin(), tmp,
 *     iterEnd = mPath.end();
 *   while (iter != iterEnd) {
 *     tmp = iter;
 *     iter++;
 *     if (iter == iterEnd)
 *       break;
 *     mDrawingClass->DrawLine(*tmp, *iter, 139, 69, 19, 1.0*mTileSize);
 *   }
 */
  //Draw path

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

  if (mInsertingTower) {
    Vector2f position = mDrawingClass->GetMousePosition();
    position.x = static_cast<int>(position.x/mTileSize)*mTileSize;
    position.y = static_cast<int>(position.y/mTileSize)*mTileSize;
    position.x += mTileSize/2;
    position.y += mTileSize/2;
    Vector3i color (255, 255, 255);
    mDrawingClass->DrawCircle(position, mTileSize/2, color, 1);
  }

  mDrawingClass->DrawFilledRoundedRectangle(mSpawn.x - mTileSize, mSpawn.y - mTileSize,
      mSpawn.x + mTileSize, mSpawn.y + mTileSize, 10, 10, 50, 200, 50);
  mDrawingClass->DrawFilledRoundedRectangle(mHome.x - mTileSize, mHome.y - mTileSize,
      mHome.x + mTileSize, mHome.y + mTileSize, 10, 10, 150, 100, 50);

  DrawHud();
  if (inMenu) {
    DrawMenu();
  }
}

void Interface::Run () {
  mDrawingClass->Run();
}

void Interface::CreateEnemy (uint wave, EnemyType et, float x, float y) {
  //Add enemy to the mWaves
  while (mWaves.size() < wave) {
    Wave aux;
    mWaves.push_back(aux);
  }
  std::list<Wave>::iterator iter = mWaves.begin();
  for (uint i = 1; i < wave; i++)
    iter++;
  
  switch(et) {
    case ET_Skeleton:
      Skeleton *aux = new Skeleton(mHome, x, y);
      aux->SetDrawingClass(mDrawingClass);
      aux->SetInterface(this);
      aux->SetPath(mPath.begin(), mPath.end());
      iter->push_back(aux);
      break;
  }
}

void Interface::CreateEnemy (uint wave, EnemyType et) {
  //Add enemy to the mWaves
  while (mWaves.size() < wave) {
    Wave aux;
    mWaves.push_back(aux);
  }
  std::list<Wave>::iterator iter = mWaves.begin();
  for (uint i = 1; i < wave; i++)
    iter++;
  
  int x = mPath.front().x, y = mPath.front().y;
  switch(et) {
    case ET_Skeleton:
      Skeleton *aux = new Skeleton(mHome, x, y);
      aux->SetDrawingClass(mDrawingClass);
      aux->SetInterface(this);
      aux->SetPath(mPath.begin(), mPath.end());
      iter->push_back(aux);
      break;
  }
}

void Interface::CreateEnemy (EnemyType et, float x, float y) {
  switch(et) {
    case ET_Skeleton:
      Skeleton *aux = new Skeleton(mHome, x, y);
      aux->SetDrawingClass(mDrawingClass);
      aux->SetInterface(this);
      aux->SetPath(mPath.begin(), mPath.end());
      mListOfEnemies.push_back(aux);
      break;
  }
}

void Interface::CreateEnemy (EnemyType et) {
  int x = mPath.front().x, y = mPath.front().y;
  switch(et) {
    case ET_Skeleton:
      Skeleton *aux = new Skeleton(mHome, x, y);
      aux->SetDrawingClass(mDrawingClass);
      aux->SetInterface(this);
      aux->SetPath(mPath.begin(), mPath.end());
      mListOfEnemies.push_back(aux);
      break;
  }
}

void Interface::CreateTower (TowerType tt, float x, float y) {
  int i = static_cast<int>(x/mTileSize), j = static_cast<int>(y/mTileSize);
  mGrid[i + j*ConstHorizontalTiles] = 't';
  x = (i + 0.5)*mTileSize;
  y = (j + 0.5)*mTileSize;
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

  mGold += enemy->GetReward();
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

void Interface::DrawHud () {
  float border = mTileSize/8;
  mDrawingClass->DrawFilledRectangle(mMapSize.x, 0, mWindowSize.x, mMapSize.y, 250, 0, 0);
  mDrawingClass->DrawFilledRoundedRectangle(mMapSize.x + border, border, 
      mWindowSize.x - border, mMapSize.y - border, 10, 10, 10, 0, 0);

  if (!mWaves.empty()) {
    float timeUntilNextWave = mFramesBetweenWaves - mWaveTimer;
    timeUntilNextWave /= ConstFps;
    timeUntilNextWave = (int) timeUntilNextWave;
    std::stringstream aux;
    aux << "Next Wave: ";
    aux.fill('0');
    aux.width(2);
    aux << timeUntilNextWave;

    float x = mMapSize.x + (mWindowSize.x - mMapSize.x)/2;
    mDrawingClass->Write(x, mTileSize, aux.str(), 
        255, 255, 255, FA_center);

  }
  float x = mMapSize.x + (mWindowSize.x - mMapSize.x)/2,
        y = 3*mTileSize;
  float dif = mTileSize*1.5;
  LightTower lightTower1(this, x - dif, y);
  LightTower lightTower2(this, x      , y);
  LightTower lightTower3(this, x + dif, y);
  LightTower lightTower4(this, x - dif, y + dif);
  LightTower lightTower5(this, x      , y + dif);
  LightTower lightTower6(this, x + dif, y + dif);
  Vector3i color(0, 0, 0);
  lightTower1.Draw();
  mDrawingClass->SmallWrite(lightTower1.GetPosition(), "1", color, FA_center);
  lightTower2.Draw();
  mDrawingClass->SmallWrite(lightTower2.GetPosition(), "2", color, FA_center);
  lightTower3.Draw();
  mDrawingClass->SmallWrite(lightTower3.GetPosition(), "3", color, FA_center);
  lightTower4.Draw();
  mDrawingClass->SmallWrite(lightTower4.GetPosition(), "4", color, FA_center);
  lightTower5.Draw();
  mDrawingClass->SmallWrite(lightTower5.GetPosition(), "5", color, FA_center);
  lightTower6.Draw();
  mDrawingClass->SmallWrite(lightTower6.GetPosition(), "6", color, FA_center);

  std::stringstream aux;
  aux << "Gold: ";
  aux.fill('0');
  aux.width(3);
  aux << mGold;
  y += 4*dif;
  mDrawingClass->Write(x, y, aux.str(), 255, 255, 255, FA_center);
}

void Interface::Keyboard (KeyCode kc) {
  switch (kc) {
    case KeyQ:
    case KeyEscape:
      mDrawingClass->Done();
      break;
    case Key1:
      InsertTower(kc);
      break;
    case KeyP:
      if (inMenu) inMenu = false;
      else if (!inMenu) inMenu = true;
      break;
    default:
      break;
  }
}

void Interface::InsertTower (KeyCode kc) {
  switch (kc) {
    case Key1:
      mNextTower = 1;
      if (mGold < ConstLightTowerCost)
        mNextTower = 0;
      else 
        mInsertingTower = true;
      break;
    default:
      mNextTower = 0;
      break;
  }
}

void Interface::Mouse (MouseCode ) {
  if (!mInsertingTower)
    return;
  Vector2f position = mDrawingClass->GetMousePosition();
  int i = static_cast<int>(position.x/mTileSize);
  int j = static_cast<int>(position.y/mTileSize);
  if (mGrid[i + j*ConstHorizontalTiles] != '.')
    return;
  switch (mNextTower) {
    case 1:
      CreateTower (TT_LightTower, position.x, position.y);
      mGold -= ConstLightTowerCost;
      mInsertingTower = false;
      break;
    default:
      break;
  }
}

void Interface::ReadLevel (const char *level) {
  std::ifstream file(level);
  size_t N = ConstHorizontalTiles*ConstVerticalTiles;
  int startX = ConstHorizontalTiles, startY = ConstVerticalTiles;
  bool hasPath = false;

  mGrid = new char[N];
  for (size_t k = 0; k < N; k++) {
    file >> mGrid[k];
    if (mGrid[k] == 'S') {
      startX = k%ConstHorizontalTiles;
      startY = k/ConstHorizontalTiles;
      hasPath = true;
    }
  }

  mSpawn.x = (startX + 0.5)*mTileSize;
  mSpawn.y = (startY + 0.5)*mTileSize;

  while (hasPath) {
    AddToPath((startX+0.5)*mTileSize, (startY+0.5)*mTileSize);
    mGrid[startX + startY*ConstHorizontalTiles] = 'o';
    hasPath = false;
    char aux;
    int i = startX - 1, j = startY;

    aux = mGrid[i + j*ConstHorizontalTiles];
    if ( (aux == 'x') || (aux == 'E') ) {
      startX = i;
      startY = j;
      hasPath = true;
    }
    i = startX + 1, j = startY;

    if (!hasPath) {
      aux = mGrid[i + j*ConstHorizontalTiles];
      if ( (aux == 'x') || (aux == 'E') ) {
        startX = i;
        startY = j;
        hasPath = true;
      }
      i = startX, j = startY + 1;
    }

    if (!hasPath) {
      aux = mGrid[i + j*ConstHorizontalTiles];
      if ( (aux == 'x') || (aux == 'E') ) {
        startX = i;
        startY = j;
        hasPath = true;
      }
      i = startX, j = startY - 1;
    }

    if (!hasPath) {
      aux = mGrid[i + j*ConstHorizontalTiles];
      if ( (aux == 'x') || (aux == 'E') ) {
        startX = i;
        startY = j;
        hasPath = true;
      }
    }
  }

  mHome.x = (startX + 0.5)*mTileSize;
  mHome.y = (startY + 0.5)*mTileSize;

}

void Interface::DrawMenu () {
  mDrawingClass->DrawFilledRectangle(0, 0, mWindowSize.x, mWindowSize.y,
      50, 50, 50, 150);
  mDrawingClass->BigWrite(mWindowSize.x/2, mWindowSize.y/10, "PAUSE",
      255, 255, 255, FA_center);
}
