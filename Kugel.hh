#ifndef KUGEL_HH
#define KUGEL_HH

#include "Vektor.hh"
#include "Koerper.hh"

class Kugel : public Koerper {
public:
  std::string name() {return "Kugel";}
  Kugel(double nr, double m);
  
  Vektor punkt();

private:
  double r_, m_;
};

#endif