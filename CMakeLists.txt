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
