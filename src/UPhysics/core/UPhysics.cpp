#include "UPhysics.h"

void UPhysics::step_world(float elapsed_time)
{
  // elapsed_time es el tiempo transcurrido desde la última actualización

  for (UBody *body : bodys)
  {
    if (!body->is_kinematic)
    {
      body->force += gravity * body->mass;
      body->body_velocity += body->force / body->mass * elapsed_time;
      body->body_position += body->body_velocity * elapsed_time;
      body->force = Vec3(0, 0, 0);
    }
  }
}

void UPhysics::add_body(UBody *body)
{
  bodys.push_back(body);
}

UBody *UPhysics::make_body()
{
  UBody *maked_body = new UBody();
  return maked_body;
}