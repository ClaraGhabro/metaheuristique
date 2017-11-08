#ifndef PARTICLE_HH
# define PARTICLE_HH
/*———.
  | Includes |
  ‘———*/
# include <vector>
# include <cassert>
# include <values.h>
# include <stdlib.h>
# include "opti_func.hh"

typedef std::vector<float> VecFloat;

class Particle
{
public :
  // ctors & dtors
  Particle(OptiFunc* func, float c1, float c2, float c3);
 ~Particle(){}
  float compute();

  void update(const VecFloat gbest);
    
  VecFloat get_p_best() const;

private :
  // Return a random value between min and max
  float get_rand(float min, float max);

private :
  // Current position
  VecFloat cur_position;
  // Current speed for each dimension
  VecFloat cur_speed;
  // Best position seen by the particle
  VecFloat best_position;
  // Best value seen by the particle
  float best_value;
  // Function to optimize
  OptiFunc* function;
  // Maximum velocity
  float v_max;
  // The factors in equation that compute new velocity of a particle
  float c1;
  float c2;
  float c3;
};

# include "particle.hxx"

#endif /* !PARTICLE HH */
