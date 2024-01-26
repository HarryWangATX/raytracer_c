#include "metal.h"
#include "vec3.h"

bool scatter_metal(metal mtl, ray *r_in, hit_record *rec, color *attenuation, ray *scattered) {
    vec3 unit_r_in = unit(&r_in->direction);
    vec3 reflected = reflect(&unit_r_in, &rec->normal);
    vec3 random_unit = random_unit_vector();
    random_unit = mult_num(&random_unit, mtl.fuzz);
    vec3 fuzzed = add(&reflected, &random_unit);
    *scattered = initRay(&rec->p, &fuzzed);
    *attenuation = mtl.albedo;
    return dot(&scattered->direction, &rec->normal) > 0;
}

metal make_metal(color albedo, double fuzz) {
    metal mtl;
    mtl.albedo = albedo;
    mtl.fuzz = fuzz;
    return mtl;
}