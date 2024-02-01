#include "rt_utils.h"
#include <math.h>

double infinity = INFINITY;
double pi = 3.1415926535897932385;

double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

double random_double_empt() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double_empt();
}
