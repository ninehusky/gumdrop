#include "cpu/cpu.hpp"
#include <iostream>

int main(void) {
  std::string result = cpu::init();
  std::cout << result << std::endl;
  return EXIT_SUCCESS;
}