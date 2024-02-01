#ifndef AABB_H
#define AABB_H

#include "intervals.h"
#include "vec3.h"
#include "ray.h"

struct aabb {
    interval x, y, z;
};

typedef struct aabb aabb;

aabb constructAABBPoints(point3 a, point3 b);
aabb constructAABBInterval(interval *x, interval *y, interval *z);
aabb constructAABBBoxes(aabb *a, aabb *b);
aabb constructAABBEmpty();

interval aabbAxis(aabb *aabb, int axis);

bool aabbHit(aabb* aabb, ray *r, interval ray_t);

#endif