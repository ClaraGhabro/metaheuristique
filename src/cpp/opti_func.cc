#include "opti_func.hh"


OptiFunc::OptiFunc(std::string name, int dimension, float min_range, float max_range)
{
  this->name_ = name;
  this->dimension_ = dimension;
  // make sure min_range < max_range or swap
  if (min_range > max_range)
  {
    float t = min_range;
    min_range = max_range;
    max_range = t;
  }
  this->range_[MIN_R] = min_range;
  this->range_[MAX_R] = max_range;
}

std::ostream& operator<< (std::ostream& out, const OptiFunc& f)
{
  unsigned int i;
  out << f.get_name() + "(";
  for (i = 0; i < f.get_dimension() - 1; i++)
  {
    out << "x" << i << ", ";
  }
  out << "x" << i << ")";
  out << " on [" << f.get_range(MIN_R) << "; " << f.get_range(MAX_R) << "]";
  return out;
}
