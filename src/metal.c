#include "metal.h"
#include "vec3.h"

bool scatter_metal(metal *mtl, ray *r_in, hit_record *rec, color *attenuation, ray *scattered) {
    vec3 unit_r_in = unit(&r_in->direction);
    vec3 reflected = reflect(&unit_r_in, &rec->normal);
    *scattered = initRay(&rec->p, &reflected);
    *attenuation = mtl->albedo;
    return true;
}

metal make_metal(color albedo) {
    metal mtl;
    mtl.albedo = albedo;
    return mtl;
}