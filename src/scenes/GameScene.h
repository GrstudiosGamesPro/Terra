#pragma once
#include <iostream>
#include "../graphics/model.h"
#include "../game/scene.h"
#include "../UPhysics/core/UPhysics.h"

class GameScene : public scene
{
public:
  UPhysics *world_physics = nullptr;
  UBody *maked_body;

  void startScene() override;
  void updateScene() override;
  void onSwapBuffer() override;
};