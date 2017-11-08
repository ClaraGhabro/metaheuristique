#ifndef OPTI_FUNC_HH
# define OPTI_FUNC_HH

# define MIN_R 0
# define MAX_R 1
/*———.
  | Includes |
  ‘———*/
# include <iostream>
# include <vector>
typedef std::vector<float> VecFloat;
/*———.
  | OptiFunc |
  ‘———*/
class OptiFunc
{
public :
  // ctors & dtors
  OptiFunc(std::string name, int dimension, float min_range, float max_range);

  virtual ~OptiFunc() = default;

  // Accessors
  std::string get_name() const;
  void set_name(std::string name);
  unsigned int get_dimension() const;
  void set_dimension(unsigned int dimension);
  float get_range(int i) const;
  void set_range(float min_range, float max_range);

  // The expression of the function to compute (abstract)
  virtual float compute(VecFloat x) = 0;

private :
  // Name of the function
  std::string name_;
  // Dimension
  unsigned int dimension_;
  // Range to search in
  float range_[2];
};

// Stream Operator
std::ostream& operator<< (std::ostream& out, const OptiFunc& f);

# include "opti_func.hxx"

#endif /* opti_func.hh */
