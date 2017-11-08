#pragma once

#include "opti_func.hh"


typedef std::vector<float> VecFloat;

class micha_2 : public OptiFunc
{
public:
  // micha_2(){}
  micha_2(std::string name, int dimension, float min_range, float max_range);
  
  float compute(VecFloat x);
};
