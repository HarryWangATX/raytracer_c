#include "rt_utils.h"

#include "color.h"
#include "hittables_list.h"
#include "sphere.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

color ray_color(ray *r, hittable_list *world) {
    hit_record rec;
    
    if (list_hit(world, r, 0, infinity, &rec)) {
        color fin = add_num(&(rec.normal), 1);
        return mult_num(&fin, 0.5);
    }

    vec3 unit_direction = unit(&r->direction);
    double a = 0.5*(y(&unit_direction) + 1.0);

    color white = initValue(1, 1, 1);
    color grad = initValue(0.5, 0.7, 1.0);
    color comp1 = mult_num(&white, (1.0 - a));
    color comp2 = mult_num(&grad, a);
    return add(&comp1, &comp2);
}

int main() {
    FILE *file = fopen("images/blue.ppm", "w");

    if (file == NULL) {
        perror("Couldn't open file");
        return 1;
    }

    // Image

    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;


    int image_height = (int)(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // World

    hittable_list world = initializeList();
    object *s1 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(0, 0, -1), 0.5)));
    object *s2 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(0, -100.5, -1), 100)));

    list_add(&world, s1);
    list_add(&world, s2);

    // world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    // world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Camera

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)image_width/image_height);
    point3 camera_center = initValue(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    vec3 viewport_u = initValue(viewport_width, 0, 0);
    vec3 viewport_v = initValue(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    vec3 pixel_delta_u = div_num(&viewport_u, image_width);
    vec3 pixel_delta_v = div_num(&viewport_v, image_height);
    vec3 pixel_sum = add(&pixel_delta_u, &pixel_delta_v);
    vec3 pixel_sum_half = div_num(&pixel_sum, 2);

    // Calculate the location of the upper left pixel.
    vec3 viewport_u_half = div_num(&viewport_u, 2);
    vec3 viewport_v_half = div_num(&viewport_v, 2);
    vec3 neg_u = neg(&viewport_u_half);
    vec3 neg_v = neg(&viewport_v_half);
    vec3 focal_vec = initValue(0, 0, focal_length);
    vec3 cam_foc = sub(&camera_center, &focal_vec);
    vec3 viewports = add(&neg_u, &neg_v);
    vec3 viewport_upper_left = add(&cam_foc, &viewports);
    // camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    vec3 pixel00_loc = add(&viewport_upper_left, &pixel_sum_half);

    // Render

    fprintf(file, "P3\n%d %d\n255\n", image_width, image_height);

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            vec3 i_comp = mult_num(&pixel_delta_u, i);
            vec3 j_comp = mult_num(&pixel_delta_v, j);
            vec3 non_normalized = add(&i_comp, &j_comp);
            vec3 pixel_center = add(&pixel00_loc, &non_normalized);

            vec3 ray_direction = sub(&pixel_center, &camera_center);
            ray r = initRay(&camera_center, &ray_direction);
            color pixel_color = ray_color(&r, &world);
            write_color(file, &pixel_color);
        }
    }

    for (int cnt = 0; cnt < world.objects.size; cnt++) {
        free((object *)list_get(&world.objects, cnt));
    }

    fclose(file);
}
