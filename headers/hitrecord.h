#ifndef HITRECORD_H
#define HITRECORD_H

#include "vec3.h"
#include "ray.h"
#include "material.h"
#include <stdbool.h>

typedef struct material material;

struct hit_record {
    point3 p;
    vec3 normal;
    double t;
    material *mat;
    bool front_face;

    // void (*set_face_normal)(bool front, ray *r, vec3 *outward_normal);
};

typedef struct hit_record hit_record;

void set_face_normal(hit_record *record, ray *r, vec3 *outward_normal);

#endif