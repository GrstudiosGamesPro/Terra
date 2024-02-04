#pragma once
#include <iostream>
#include <vector>
using namespace std;

// UPhysics Libs
#include <sharedpointer/ptr.hpp>
#include "body/UBody.h"

class UPhysics
{
public:
  Vec3 gravity = {0.0f, -9.8f, 0.0f};
  vector<UBody *> bodys = vector<UBody *>();

  void step_world(float time_step);

  // BODY FUNCTIONS
  void clear_all_bodys();
  void add_body(UBody *body);
  UBody *make_body();
};