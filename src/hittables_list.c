#include "hittables_list.h"
#include <stdbool.h>
#include <stdio.h>

shape create_shape(enum object_type type, void *sh) {
    shape shp;
    switch (type){
    case SPHERE_TYPE:
        shp.s = (sphere *) sh;
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

hittable_list initializeList() {
    hittable_list list;
    initializeVector(&(list.objects), sizeof(object *));
    return list;
}

hittable_list initializeListValue(object obj) {
    hittable_list list = initializeList();
    list_add(&list, &obj);
}

void clear(hittable_list *list) {
    free_vec(&(list->objects));
    initializeVector(&(list->objects), sizeof(object *));
}

void list_add(hittable_list *list, object *obj) {
    push_back(&(list->objects), (void *) obj);
}

bool list_hit(hittable_list *list, ray *r, double ray_tmin, double ray_tmax, hit_record *rec) {
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = ray_tmax;

    for (int cnt = 0; cnt < (list->objects).size; cnt++) {
        object *obj = (object *)(*list_get(&list->objects, cnt));        
        bool hitted = false;
        switch ((*obj).type) {
        case SPHERE_TYPE:
            // hitted = (*obj).objects.s->hit((*obj).objects.s, r, ray_tmin, closest_so_far, &temp_rec);
            hitted = hitSphere((*obj).objects.s, r, ray_tmin, closest_so_far, &temp_rec);
            break;
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