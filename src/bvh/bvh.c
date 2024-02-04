#include "bvh.h"
#include <stdlib.h>

int boxCompare(const object *o1, const object *o2, int axis) {
    switch (o1->type)
    {
    case SPHERE_TYPE:
        return aabbAxis(&o1->objects.s->bounding_box, axis).min - aabbAxis(&o2->objects.s->bounding_box, axis).min;
    default:
        break;
    }
    return false;
}

int compareX(const void *o1, const void *o2) {
    return boxCompare(*(const object **) o1, *(const object **) o2, 0);
}

int compareY(const void *o1, const void *o2) {
    return boxCompare(*(const object **) o1, *(const object **) o2, 1);
}

int compareZ(const void *o1, const void *o2) {
    return boxCompare(*(const object **) o1, *(const object **) o2, 2);
}

bvh_node constructNode(object *obj, bool isLeaf) {
    bvh_node bvh;
    switch (obj->type)
    {
    case SPHERE_TYPE:
        bvh.bbox = obj->objects.s->bounding_box;
        bvh.leaf = isLeaf;
        bvh.obj = obj;
        return bvh;
    default:
        break;
    }

    bvh.leaf = isLeaf;
    return bvh;
}

bvh_node *allocateBVH(object *obj, bool isLeaf) {
    bvh_node *bvh = (bvh_node *) malloc(sizeof(bvh_node));
    bvh->left = NULL;
    bvh->right = NULL;
    switch (obj->type) {
    case SPHERE_TYPE:
        bvh->bbox = obj->objects.s->bounding_box;
        bvh->leaf = isLeaf;
        bvh->obj = obj;
        return bvh;
    default:
        break;
    }

    bvh->leaf = isLeaf;
    return bvh;
}

void allocateBVHEmpty(bvh_node **bvh) {
    *bvh = (bvh_node *) malloc(sizeof(bvh_node));
}

void constructBVH(bvh_node *bvh, hittable_list *list) {
    constructBVHBuild(bvh, list, 0, list->objects.size);
}

void constructBVHBuild(bvh_node *bvh, hittable_list *list, size_t start, size_t end) {
    hittable_list part = *list;

    int axis = rand() % 2;
    int (*compare) (const void *o1, const void *o2) = (axis == 0 ? &compareX : (axis == 1 ? &compareY : &compareZ));

    size_t total = end - start;

    bvh->leaf = false;
    bvh->obj = NULL;

    if (total == 1) {
        bvh->left = bvh->right = allocateBVH((object *) list_get(&list->objects, start), true);
    }
    else if (total == 2) {
        object *o1 = (object *) list_get(&list->objects, start);
        object *o2 = (object *) list_get(&list->objects, start + 1);
        if ((*compare)(&o1, &o2)) {
            bvh->left = allocateBVH(o1, true);
            bvh->right = allocateBVH(o2, true);
        }
        else {
            bvh->left = allocateBVH(o2, true);
            bvh->right = allocateBVH(o1, true);
        }
    }
    else {
        object *sortable_list[total];

        for (int i = 0; i < total; i++) {
            sortable_list[i] = (object *) list_get(&list->objects, start + i);
        }

        qsort(sortable_list, total, sizeof(object *), *compare);

        for (int i = 0; i < total; i++) {
            insert_into(&part.objects, sortable_list[i], start + i);
        }

        bvh->left = (bvh_node *) malloc(sizeof(bvh_node));
        bvh->right = (bvh_node *) malloc(sizeof(bvh_node));

        int mid = start + total / 2;
        constructBVHBuild(bvh->left, &part, start, mid);
        constructBVHBuild(bvh->right, &part, mid, end);
    }

    bvh->bbox = constructAABBBoxes(&bvh->left->bbox, &bvh->right->bbox);
}

bool bvh_hit(bvh_node *bvh, ray *r, interval iv, hit_record *hit_record) {
    if (bvh->leaf) {
        switch (bvh->obj->type) {
            case SPHERE_TYPE:
                return hitSphere(bvh->obj->objects.s, r, iv, hit_record);
            default:
                break;
        }
    }

    if (!aabbHit(&bvh->bbox, r, iv)) return false;

    bool left_hit = bvh_hit(bvh->left, r, iv, hit_record);
    bool right_hit = bvh_hit(bvh->right, r, interval_value(iv.min, left_hit ? hit_record->t : iv.max), hit_record);

    return left_hit || right_hit;
}