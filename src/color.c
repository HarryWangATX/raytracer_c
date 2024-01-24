#include "color.h"
#include "intervals.h"

void write_color(FILE *file, color *pixel_color, int samples_per_pixel) {
    // Write the translated [0,255] value of each color component.
    double r = x(pixel_color);
    double g = y(pixel_color);
    double b = z(pixel_color);

    double scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    static interval intensity = {0.000, 0.999};
    fprintf(file, "%d %d %d\n", (int)(255.999 * clamp(&intensity, r)),
                         (int)(255.999 * clamp(&intensity, g)),
                         (int)(255.999 * clamp(&intensity, b)));
}