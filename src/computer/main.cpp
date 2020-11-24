#include "computer/computer.h"
#include <iostream>

int main() {
  Computer m(512000, "araf", 34567);
  ComputerWithMonitor r(712000, "faraf", 37391);

  m.data();
  r.data();

  std::getchar();
  return 0;
}