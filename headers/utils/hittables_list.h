#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "vector.h"
#include "hitrecord.h"
#include "ray.h"
#include "sphere.h"
#include "aabb.h"
#include "stdbool.h"

enum object_type {
    SPHERE_TYPE
};

union shape {
    sphere *s;
};

typedef union shape shape;

struct object {
    enum object_type type;
    shape objects;
};

struct hittable_list {
    vector objects;
    aabb bbox;
};

typedef struct hittable_list hittable_list;
typedef struct object object;

shape create_shape(enum object_type type, void *sh);
object *create_object(enum object_type type, shape obj);
void free_object(object *obj);

hittable_list initializeList();
hittable_list initializeListValue(object obj);

void list_add(hittable_list *list, object *obj);
bool list_hit(hittable_list *list, ray *r, interval ray_t, hit_record *rec);

#endif