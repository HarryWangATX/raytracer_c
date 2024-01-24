#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <stdio.h>

typedef struct vec3 color;

void write_color(FILE *file, color *pixel_color, int samples_per_pixel);

#endif