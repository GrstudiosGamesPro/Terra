#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "../UPoints.h"

using namespace glm;

class UBody
{
public:
  // FUNCTIONS
  float get_magnitude();
  vec3 get_position();
  vec3 get_velocity();
  void apply_force(vec3 direction);
  void update_body();

  // VARIABLES
  float mass = 1.0f;
  bool use_gravity = true;
  bool is_kinematic = false;

  float magnitud = 0.0f;
  vec3 force = {0, 0, 0};
  vec3 body_position = {0, 0, 0};
  vec3 body_velocity = {0, 0, 0};

  UCollider *collision_type;
};