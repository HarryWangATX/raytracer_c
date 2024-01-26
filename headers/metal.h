#ifndef METAL_H
#define METAL_H

#include "color.h"
#include "ray.h"
#include "hitrecord.h"

struct metal {
    color albedo;
    double fuzz;
};

typedef struct metal metal;
typedef struct hit_record hit_record;

metal make_metal(color albedo, double fuzz);
bool scatter_metal(metal mtl, ray *r_in,  hit_record *rec, color *attenuation, ray *scattered);

#endif