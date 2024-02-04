#include "UBody.h"

float UBody::get_magnitude()
{
  return magnitud;
}

Vec3 UBody::get_position()
{
  return body_position;
}

Vec3 UBody::get_velocity()
{
  return body_velocity;
}

void UBody::add_force(Vec3 direction)
{
}