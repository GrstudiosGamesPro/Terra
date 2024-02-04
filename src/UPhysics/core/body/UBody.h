#pragma once
#include <origami/math.hpp>

class UBody
{
public:
  // VARIABLES
  float mass = 1.0f;
  bool use_gravity = true;
  bool is_kinematic = true;

  float magnitud = 0.0f;
  float density = 0.0f;
  Vec3 force = {0, 0, 0};
  Vec3 body_position = {0, 0, 0};
  Vec3 body_velocity = {0, 0, 0};

  // FUNCTIONS
  float get_magnitude();
  Vec3 get_position();
  Vec3 get_velocity();
  void add_force(Vec3 direction);
};