# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)

# Define the project and set languages
project(RayTracer C)

include_directories(headers)

# Add the executable target and specify source files
add_executable(main main.c src/vec3.c)

# Link with the math library
target_link_libraries(main m)