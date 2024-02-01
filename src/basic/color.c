#include "color.h"
#include "intervals.h"
#include <math.h>

double linear_to_gamma(double linear_component) {
    return sqrt(linear_component);
}

void write_color(FILE *file, color *pixel_color, int samples_per_pixel) {
    // Write the translated [0,255] value of each color component.
    double r = x(pixel_color);
    double g = y(pixel_color);
    double b = z(pixel_color);

    double scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    r = linear_to_gamma(r);
    b = linear_to_gamma(b);
    g = linear_to_gamma(g);

    static interval intensity = {0.000, 0.999};
    fprintf(file, "%d %d %d\n", (int)(255.999 * clamp(&intensity, r)),
                         (int)(255.999 * clamp(&intensity, g)),
                         (int)(255.999 * clamp(&intensity, b)));
}