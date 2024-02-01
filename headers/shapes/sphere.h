#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "ray.h"
#include "intervals.h"
#include "hitrecord.h"
#include "material.h"
#include "aabb.h"
#include <stdbool.h>

struct sphere {
    aabb bounding_box;
    point3 center;
    vec3 center_vec;
    material *mat;
    double radius;
    bool moving;
};

typedef struct sphere sphere;

sphere *makeSphere(point3 center, double radius, material *mat);
sphere *makeSphereMoving(point3 center, point3 center2, double radius, material *mat);
bool hitSphere(sphere *s, ray *r, interval iv, hit_record *rec);
point3 sphereCenter(sphere *s, double time);

#endif