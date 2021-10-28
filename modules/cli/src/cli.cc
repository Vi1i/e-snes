#include <cstdlib>
#include <iostream>

#include <esnes/esnes.h>

auto main(int argc, const char* argv[]) -> int {
  std::cout << esnes::esnes() << std::endl;

  return EXIT_SUCCESS;
}
