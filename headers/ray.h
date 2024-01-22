#include "vec3.h"

#ifndef RAY_H
#define RAY_H

struct ray {
    point3 origin;
    vec3 direction;
};

typedef struct ray ray;

ray initRay(point3 *orig, vec3 *direction);

point3 origin(ray *r);
vec3 direction(ray *r);

point3 at(ray *r, double t);

#endif