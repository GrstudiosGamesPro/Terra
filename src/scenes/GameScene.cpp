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
    maked_body->body_position.y = 15.0f;

    maked_body->freeze_z = true;

    maked_body2 = world_physics->make_body();
    world_physics->add_body(maked_body2);
    maked_body2->is_kinematic = true;
    maked_body2->body_position.y = -2;

    maked_body3 = world_physics->make_body();
    world_physics->add_body(maked_body3);
    maked_body3->is_kinematic = true;
    maked_body3->body_position.y = -1.0f;
    maked_body3->body_position.x = -3.0f;

    maked_body4 = world_physics->make_body();
    world_physics->add_body(maked_body4);
    maked_body4->is_kinematic = true;
    maked_body4->body_position.y = -1.0f;
    maked_body4->body_position.x = 3.0f;
  }
  else
  {
    std::cout << "World physics not found" << std::endl;
  }

  md = new Model("assets/Sphere.fbx");
  md2 = new Model("assets/Sphere.fbx");
  md3 = new Model("assets/Sphere.fbx");
  md4 = new Model("assets/Sphere.fbx");
  scene_shader = new Shader("assets/shaders/default.vert", "assets/shaders/default.frag");
}

void GameScene::updateScene(float deltatime)
{
  scene_shader->use();
  glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
  glm::mat4 view = camera.GetViewMatrix();
  scene_shader->setMat4("projection", projection);
  scene_shader->setMat4("view", view);
  scene_shader->setVec3("viewPos", camera.Position);
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::mat4(1.0f);
  model = glm::translate(model, glm::vec3(maked_body->body_position.x, maked_body->body_position.y, maked_body->body_position.z));

  glm::quat rotationZ = glm::angleAxis(glm::radians(maked_body->body_rotation.x), glm::vec3(0.0f, 0.0f, 1.0f));
  glm::quat rotationY = glm::angleAxis(glm::radians(maked_body->body_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
  glm::quat rotationX = glm::angleAxis(glm::radians(maked_body->body_rotation.z), glm::vec3(1.0f, 0.0f, 0.0f));

  rotation = rotationZ * rotationY * rotationX;

  model *= glm::mat4_cast(rotation);

  model = glm::scale(model, glm::vec3(maked_body->collision_type->radius / 2.0f));

  scene_shader->setMat4("model", model);
  md->Draw(*scene_shader);

  model = glm::mat4(1.0f);
  model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
  model = glm::scale(model, glm::vec3(maked_body2->collision_type->radius / 2.0f));
  scene_shader->setMat4("model", model);
  md2->Draw(*scene_shader);

  model = glm::mat4(1.0f);
  model = glm::translate(model, maked_body3->get_position());
  model = glm::scale(model, glm::vec3(maked_body3->collision_type->radius / 2.0f));
  scene_shader->setMat4("model", model);
  md3->Draw(*scene_shader);

  model = glm::mat4(1.0f);
  model = glm::translate(model, maked_body4->get_position());
  model = glm::scale(model, glm::vec3(maked_body4->collision_type->radius / 2.0f));
  scene_shader->setMat4("model", model);
  md4->Draw(*scene_shader);

  maked_body4->collision_type->radius += 0.001f;

  float force_multiplier = 100;

  if (glfwGetKey(GameSystem::window, GLFW_KEY_W) == GLFW_PRESS)
  {
    maked_body->force.z -= force_multiplier;
  }

  if (glfwGetKey(GameSystem::window, GLFW_KEY_A) == GLFW_PRESS)
  {
    maked_body->force.x -= force_multiplier;
  }

  if (glfwGetKey(GameSystem::window, GLFW_KEY_S) == GLFW_PRESS)
  {
    maked_body->force.z += force_multiplier;
  }

  if (glfwGetKey(GameSystem::window, GLFW_KEY_D) == GLFW_PRESS)
  {
    maked_body->force.x += force_multiplier;
  }

  if (world_physics != nullptr)
  {
    world_physics->step_world(static_cast<float>(1) / 60);

    // vec3 aabb_min = maked_body2->body_position - vec3(maked_body2->collision_type->collider_radius * 2.0f);
    // vec3 aabb_max = maked_body2->body_position + vec3(maked_body2->collision_type->collider_radius * 2.0f);

    // if (maked_body->body_position.x >= aabb_min.x &&
    //     maked_body->body_position.x <= aabb_max.x &&
    //     maked_body->body_position.y >= aabb_min.y &&
    //     maked_body->body_position.y <= aabb_max.y &&
    //     maked_body->body_position.z >= aabb_min.z &&
    //     maked_body->body_position.z <= aabb_max.z)
    // {
    //   // Calcular la magnitud de la velocidad antes de la colisión
    //   float preCollisionSpeed = glm::length(maked_body->body_velocity);

    //   // Aplicar rebote proporcional a la velocidad anterior
    //   maked_body->body_velocity = -maked_body->body_velocity * (0 * preCollisionSpeed);
    // }
  }
}

void GameScene::onSwapBuffer()
{
  // CODE HERE
}