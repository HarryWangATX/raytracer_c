#include "sphere.h"
#include "hitrecord.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool hitSphere(sphere *s, ray *r, double ray_tmin, double ray_tmax, hit_record *rec) {
    vec3 oc = sub(&r->origin, &s->center);
    double a = length_squared(&r->direction);
    double half_b = dot(&oc, &r->direction);
    double c = length_squared(&oc) - s->radius*s->radius;
    double discriminant = half_b * half_b - a*c;

    if (discriminant < 0) return false;
    double sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    double root = (-half_b - sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
        root = (-half_b + sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root)
            return false;
    }

    rec->t = root;
    rec->p = at(r, rec->t);
    vec3 outward_normal = sub(&rec->p, &s->center);
    outward_normal = div_num(&outward_normal, s->radius);
    set_face_normal(rec, r, &outward_normal);

    return true;
}

sphere *makeSphere(point3 center, double radius) {
    sphere *s = (sphere *) malloc(sizeof(sphere));
    s->center = center;
    s->radius = radius;
    s->hit = &hitSphere;
    return s;
}