#include "swarm.hh"
#include "function.hh"

int main()
{
  // Functions to optimize
  micha_2          a("micha", 2, 0, 3.14);
  // Micha_5       b;
  // Micha_10      c;
  // DeJongF1<6>   d;
  // DeJongF2      e;
  // DeJongF3<5>   f;
  // GoldPrice     g;
  // Rosenbrock<5> h;
  // Zakharov<6>   i;
  // Schwefel<4>   j;
  Swarm s(&a, 2000, 11, 200, 1.0, 2.0, 2.0) ;
  s.resolve() ;
  return(0) ;
}
