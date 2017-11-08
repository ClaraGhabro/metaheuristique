#include "function.hh"

#include <cmath>

micha_2::micha_2(std::string name, int dimension, float min_range, float max_range)
  : OptiFunc(name, dimension, min_range, max_range)
{
}

float micha_2::compute(VecFloat x)
{
  float mz = 0;
  for (unsigned i = 0; i < x.size(); ++i)
    mz += std::sin(x[i]) * std::pow((std::sin(std::pow(x[i], 2) * i)), 20);

  return mz;
}
