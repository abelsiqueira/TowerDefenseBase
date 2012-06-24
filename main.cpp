#include <iostream>
#include "Interface.h"
#include <cstdlib>
#include <ctime>

int main () {
  srand(time(0));
  Interface interface;

  interface.AddToPath(0, 400);
  interface.AddToPath(400, 400);
  interface.AddToPath(400, 200);
  interface.AddToPath(600, 200);
  interface.AddToPath(600, 400);
  interface.AddToPath(1000, 400);

  interface.CreateEnemy(1, ET_Skeleton);
  interface.CreateEnemy(1, ET_Skeleton);
  for (int i = 0; i < 10; i++)
    interface.CreateEnemy(2, ET_Skeleton);

  interface.CreateTower(TT_LightTower, 500, 300);


  interface.Run();

  return 0;
}
