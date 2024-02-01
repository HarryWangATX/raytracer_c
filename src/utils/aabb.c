#include "aabb.h"

aabb constructAABBPoints(point3 a, point3 b) {
    aabb aabb;
    aabb.x = interval_value(fmin(x(&a), x(&b)), fmax(x(&a), x(&b)));
    aabb.y = interval_value(fmin(y(&a), y(&b)), fmax(y(&a), y(&b)));
    aabb.z = interval_value(fmin(z(&a), z(&b)), fmax(z(&a), z(&b)));
    return aabb;
}

aabb constructAABBInterval(interval *x, interval *y, interval *z) {
    aabb aabb;
    aabb.x = *x;
    aabb.y = *y;
    aabb.z = *z;
}

aabb constructAABBBoxes(aabb *a, aabb *b) {
    aabb aabb;
    aabb.x = interval_interval(&a->x, &b->x);
    aabb.y = interval_interval(&a->y, &b->y);
    aabb.z = interval_interval(&a->z, &b->z);
    return aabb;
}

aabb constructAABBEmpty() {
    aabb aabb;
    aabb.x = default_interval();
    aabb.y = default_interval();
    aabb.z = default_interval();
    return aabb;
}

interval aabbAxis(aabb *aabb, int axis) {
    if (axis == 1) return aabb->y;
    if (axis == 2) return aabb->z;
    return aabb->x;
}

void swap(double *t0, double *t1) {
    double tmp = *t0;
    *t0 = *t1;
    *t1 = tmp;
}

bool aabbHit(aabb* aabb, ray *r, interval ray_t) {
    for (int axis = 0; axis < 3; axis++) {
        double invD = 1 / r->direction.e[axis];
        double orig = r->origin.e[axis];

        double t0 = (aabbAxis(aabb, axis).min - orig) * invD;
        double t1 = (aabbAxis(aabb, axis).max - orig) * invD;

        if (invD < 0) {
            swap(&t0, &t1);
        }

        if (t0 > ray_t.min) ray_t.min = t0;
        if (t1 < ray_t.max) ray_t.max = t1;

        if (ray_t.max <= ray_t.min)
            return false;
    }

    return true;
}