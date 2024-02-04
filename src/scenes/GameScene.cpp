#include "GameScene.h"
#include <iostream>

void GameScene::startScene()
{
  makeEntity();

  world_physics = new UPhysics();

  if (world_physics != nullptr)
  {
    std::cout << "World physics maked" << std::endl;

    maked_body = world_physics->make_body();
    world_physics->add_body(maked_body);
  }
  else
  {
    std::cout << "World physics not found" << std::endl;
  }
}

void GameScene::updateScene()
{
  if (world_physics != nullptr)
  {
    world_physics->step_world(static_cast<float>(1) / 60);

    if (maked_body->get_position().y >= 5.0f)
    {
      maked_body->body_position.y = 5.0f;
    }
  }
}

void GameScene::onSwapBuffer()
{
  // CODE HERE
}