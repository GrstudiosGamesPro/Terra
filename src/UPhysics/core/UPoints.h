#pragma once
#include <origami-math/include/origami/math.hpp>

struct UPoint
{
  Vec3 a;
  Vec3 b;
  Vec3 normal;
  float depth;
  bool has_collision;
};

enum UType
{
  CUBE,
  PLANE
};

struct UCollider
{
  UType collider_type;
};

struct UColliderCube : UCollider
{
  Vec3 collider_center;
  Vec3 collider_radius;
};

struct UColliderPlane : UCollider
{
  Vec3 collider_normal;
  float collider_distance;
};
