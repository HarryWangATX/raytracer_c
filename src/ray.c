#include "ray.h"

ray initRay(point3 *orig, vec3 *direction) {
    ray r;
    r.origin = *orig;
    r.direction = *direction;
    return r;
}

point3 origin(ray *r) {
    return r->origin;
}

vec3 direction(ray *r) {
    return r->direction;
}

point3 at(ray *r, double t) {
    vec3 go = mult_num(&(r->direction), t);
    return add(&(r->origin), &go);
}