#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "color.h"
#include "ray.h"
#include "hitrecord.h"

struct lambertian {
    color albedo;
};

typedef struct lambertian lambertian;
typedef struct hit_record hit_record;

lambertian make_lambertian(color albedo);
bool scatter_lambertian(lambertian *lbt, ray *r_in, hit_record *rec, color *attenuation, ray *scattered);

#endif