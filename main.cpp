#include <iostream>
#include "Interface.h"
#include <cstdlib>
#include <ctime>

int main () {
  srand(time(0));
  Interface interface;
  int numEnemies = 4, numTowers = 4;

  for (int i = 0; i < numEnemies; i++)
    interface.CreateEnemy (ET_Skeleton,   0, i*800/(numEnemies-1));

  for (int i = 0; i < numTowers; i++)
    interface.CreateTower (TT_LightTower, 300 + rand()%400, rand()%800);

  interface.Run();

  return 0;
}
