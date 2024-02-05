#pragma once
#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

using namespace std;

// UPhysics Libs
#include <sharedpointer/ptr.hpp>
#include "UPoints.h"
#include "body/UBody.h"

class UPhysics
{
public:
  float in_step;
  glm::vec3 gravity = glm::vec3(0.0f, -9.8f, 0.0f);
  vector<UBody *> bodys = vector<UBody *>();

  void step_world(float time_step);

  // BODY FUNCTIONS
  void clear_all_bodys();
  void add_body(UBody *body);
  UBody *make_body();

  bool CheckCollision(UBody *body1, UBody *body2);

  void ResolveCollision(UBody *body1, UBody *body2);

  bool checkCollision(UBody obj1, UBody obj2)
  {
    float distance = glm::distance(obj1.body_position, obj2.body_position);
    float combinedRadii = (obj1.collision_type->radius + obj2.collision_type->radius) / 2.0f;
    std::cout << "RADIUS: " << combinedRadii << std::endl;
    return (distance < combinedRadii);
  }

  float combinedCollision(UBody obj1, UBody obj2)
  {
    float distance = glm::distance(obj1.body_position, obj2.body_position);
    float combinedRadii = (obj1.collision_type->radius + obj2.collision_type->radius) / 2.0f;
    std::cout << "RADIUS: " << combinedRadii << std::endl;
    return combinedRadii;
  }
};