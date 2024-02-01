#include "intervals.h"
#include "sphere.h"
#include "hitrecord.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool hitSphere(sphere *s, ray *r, interval iv, hit_record *rec) {
    point3 center = s->moving ? sphereCenter(s, r->time) : s->center;
    vec3 oc = sub(&r->origin, &center);
    double a = length_squared(&r->direction);
    double half_b = dot(&oc, &r->direction);
    double c = length_squared(&oc) - s->radius*s->radius;
    double discriminant = half_b * half_b - a*c;

    if (discriminant < 0) return false;
    double sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    double root = (-half_b - sqrtd) / a;
    if (!surrounds(&iv, root)) {
        root = (-half_b + sqrtd) / a;
        if (!surrounds(&iv, root))
            return false;
    }

    rec->t = root;
    rec->p = at(r, rec->t);
    vec3 outward_normal = sub(&rec->p, &center);
    outward_normal = div_num(&outward_normal, s->radius);
    set_face_normal(rec, r, &outward_normal);
    rec->mat = s->mat;

    return true;
}

sphere *makeSphere(point3 center, double radius, material *mat) {
    sphere *s = (sphere *) malloc(sizeof(sphere));
    s->center = center;
    s->radius = radius;
    s->mat = mat;
    s->moving = false;
    vec3 rad = initValue(radius, radius, radius);
    s->bounding_box = constructAABBPoints(sub(&center, &rad), add(&center, &rad));
    return s;
}

sphere *makeSphereMoving(point3 center, point3 center2, double radius, material *mat) {
    sphere *s = makeSphere(center, radius, mat);
    s->moving = true;

    vec3 rad = initValue(radius, radius, radius);
    aabb box1 = constructAABBPoints(sub(&center, &rad), add(&center, &rad));
    aabb box2 = constructAABBPoints(sub(&center2, &rad), add(&center2, &rad));
    s->bounding_box = constructAABBBoxes(&box1, &box2);
    s->center_vec = sub(&center2, &center);

    return s;
}

point3 sphereCenter(sphere *s, double time) {
    vec3 direction = mult_num(&s->center_vec, time);

    return add(&direction, &s->center);
}