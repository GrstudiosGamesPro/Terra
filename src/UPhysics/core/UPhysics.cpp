#include "UPhysics.h"

void UPhysics::step_world(float time_step)
{
  for (UBody *body : bodys)
  {
    body->force += gravity * body->mass;
    body->body_velocity += body->force / body->mass * time_step;
    body->body_position += body->body_velocity * time_step;

    std::cout << "BODY POSITION -> "
              << " X: " << body->body_position.x << " Y: " << body->body_position.y << " Z: " << body->body_position.z << std::endl;
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