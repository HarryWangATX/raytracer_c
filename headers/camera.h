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
    double vfov;
    point3 lookfrom, lookat;
    vec3 vup;
    double defocus_angle;
    double focus_dist;

    int image_height;
    point3 center;
    point3 pixel00_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;
    vec3 u, v, w;
    vec3 defocus_disk_u, defocus_disk_v;
};

typedef struct camera camera;

void render(camera *cam, hittable_list *world, FILE *file);


ray get_ray(camera *cam, int i, int j);
vec3 pixel_sample_square(camera *cam);

point3 defocus_disk_sample(camera *cam);
color ray_color(camera *cam, ray *r, int depth, hittable_list *world);
void initialize_camera(camera *cam);

#endif