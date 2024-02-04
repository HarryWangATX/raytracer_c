#include "hittables_list.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct bvh_node bvh_node;
bool bvh_hit(bvh_node *bvh, ray *r, interval iv, hit_record *hit_record);

shape create_shape(enum object_type type, void *sh) {
    shape shp;
    switch (type){
    case SPHERE_TYPE:
        shp.s = (sphere *) sh;
        break;
    case BVH_TYPE:
        shp.bvh = (bvh_node *) sh;
        break;
    default:
        break;
    }
    return shp;
}

object *create_object(enum object_type type, shape obj) {
    object *res = (object *) malloc(sizeof(object));
    res->type = type;
    res->objects = obj;
    return res;
}

void free_object(object *obj) {
    switch (obj->type)
    {
    case SPHERE_TYPE:
        free(obj->objects.s);
        break;
    
    default:
        break;
    }

    free(obj);
}


hittable_list initializeList() {
    hittable_list list;
    initializeVector(&(list.objects), sizeof(object *));
    return list;
}

hittable_list initializeListValue(object obj) {
    hittable_list list = initializeList();
    list_add(&list, &obj);
}

aabb hittableBoundingBox(hittable_list *list) {
    return list->bbox;
}

void list_add(hittable_list *list, object *obj) {
    push_back(&(list->objects), (void *) obj);
    switch (obj->type) {
        case SPHERE_TYPE:
            list->bbox = constructAABBBoxes(&list->bbox, &obj->objects.s->bounding_box);
            break;
        
        default:
            break;
    }
}

bool list_hit(hittable_list *list, ray *r, interval ray_t, hit_record *rec) {
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = ray_t.max;

    for (int cnt = 0; cnt < (list->objects).size; cnt++) {
        object *obj = (object *) list_get(&list->objects, cnt);        
        bool hitted = false;
        switch ((*obj).type) {
        case SPHERE_TYPE:
            // hitted = (*obj).objects.s->hit((*obj).objects.s, r, ray_tmin, closest_so_far, &temp_rec);
            hitted = hitSphere((*obj).objects.s, r, interval_value(ray_t.min, closest_so_far), &temp_rec);
            break;
        case BVH_TYPE:
            hitted = bvh_hit((*obj).objects.bvh, r, interval_value(ray_t.min, closest_so_far), &temp_rec);
        default:
            break;
        }

        if (hitted) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            *rec = temp_rec;
        }
    }

    return hit_anything;
}