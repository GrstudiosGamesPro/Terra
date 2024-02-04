#pragma once
#include <origami/math.hpp>

class UTransform
{
public:
  Vec3 transform_position = {0, 0, 0};
  Vec3 transform_scale = {0, 0, 0};
  Quat transform_rotation = {0, 0, 0, 0};
};