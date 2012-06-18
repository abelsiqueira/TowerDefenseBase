#include <iostream>
#include "Interface.h"

int main () {
  Interface interface;

  interface.CreateTower (TT_LightTower, 50, 50);
  interface.CreateTower (TT_LightTower, 150, 50);
  interface.CreateEnemy (ET_Skeleton,   50, 150);
  interface.CreateEnemy (ET_Skeleton,  150, 150);
  interface.Run();

  return 0;
}
