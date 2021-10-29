#include <cstdlib>
#include <iostream>

#include <esnes/esnes.h>

auto main(int argc, const char* argv[]) -> int {
  std::cout << esnes::test_func() << std::endl;

  return EXIT_SUCCESS;
}
