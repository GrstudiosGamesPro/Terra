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

  md = new Model("assets/Box.fbx");
  scene_shader = new Shader("assets/shaders/default.vert", "assets/shaders/default.frag");
}

void GameScene::updateScene()
{
  if (world_physics != nullptr)
  {
    world_physics->step_world(static_cast<float>(1) / 165);
  }

  scene_shader->use();
  glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
  glm::mat4 view = camera.GetViewMatrix();
  scene_shader->setMat4("projection", projection);
  scene_shader->setMat4("view", view);
  scene_shader->setVec3("viewPos", camera.Position);

  glm::mat4 model = glm::mat4(1.0f);
  model = glm::mat4(1.0f);
  model = glm::translate(model, glm::vec3(maked_body->body_position.x, maked_body->body_position.y, maked_body->body_position.z));
  model = glm::scale(model, glm::vec3(0.5f));
  scene_shader->setMat4("model", model);
  md->Draw(*scene_shader);
}

void GameScene::onSwapBuffer()
{
  // CODE HERE
}