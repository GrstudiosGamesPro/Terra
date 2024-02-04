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
  SPHERE,
  PLANE
};

struct UCollider
{
  UType collider_type;
};

struct UColliderSphere : UCollider
{
  Vec3 collider_center;
  float collider_radius;
};

struct UColliderPlane : UCollider
{
  Vec3 collider_normal;
  float collider_distance;
};
