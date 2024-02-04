#pragma once
#include <iostream>
#include "../graphics/model.h"
#include "../game/scene.h"
#include "../UPhysics/core/UPhysics.h"
#include "../graphics/camera.h"

class GameScene : public scene
{
public:
  UPhysics *world_physics = nullptr;
  UBody *maked_body;
  Model *md = nullptr;

  Shader *scene_shader = nullptr;
  Camera camera = Camera();

  void startScene() override;
  void updateScene() override;
  void onSwapBuffer() override;
};