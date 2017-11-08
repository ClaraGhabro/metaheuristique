#include "particle.hh"


Particle::Particle(OptiFunc* func, float c1, float c2, float c3)
{
  float down = func->get_range(0);
  float up = func->get_range(1);
  function = func;
  c1 = c1;
  c2 = c2;
  c3 = c3;
  v_max = up - down;
  // Initialize with random values
  for (unsigned int i = 0; i < func->get_dimension(); i++)
  {
    cur_position.push_back(get_rand(down, up));
    //
    this->cur_speed.push_back(v_max * get_rand(0.0, 1.0));
    this->cur_speed.push_back(0);
  }
  best_value = MAXFLOAT;
}

float Particle::compute()
{
  float res = function->compute(cur_position);
  if (res < best_value)
  {
    best_value = res;
    best_position = cur_position;
  }
  return res;
}


void Particle::update(const VecFloat gbest)
{
  VecFloat newSpeed;
  assert(gbest.size() >= function->get_dimension());
  // update current speed and current position
  for (unsigned int i = 0; i < function->get_dimension(); i++)
  {
    // update speed
    newSpeed.push_back(c1 * this->cur_speed[i]
                       + get_rand(0.0, c2) * (best_position[i] - cur_position[i])
                       + get_rand(0.0, c3) * (gbest[i] - cur_position[i]));
    // update position
    cur_position[i] += newSpeed[i];
    // Make sure position is in search interval
    if (cur_position[i] > function->get_range(1))
      cur_position[i] = function->get_range(1);
    if (cur_position[i] < function->get_range(0))
      cur_position[i] = function->get_range(0);
  }
  this->cur_speed = newSpeed;
}


float Particle::get_rand(float min, float max)
{
  return (float) ((max - min)*(rand()/(float)RAND_MAX) + min);
}
