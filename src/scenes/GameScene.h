#pragma once
#include <iostream>
#include "../graphics/model.h"
#include "../game/scene.h"
#include "../UPhysics/core/UPhysics.h"
#include "../graphics/camera.h"
#include "../game/GameSystem.h"

class GameScene : public scene
{
public:
  UPhysics *world_physics = nullptr;
  UBody *maked_body;
  UBody *maked_body2;
  UBody *maked_body3;
  Model *md = nullptr;
  Model *md2 = nullptr;
  Model *md3 = nullptr;

  Shader *scene_shader = nullptr;
  Camera camera = Camera();

  glm::quat rotation;

  void startScene() override;
  void updateScene(float deltatime) override;
  void onSwapBuffer() override;
};