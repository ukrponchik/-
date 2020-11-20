#include "quadrangle/quadrangle.h"

int main() {
  Quadrangle quad(vdouble{5, 6, 7, 8}, vdouble{100, 200, 30, 40});

  std::cout << quad << std::endl;

  Square s{vdouble{30, 40}};

  std::cout << s << std::endl;

  s = quad;
  std::cout << s << std::endl;

  return 0;
}
