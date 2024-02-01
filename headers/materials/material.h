#ifndef MATERIAL_H
#define MATERIAL_H

#include "lambertian.h"
#include "metal.h"
#include "dielectric.h"
#include "hitrecord.h"
#include <stdbool.h>



enum surface_type {
    LAMBERTIAN,
    METAL,
    DIELECTRIC
};

union surface {
    lambertian lbt;
    metal mtl;
    dielectric dlc;
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