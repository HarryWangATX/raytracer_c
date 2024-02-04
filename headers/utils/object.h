#ifndef OBJECT_H
#define OBJECT_H

#include "sphere.h"

struct bvh_node;

typedef struct bvh_node bvh_node;

enum object_type {
    SPHERE_TYPE,
    BVH_TYPE
};

union shape {
    sphere *s;
    bvh_node *bvh;
};

typedef union shape shape;

struct object {
    enum object_type type;
    shape objects;
};

typedef struct object object;

#endif
