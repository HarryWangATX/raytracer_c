#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <stdlib.h>

// Constants

extern double infinity, pi;

// Utility Functions

double degrees_to_radians(double degrees);

double random_double_empt();

double random_double(double min, double max);

// Common Headers

#include "ray.h"
#include "vec3.h"
#include "intervals.h"

#endif