#include "dielectric.h"
#include "rt_utils.h"
#include <math.h>

bool scatter_dielectric(dielectric *dlc, ray *r_in, hit_record *rec, color *attenuation, ray *scattered) {
    *attenuation = initValue(1.0, 1.0, 1.0);
    double refraction_ratio = rec->front_face ? (1.0/dlc->ir) : dlc->ir;

    vec3 unit_direction = unit(&r_in->direction);
    vec3 neg_unit_direction = neg(&unit_direction);
    double cos_theta = fmin(dot(&neg_unit_direction, &rec->normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

    bool cannot_refract = refraction_ratio * sin_theta > 1.0;
    vec3 direction;

    if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double_empt())
        direction = reflect(&unit_direction, &rec->normal);
    else
        direction = refract(&unit_direction, &rec->normal, refraction_ratio);

    *scattered = initRay(&rec->p, &direction);
    return true;
}

dielectric make_dielectric(double ir) {
    dielectric dlc;
    dlc.ir = ir;
    return dlc;
}

double reflectance(double cosine, double ref_idx) {
    // Use Schlick's approximation for reflectance.
    double r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1 - cosine),5);
}