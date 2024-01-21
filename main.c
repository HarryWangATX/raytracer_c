#include "color.h"
#include "vec3.h"

#include <stdio.h>


int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            color pixel_color = initValue((double)i/(image_width-1), (double)j/(image_height-1), 0);
            write_color(&pixel_color);
        }
    }
}
