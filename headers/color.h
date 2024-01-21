#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <stdio.h>

typedef struct vec3 color;

void write_color(color *pixel_color) {
    // Write the translated [0,255] value of each color component.
    printf("%d %d %d\n", (int)(255.999 * x(pixel_color)),
                         (int)(255.999 * y(pixel_color)),
                         (int)(255.999 * z(pixel_color)));
}

#endif