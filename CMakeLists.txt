# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)

# Define the project and set languages
project(RayTracer C)

include_directories(headers)

# Set the build type to Debug
# set(CMAKE_BUILD_TYPE Debug)

# Add the -g flag for debugging information
# set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

# Add all .c files in the src/ directory
set(SOURCE_FILES
    src/rt_utils.c
    src/vec3.c
    src/color.c
    src/ray.c
    src/intervals.c
    src/hitrecord.c
    src/hittables_list.c
    src/sphere.c
    src/vector.c
    src/camera.c)

# Add the executable target and specify source files
add_executable(main main.c ${SOURCE_FILES})

# Link with the math library
target_link_libraries(main m)