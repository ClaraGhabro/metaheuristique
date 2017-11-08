#include "opti_func.hh"

inline std::string OptiFunc::get_name() const
{
  return this->name_;
}

inline void OptiFunc::set_name(std::string name)
{
  this->name_ = name;
}

inline unsigned int OptiFunc::get_dimension() const
{
  return this->dimension_;
}

inline void OptiFunc::set_dimension(unsigned int dimension)
{
  this->dimension_ = dimension;
}

inline float OptiFunc::get_range(int i) const
{
  return range_[i];
}

inline void OptiFunc::set_range(float min_range, float max_range)
{
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
