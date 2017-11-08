# include "swarm.hh"

inline OptiFunc* Swarm::get_function() const
{
  return this->function;
}

inline void Swarm::set_function(OptiFunc* f)
{
  this->function = f;
}

inline unsigned int Swarm::get_nb_particles() const
{
  return this->nb_particles;
}

inline void Swarm::set_nb_particles(unsigned int nb)
{
  this->nb_particles = nb;
}

inline unsigned int Swarm::get_nb_iter() const
{
  return this->nb_iter;
}

inline void Swarm::set_nb_iter(unsigned int iter)
{
  this->nb_iter = iter;
}

inline void Swarm::print_solution(int precision)
{
  std::cout << function->get_name() + "(" << precision << std::endl;
  // for (unsigned i = 0; i < function->get_dimension() - 1; i++)
    // std::cout << setprecision(precision) << Solution[i] << ", ";
  // std::cout << setprecision(precision) << Solution[i] << ")";
  // std::cout << " = " << setprecision(precision) << gbest << std::endl << std::endl;
}
