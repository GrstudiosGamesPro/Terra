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

  float CalculatePenetrationDepth(const UBody *body1, const UBody *body2)
  {
    float penetrationX = std::abs(body1->body_position.x - body2->body_position.x) - (body1->collision_type->collider_radius.x + body2->collision_type->collider_radius.x) / 2.0f;
    float penetrationY = std::abs(body1->body_position.y - body2->body_position.y) - (body1->collision_type->collider_radius.y + body2->collision_type->collider_radius.y) / 2.0f;

    return std::min(penetrationX, penetrationY);
  }

  glm::vec3 CalculateCollisionNormal(const UBody *body1, const UBody *body2)
  {
    glm::vec3 normal(0.0f);

    float overlapX = (body1->collision_type->collider_radius.x + body2->collision_type->collider_radius.x) / 2.0f - std::abs(body1->body_position.x - body2->body_position.x);
    float overlapY = (body1->collision_type->collider_radius.y + body2->collision_type->collider_radius.y) / 2.0f - std::abs(body1->body_position.y - body2->body_position.y);

    if (overlapX < overlapY)
    {
      normal.x = (body1->body_position.x < body2->body_position.x) ? -1.0f : 1.0f;
    }
    else
    {
      normal.y = (body1->body_position.y < body2->body_position.y) ? -1.0f : 1.0f;
    }

    return glm::normalize(normal);
  }

  bool checkCollision(UBody obj1, UBody obj2)
  {
    float distance = glm::distance(obj1.body_position, obj2.body_position);
    float combinedRadii = obj1.collision_type->radius / 2.0f + obj2.collision_type->radius / 2.0f;
    return distance < combinedRadii;
  }
};