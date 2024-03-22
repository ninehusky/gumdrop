#include "cpu/cpu.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::string result = cpu::init();
  std::cout << result << std::endl;
  return EXIT_SUCCESS;
}