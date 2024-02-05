#include "UBody.h"

using namespace glm;

float UBody::get_magnitude()
{
  return magnitud;
}

vec3 UBody::get_position()
{
  return body_position;
}

vec3 UBody::get_velocity()
{
  return body_velocity;
}

void UBody::update_body()
{
  if (collision_type != nullptr)
  {
  }
}

void UBody::apply_force(vec3 direction)
{
  body_velocity = vec3(0.0f, 0.0f, 0.0f);
  force += direction;
}