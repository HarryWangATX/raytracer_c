#ifndef RAY_H
#define RAY_H

#include "vec3.h"

struct ray {
    point3 origin;
    vec3 direction;
    double time;
};

typedef struct ray ray;

ray initRay(point3 *orig, vec3 *direction);
ray initRayTime(point3 *orig, vec3 *direction, double time);

point3 origin(ray *r);
vec3 direction(ray *r);

point3 at(ray *r, double t);

#endif