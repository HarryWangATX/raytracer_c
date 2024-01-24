#ifndef MATERIAL_H
#define MATERIAL_H

#include "hitrecord.h"
#include "lambertian.h"
#include "metal.h"
#include <stdbool.h>

typedef struct lambertian lambertian;
typedef struct metal metal;

enum surface_type {
    LAMBERTIAN,
    METAL
};

union surface {
    lambertian *lbt;
    metal *mtl;
};

typedef union surface surface;

struct material {
    enum surface_type type;
    surface sf;
};

typedef struct material material;

surface create_surface(enum surface_type type, void *sf);
material *create_material(enum surface_type type, surface sf);
void free_material(material *mat);

#endif