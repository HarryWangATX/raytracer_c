#ifndef BVH_H
#define BVH_H

#include "object.h"
#include "aabb.h"
#include "hittables_list.h"
#include <stdbool.h>

struct bvh_node {
    aabb bbox;
    object *obj;
    bool leaf;
    struct bvh_node *left, *right;
};

typedef struct bvh_node bvh_node;

bvh_node *allocateBVH(object *obj, bool isLeaf);
void constructBVH(bvh_node *bvh, hittable_list *list);
void constructBVHBuild(bvh_node *bvh, hittable_list *list, size_t start, size_t end);
bool bvh_hit(bvh_node *bvh, ray *r, interval iv, hit_record *hit_record);

#endif