#pragma once
#include <iostream>
#include <vector>
#include "../components/ECS.h"
#include <sharedpointer/ptr.hpp>

using namespace std;

class scene
{
public:
  vector<Shared<Entity>> entity = vector<Shared<Entity>>();

  scene();
  ~scene();

  virtual void startScene()
  {
  }

  virtual void updateScene()
  {
    for (Shared<Entity> g : entity)
    {
      g.get()->draw();
    }
  }

  virtual void onSwapBuffer()
  {
  }

  Entity *makeEntity()
  {
    Shared<Entity> newEntity = new_shared<Entity>();
    entity.push_back(newEntity);

    return newEntity.get();
  }

  int countEntityScenes()
  {
    return entity.size();
  }
};
