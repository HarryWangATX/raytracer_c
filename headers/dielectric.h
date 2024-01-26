#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "hitrecord.h"
#include "color.h"

struct dielectric {
    double ir;
};

typedef struct dielectric dielectric;

bool scatter_dielectric(dielectric dlc, ray *r_in, hit_record *rec, color *attenuation, ray *scattered);
dielectric make_dielectric(double ir);

double reflectance(double cosine, double ref_idx);

#endif