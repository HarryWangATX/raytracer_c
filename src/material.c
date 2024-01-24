#include "material.h"
#include <stdlib.h>

surface create_surface(enum surface_type type, void *sf) {
    surface union_sf;
    switch (type)
    {
    case LAMBERTIAN:
        union_sf.lbt = (lambertian *) sf;
        break;
    case METAL:
        union_sf.mtl = (metal *) sf;
        break;
    default:
        break;
    }

    return union_sf;
}

material *create_material(enum surface_type type, surface sf) {
    material *mat = (material *) malloc(sizeof(material));

    mat->type = type;
    mat->sf = sf;
    return mat;
}

void free_material(material *mat) {
    switch (mat->type)
    {
    case LAMBERTIAN:
        free(mat->sf.lbt);
        break;
    case METAL:
        free(mat->sf.mtl);
        break;
    default:
        break;
    }

    free(mat);
}