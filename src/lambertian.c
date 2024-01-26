#include "lambertian.h"

bool scatter_lambertian(lambertian lbt, ray *r_in,  hit_record *rec, color *attenuation, ray *scattered) {
    vec3 rand_unit = random_unit_vector();
    vec3 scatter_direction = add(&rec->normal, &rand_unit);
    if (near_zero(&scatter_direction))
        scatter_direction = rec->normal;
    *scattered = initRay(&rec->p, &scatter_direction);
    *attenuation = lbt.albedo;
    return true;
}

lambertian make_lambertian(color albedo) {
    lambertian lbt;
    lbt.albedo = albedo;
    return lbt;
}
