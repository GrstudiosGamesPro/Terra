#include "UPhysics.h"

void UPhysics::step_world(float elapsed_time)
{
  in_step = elapsed_time;

  for (UBody *body : bodys)
  {
    if (!body->is_kinematic)
    {
      body->force += gravity * body->mass;

      glm::vec3 acceleration = body->force / body->mass;
      body->body_velocity += acceleration * elapsed_time;

      if (body->freeze_x)
      {
        body->force.x = 0;
        body->body_velocity.x = 0;
        body->body_position.x = body->body_position.x;
        body->body_position.y += body->body_velocity.y * elapsed_time;
        body->body_position.z += body->body_velocity.z * elapsed_time;
      }
      else if (body->freeze_y)
      {
        body->force.y = 0;
        body->body_velocity.y = 0;
        body->body_position.y = body->body_position.y;
        body->body_position.x += body->body_velocity.x * elapsed_time;
        body->body_position.z += body->body_velocity.z * elapsed_time;
      }
      else if (body->freeze_z)
      {
        body->force.z = 0;
        body->body_velocity.z = 0;
        body->body_position.z = body->body_position.z;
        body->body_position.x += body->body_velocity.x * elapsed_time;
        body->body_position.y += body->body_velocity.y * elapsed_time;
      }
      else
      {
        body->body_position += body->body_velocity * elapsed_time;
      }

      // Resto de la lógica para la actualización del cuerpo (gravedad, colisiones, etc.)
      // ...

      body->force = glm::vec3(0, 0, 0);
      glm::vec3 torque = body->calculateTorque();

      glm::vec3 angular_acceleration = torque / body->moment_of_inertia;

      body->body_angular_velocity += angular_acceleration * elapsed_time;
    }

    for (UBody *body2 : bodys)
    {
      if (body != body2 && body->collision_type != nullptr && body2->collision_type != nullptr)
      {
        if (CheckCollision(body, body2))
        {
          ResolveCollision(body, body2);
        }
      }
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

bool UPhysics::CheckCollision(UBody *body1, UBody *body2)
{
  float distanceX = std::abs(body1->body_position.x - body2->body_position.x);
  float distanceY = std::abs(body1->body_position.y - body2->body_position.y);

  float combinedHalfWidths = (body1->collision_type->collider_radius.x + body2->collision_type->collider_radius.x) / 2.0f;
  float combinedHalfHeights = (body1->collision_type->collider_radius.y + body2->collision_type->collider_radius.y) / 2.0f;

  return distanceX < combinedHalfWidths && distanceY < combinedHalfHeights;
}

void UPhysics::ResolveCollision(UBody *body1, UBody *body2)
{
  // vec3 aabb_min = body2->body_position - vec3(body2->collision_type->collider_radius);
  // vec3 aabb_max = body2->body_position + vec3(body2->collision_type->collider_radius);

  // if (body1->body_position.x >= aabb_min.x &&
  //     body1->body_position.x <= aabb_max.x &&
  //     body1->body_position.y >= aabb_min.y &&
  //     body1->body_position.y <= aabb_max.y &&
  //     body1->body_position.z >= aabb_min.z &&
  //     body1->body_position.z <= aabb_max.z)
  // {
  //   body1->body_velocity += gravity * body1->mass;

  //   vec3 acceleration = (body1->force / body1->mass) + gravity;

  //   body1->body_velocity += acceleration;
  //   body1->body_position += body1->body_velocity;
  // }

  if (checkCollision(*body1, *body2))
  {
    float volume1 = (4.0f / 3.0f) * glm::pi<float>() * std::pow(body1->collision_type->radius, 3);
    float volume2 = (4.0f / 3.0f) * glm::pi<float>() * std::pow(body2->collision_type->radius, 3);

    float mass1 = body1->collision_type->density * volume1;
    float mass2 = body2->collision_type->density * volume2;

    glm::vec3 relativeVelocity = body1->body_velocity - body2->body_velocity;
    glm::vec3 collisionNormal = glm::normalize(body1->get_position() - body2->get_position());

    float coeficiente_friccion = body1->collision_type->friction * 100.0f;
    glm::vec3 fuerza_friccion = -coeficiente_friccion * glm::dot(body1->body_velocity, collisionNormal) * collisionNormal;

    if (glm::length(fuerza_friccion) >= 200)
    {
      body1->apply_force(fuerza_friccion);
      body2->apply_force(-fuerza_friccion);
    }

    float coeficiente_restitucion = 0.1f;
    glm::vec3 velocidad_despues_colision = (mass1 * body1->body_velocity + mass2 * body2->body_velocity +
                                            coeficiente_restitucion * mass2 * glm::dot(body2->body_velocity - body1->body_velocity, collisionNormal) * collisionNormal) /
                                           (mass1 + mass2);

    body1->body_velocity = velocidad_despues_colision;

    glm::vec3 nueva_posicion = body2->get_position() + collisionNormal * (body1->collision_type->radius + body2->collision_type->radius) / 2.0f;
    body1->set_position(nueva_posicion);
  }
}
