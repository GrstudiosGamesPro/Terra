#include "UPhysics.h"

void UPhysics::step_world(float elapsed_time)
{
  // elapsed_time es el tiempo transcurrido desde la última actualización

  for (UBody *body : bodys)
  {
    body->force += gravity * body->mass;

    // Utiliza el tiempo transcurrido para controlar la velocidad de la simulación
    body->body_velocity += body->force / body->mass * elapsed_time;

    body->body_position += body->body_velocity * elapsed_time;

    // Restablece la fuerza para el siguiente paso de la simulación
    body->force = Vec3(0, 0, 0);
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