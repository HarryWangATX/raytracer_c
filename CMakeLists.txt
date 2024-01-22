# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)

# Define the project and set languages
project(RayTracer C)

include_directories(headers)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Add the -g flag for debugging information
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

# Add the executable target and specify source files
add_executable(main main.c src/vec3.c src/ray.c src/sphere.c src/vector.c src/hittables_list.c src/hitrecord.c)

# Link with the math library
target_link_libraries(main m)