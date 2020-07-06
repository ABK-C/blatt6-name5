#include "Kugel.hh"

#include <cmath>
#include <math.h>
#include <cstdlib>

Kugel::Kugel(double nr, double nm) {
  r_ = nr;
  m_ = nm;
}

Vektor Kugel::punkt() {
  double R = r_*cbrt(rand() / (double)RAND_MAX);
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double theta = M_PI * rand() / (double)RAND_MAX;

  double x = R*sin(theta)*cos(phi);
  double y = R*sin(theta)*sin(phi);
  double z = R*cos(theta);
  return Vektor(x, y, z);
};


/*double Kugel::masse() {
  return m_;
}*/