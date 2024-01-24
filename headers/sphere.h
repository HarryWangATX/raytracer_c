#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "ray.h"
#include "intervals.h"
#include "hitrecord.h"
#include <stdbool.h>

struct sphere {
    point3 center;
    double radius;
    material *mat;
    bool (*hit)(struct sphere *s, ray *r, interval iv, hit_record *rec);
};

typedef struct sphere sphere;

sphere *makeSphere(point3 center, double radius, material * mat);
bool hitSphere(sphere *s, ray *r, interval iv, hit_record *rec);

#endif