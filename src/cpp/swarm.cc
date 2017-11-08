#include "swarm.hh"

#include "particle.hh"


Swarm::Swarm(OptiFunc* f, unsigned int iter, unsigned int nbrun,
             unsigned int nbparticles, float c1, float c2, float c3)
{
  function = f;
  nb_iter = iter;
  if ((nbrun % 2) == 0)
    nb_run = nbrun + 1;
  else
    nb_run = nbrun;
  nb_particles = nbparticles;
  c1 = c1;
  c2 = c2;
  c3 = c3;
  srandom(time(NULL));

}

Swarm::Swarm(OptiFunc* f, unsigned int iter, unsigned int nbrun,
             unsigned int nbparticles)
{
  function = f;
  nb_iter = iter;
  if ((nbrun % 2) == 0)
    nb_run = nbrun + 1;
  else
    nb_run = nbrun;
  nb_particles = nbparticles;
  c1 = C1;
  c2 = C2;
  c3 = C3;
  srandom(1);
}

Swarm::Swarm(OptiFunc* f)
{
  function = f;
  nb_iter = NB_ITER;
  nb_run = NB_RUN;
  nb_particles = NB_PARTICLES;
  srandom(time(NULL));
}

Swarm::Swarm()
{
  nb_iter = NB_ITER;
  nb_run = NB_RUN;
  nb_particles = NB_PARTICLES;
  srandom(time(NULL));
}



void Swarm::resolve(int precision)
{
  // The best value seen by all particles
  int gbest_idx = -1;
  std::cout << "Trying to minimize :" << std::endl;
  std::cout << "\t" << *function << std::endl << std::endl;
  initialize_swarm();
  for (unsigned int iter = 0; iter < nb_iter; iter++)
  {
    for (unsigned int i = 0; i < nb_particles; i++)
    {
      float res = particles[i].compute();
      if (res < gbest)
      {
        gbest = res;
        gbest_idx = i;
        solution = particles[gbest_idx].get_p_best();
      }
    }
    for (unsigned int i = 0; i < nb_particles; i++)
    {
      particles[i].update(particles[gbest_idx].get_p_best());
    }
  }
  print_solution(precision);
}


void Swarm::analysis(int precision)
{
  float average = 0;
  float average_iter = 0;
  ListFloat l;
  for (unsigned int run = 0; run < nb_run; run++)
  {
    // The best value seen by all particles
    int gbest_indx = -1;
    unsigned int nbiter = 0;
    initialize_swarm();
    for (unsigned int iter = 0; iter < nb_iter; iter++)
    {
      for (unsigned int i = 0; i < nb_particles; i++)
      {
        float res = particles[i].compute();
        if (res < gbest)
        {
          gbest = res;
          gbest_indx = i;
          nbiter = iter;
          this->solution = particles[gbest_indx].get_p_best();
        }
      }
      for (unsigned int i = 0; i < nb_particles; i++)
      {
        particles[i].update(particles[gbest_indx].get_p_best());
      }
    }
    l.push_back(gbest);
    average += gbest;
    average_iter += nbiter;
    print_solution(precision);
    std::cout << "found iteration number " << nbiter << std::endl << std::endl;
  }
  std::cout << "------------------- " << std::endl;
  std::cout << "Average value : " << average / nb_run << std::endl;
  std::cout << "Median value : " << getMediane(l) << std::endl;
  std::cout << "Average iterations number : " << average_iter / nb_run << std::endl;
}

