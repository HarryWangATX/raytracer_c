#include "vec3.h"
#include "ray.h"
#include "hitrecord.h"
#include <stdbool.h>

#ifndef SPHERE_H
#define SPHERE_H

struct sphere {
    point3 center;
    double radius;
    bool (*hit)(struct sphere *s, ray *r, double ray_tmin, double ray_tmax, hit_record *rec);
};

typedef struct sphere sphere;

sphere *makeSphere(point3 center, double radius);
bool hitSphere(sphere *s, ray *r, double ray_tmin, double ray_tmax, hit_record *rec);

#endif