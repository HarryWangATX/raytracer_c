#ifndef CAMERA_H
#define CAMERA_H

#include "hittables_list.h"
#include "color.h"
#include <stdio.h>

struct camera {
    double aspect_ratio;
    int image_width;
    int samples_per_pixel;
    int max_depth;

    int image_height;
    point3 center;
    point3 pixel00_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;
};

typedef struct camera camera;

void render(camera *cam, hittable_list *world, FILE *file);


ray get_ray(camera *cam, int i, int j);
vec3 pixel_sample_square(camera *cam);

color ray_color(camera *cam, ray *r, int depth, hittable_list *world);
void initialize_camera(camera *cam);

#endif