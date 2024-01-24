#include "camera.h"
#include "rt_utils.h"

void render(camera *cam, hittable_list *world, FILE *file) {
    initialize_camera(cam);
    fprintf(file, "P3\n%d %d\n255\n", cam->image_width, cam->image_height);

    for (int j = 0; j < cam->image_height; ++j) {
        for (int i = 0; i < cam->image_width; ++i) {
            vec3 i_comp = mult_num(&cam->pixel_delta_u, i);
            vec3 j_comp = mult_num(&cam->pixel_delta_v, j);
            vec3 non_normalized = add(&i_comp, &j_comp);
            vec3 pixel_center = add(&cam->pixel00_loc, &non_normalized);

            vec3 ray_direction = sub(&pixel_center, &cam->center);
            ray r = initRay(&cam->center, &ray_direction);

            color pixel_color = initValue(0,0,0);
            for (int sample = 0; sample < cam->samples_per_pixel; ++sample) {
                ray r = get_ray(cam, i, j);
                color pc = ray_color(cam, &r, cam->max_depth, world);
                add_to(&pixel_color, &pc);
            }
            write_color(file, &pixel_color, cam->samples_per_pixel);
        }
    }

}

ray get_ray(camera *cam, int i, int j) {
    // Get a randomly sampled camera ray for the pixel at location i,j.

    vec3 i_comp = mult_num(&cam->pixel_delta_u, i);
    vec3 j_comp = mult_num(&cam->pixel_delta_v, j);
    vec3 comp_sum = add(&i_comp, &j_comp);

    vec3 pixel_center = add(&cam->pixel00_loc, &comp_sum);
    vec3 sampled = pixel_sample_square(cam);
    vec3 pixel_sample = add(&pixel_center, &sampled);

    point3 ray_origin = cam->center;
    vec3 ray_direction = sub(&pixel_sample, &ray_origin);

    return initRay(&ray_origin, &ray_direction);
}

vec3 pixel_sample_square(camera *cam) {
    // Returns a random point in the square surrounding a pixel at the origin.
    double px = -0.5 + random_double_empt();
    double py = -0.5 + random_double_empt();

    vec3 x_comp = mult_num(&cam->pixel_delta_u, px);
    vec3 y_comp = mult_num(&cam->pixel_delta_v, py);

    return add(&x_comp, &y_comp);
}

color ray_color(camera *cam, ray *r, int depth, hittable_list *world) {
    hit_record rec;
    
    if (depth <= 0)
            return initValue(0,0,0);

    if (list_hit(world, r, interval_value(0.001, infinity), &rec)) {
        ray scattered;
        color attenuation;
        switch (rec.mat->type) {
        case LAMBERTIAN:
            if (scatter_lambertian(rec.mat->sf.lbt, r, &rec, &attenuation, &scattered)) {
                color col = ray_color(cam, &scattered, depth - 1, world);
                return mult(&attenuation, &col);
            }
            break;
        case METAL:
            if (scatter_metal(rec.mat->sf.mtl, r, &rec, &attenuation, &scattered)) {
                color col = ray_color(cam, &scattered, depth - 1, world);
                return mult(&attenuation, &col);
            }
            break;
        case DIELECTRIC:
            if (scatter_dielectric(rec.mat->sf.dlc, r, &rec, &attenuation, &scattered)) {
                color col = ray_color(cam, &scattered, depth - 1, world);
                return mult(&attenuation, &col);
            }
            break;
        default:
            break;
        }

        return initValue(0,0,0);
    }

    vec3 unit_direction = unit(&r->direction);
    double a = 0.5*(y(&unit_direction) + 1.0);

    color white = initValue(1, 1, 1);
    color grad = initValue(0.5, 0.7, 1.0);
    color comp1 = mult_num(&white, (1.0 - a));
    color comp2 = mult_num(&grad, a);
    return add(&comp1, &comp2);
}

void initialize_camera(camera *cam) {
    cam->image_height = (int)(cam->image_width / cam->aspect_ratio);
    cam->image_height = (cam->image_height < 1) ? 1 : cam->image_height;

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)cam->image_width/cam->image_height);
    cam->center = initValue(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    vec3 viewport_u = initValue(viewport_width, 0, 0);
    vec3 viewport_v = initValue(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    cam->pixel_delta_u = div_num(&viewport_u, cam->image_width);
    cam->pixel_delta_v = div_num(&viewport_v, cam->image_height);
    vec3 pixel_sum = add(&cam->pixel_delta_u, &cam->pixel_delta_v);
    vec3 pixel_sum_half = div_num(&pixel_sum, 2);

    // Calculate the location of the upper left pixel.
    vec3 viewport_u_half = div_num(&viewport_u, 2);
    vec3 viewport_v_half = div_num(&viewport_v, 2);
    vec3 neg_u = neg(&viewport_u_half);
    vec3 neg_v = neg(&viewport_v_half);
    vec3 focal_vec = initValue(0, 0, focal_length);
    vec3 cam_foc = sub(&cam->center, &focal_vec);
    vec3 viewports = add(&neg_u, &neg_v);
    vec3 viewport_upper_left = add(&cam_foc, &viewports);
    // camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    cam->pixel00_loc = add(&viewport_upper_left, &pixel_sum_half);
}