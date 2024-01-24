#ifndef METAL_H
#define METAL_H

#include "color.h"
#include "ray.h"
#include "hitrecord.h"

struct metal {
    color albedo;
};

typedef struct metal metal;
typedef struct hit_record hit_record;

metal make_metal(color albedo);
bool scatter_metal(metal *mtl, ray *r_in,  hit_record *rec, color *attenuation, ray *scattered);

#endif