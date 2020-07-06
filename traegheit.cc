#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include "Koerper.hh"
#include "Kugel.hh"
#include <iostream>
#include <memory>

double traegheit(Koerper* k, Vektor a, Vektor u, double M) {
  std::cout << "berechne für " << k->name() << "\n";
  
  const int N = 10000;
  double J = 0;
  double m = M / N;
  
  for (int i = 0; i < N; ++i) {
     Vektor x = k->punkt();
    
     double r = (u.kreuz(x - a)).betrag()/u.betrag();
    
      J += m * r * r;
    }
  return J;
}


int main() {
  const double M = 1;   // Masse 
  const double R = 1.0; // Radius 
  const double L = 1.0; // Laenge 
  
  
  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std::unique_ptr<Koerper> k(new Zylindermantel(R, L));
  double JZ = traegheit(k.get(),a,u,M);
  
  std::unique_ptr<Koerper> k2(new Vollzylinder(R, L));
  double JV = traegheit(k2.get(),a,u,M);
  
  std::unique_ptr<Koerper> k3(new Kugel(R, M));
  double JK = traegheit(k3.get(),a,u,M);
  
  
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << JZ << std::endl;
  std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << JV << std::endl;
  std::cout << "Massentraegheitsmoment fuer einen Kugel"
            << " mit a = " << a << " und u = " << u << ": " << JK << std::endl;

  return 0;
}
