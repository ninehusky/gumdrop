# This is CMakeLists.txt for the "src" directory of the project.

cmake_minimum_required(VERSION 3.10)
project(gumdrop)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory for header files
include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cc")

# Add executable target
add_executable(gumdrop ${SOURCES})

# Set output directory for built executable
set_target_properties(gumdrop PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Add compiler flags for warnings and debugging
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Define a target for your test executable
add_executable(tests
    tests/test_cpu.cc
    # Add more test source files as needed
    src/cpu/cpu.cc
)

# Link against the Google Test libraries
target_link_libraries(tests PRIVATE gtest gtest_main)

# Discover tests and add them to CTest
include(GoogleTest)
gtest_discover_tests(tests)