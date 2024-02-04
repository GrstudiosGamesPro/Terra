#include <iostream>
#include "game/GameSystem.h"
#include "scenes/GameScene.h"

int main()
{
     GameSystem *grp = new GameSystem();
     GameScene *game = new GameScene();
     grp->startEngine(game);

     return 0;
}