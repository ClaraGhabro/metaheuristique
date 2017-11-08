#ifndef SWARM_HH
# define SWARM_HH


/*———.
| Includes |
‘———*/
# include <vector>
# include <stdlib.h>
# include <list>
# include <iomanip>
# include "opti_func.hh"
# include "particle.hh"

typedef std::vector<float> VecFloat;
typedef std::vector<Particle> VecParticle;
typedef std::list<float> ListFloat;


# define NB_ITER 2000
# define NB_RUN 101
# define NB_PARTICLES 40
# define C1 1.0
# define C2 2.0
# define C3 2.0



class Swarm
{
public :
  // ctors & dtors
  Swarm(OptiFunc* f, unsigned int iter, unsigned int nbrun,
        unsigned int nbparticles, float c1, float c2, float c3);
  Swarm(OptiFunc* f, unsigned int iter, unsigned int nbrun,
        unsigned int nbparticles);
  Swarm(OptiFunc* f);
  Swarm();
 ~Swarm(){}

  // function to find the global minimum of “function”
  void resolve(int precision = 4);

  // function to analysis the influence of some parameters on the algorithm efficiency
  // It does a few runs and display some useful average values
  void analysis(int precision = 6);

  // Accessors
  OptiFunc* get_function() const;
  void set_function(OptiFunc* f);
  unsigned int get_nb_particles() const;
  void set_nb_particles(unsigned int nb);
  unsigned int get_nb_iter() const;
  void set_nb_iter(unsigned int iter);
  // Display Solution
  void print_solution(int precision);

private :
  // Initialize the particles
  void initialize_swarm()
  {
    gbest = MAXFLOAT;
    particles.clear();
    for (unsigned int i = 0; i < nb_particles; i++)
      particles.push_back(Particle(function, c1, c2, c3));
  }
  float getMediane(ListFloat l)
  {
    l.sort();
    std::list<float>::iterator iter;
    unsigned int i;
    for (iter = l.begin(), i = 0; i < l.size() / 2; iter++, i++)
      ;
    return *iter;
  }
private :
  // Number of particles
  unsigned int nb_particles;
  // Maximum number of iterations
  unsigned int nb_iter;
  // Maximum number of iterations
  unsigned int nb_run;
  // Function to minimize
  OptiFunc* function;
  // swarm of particles
  VecParticle particles;
  // Final solution
  VecFloat solution;
  // Value of solution
  float
    gbest;
  // The factors in equation that compute new velocity of a particle
  float c1;
  float c2;
  float c3;
};

# include "swarm.hxx"

#endif /* swarm.hh */
