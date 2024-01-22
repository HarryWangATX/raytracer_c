#ifndef UTILS_H
#define UTILS_H

#include <math.h>

// Constants

const double infinity = INFINITY;
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common Headers

#include "ray.h"
#include "vec3.h"

#endif