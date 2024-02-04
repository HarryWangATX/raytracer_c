# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)

# Define the project and set languages
project(RayTracer C)

include_directories(headers)
include_directories(headers/basic)
include_directories(headers/bvh)
include_directories(headers/materials)
include_directories(headers/shapes)
include_directories(headers/utils)

# Set the build type to Debug
# set(CMAKE_BUILD_TYPE Debug)

# Add the -g flag for debugging information
# set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")

# Add all .c files in the src/ directory
set(SOURCE_FILES
    src/utils/rt_utils.c
    src/basic/vec3.c
    src/basic/color.c
    src/basic/ray.c
    src/utils/intervals.c
    src/utils/hitrecord.c
    src/utils/hittables_list.c
    src/materials/lambertian.c 
    src/materials/metal.c
    src/materials/dielectric.c
    src/shapes/sphere.c
    src/basic/vector.c
    src/camera.c
    src/materials/material.c
    src/utils/aabb.c
    src/bvh/bvh.c)

# Add the executable target and specify source files
add_executable(main main.c ${SOURCE_FILES})

# Link with the math library
target_link_libraries(main m)