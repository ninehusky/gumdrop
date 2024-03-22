// This uses Google Test to test the CPU class.

#include "../include/cpu/cpu.hpp"
#include <gtest/gtest.h>

TEST(CPU, Init) {
  std::string result = cpu::init();
  EXPECT_EQ(result, "well i'm here!");
}
