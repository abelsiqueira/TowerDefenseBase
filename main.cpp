#include <iostream>
#include "Interface.h"
#include <cstdlib>
#include <ctime>

int main () {
  srand(time(0));
  Interface interface;

  interface.ReadLevel("Maps/level2");

  interface.CreateEnemy(1, ET_Skeleton);
  interface.CreateEnemy(1, ET_Skeleton);
  for (int i = 0; i < 10; i++)
    interface.CreateEnemy(2, ET_Skeleton);

  interface.CreateTower(TT_LightTower, 500, 300);


  interface.Run();

  return 0;
}
