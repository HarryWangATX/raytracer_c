#include "rt_utils.h"
#include "camera.h"
#include "color.h"
#include "hittables_list.h"
#include "sphere.h"
#include "material.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    FILE *file = fopen("images/blue.ppm", "w");

    if (file == NULL) {
        perror("Couldn't open file");
        return 1;
    }

    // World

    hittable_list world = initializeList();

    lambertian mat_ground = make_lambertian(initValue(0.5, 0.5, 0.5));
    dielectric mat1 = make_dielectric(1.5);
    lambertian mat2 = make_lambertian(initValue(0.4, 0.2, 0.1));
    metal mat3 = make_metal(initValue(0.7, 0.6, 0.5), 0.0);
    material *material_ground = create_material(LAMBERTIAN, create_surface(LAMBERTIAN, &mat_ground)); // make_shared<lambertian>(color(0.8, 0.8, 0.0));
    material *material1 = create_material(DIELECTRIC, create_surface(DIELECTRIC, &mat1));// make_shared<lambertian>(color(0.7, 0.3, 0.3));
    material *material2   = create_material(LAMBERTIAN, create_surface(LAMBERTIAN, &mat2));// make_shared<metal>(color(0.8, 0.8, 0.8));
    material *material3  = create_material(METAL, create_surface(METAL, &mat3));// make_shared<metal>(color(0.8, 0.6, 0.2));

    object *s1 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(0,-1000,0), 1000.0, material_ground)));
    object *s2 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(0, 1, 0), 1, material1)));
    object *s3 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(-4, 1, 0), 1.0, material2)));
    object *s4 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(4, 1, 0), 1.0, material3)));
    // object *s4 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(1.0,    0.0, -1.0),   0.5, material_right)));


    list_add(&world, s1);
    list_add(&world, s2);
    list_add(&world, s3);
    list_add(&world, s4);

    vector materials;
    initializeVector(&materials, 0);

    push_back(&materials, material_ground);
    push_back(&materials, material1);
    push_back(&materials, material2);
    push_back(&materials, material3);

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            double choose_mat = random_double_empt();
            point3 center = initValue(a + 0.9*random_double_empt(), 0.2, b + 0.9*random_double_empt());
            point3 pt = initValue(4, 0.2, 0);
            vec3 sub_res = sub(&center, &pt);

            if (len(&sub_res) > 0.9) {
                if (choose_mat < 0.8) {
                    // diffuse
                    vec3 rand_vec = random_vec();
                    vec3 rand_vec_2 = random_vec();
                    color albedo = mult(&rand_vec, &rand_vec_2);
                    lambertian sphere_material = make_lambertian(albedo);
                    material *material_sphere = create_material(LAMBERTIAN, create_surface(LAMBERTIAN, &sphere_material)); 
                    push_back(&materials, material_sphere);
                    object *sphere_lamb = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(center, 0.2, material_sphere)));
                    list_add(&world, sphere_lamb);
                } else if (choose_mat < 0.95) {
                    // metal
                    color albedo = random_vec_value(0.5, 1);
                    double fuzz = random_double(0, 0.5);
                    metal sphere_material = make_metal(albedo, fuzz);
                    material *material_sphere = create_material(METAL, create_surface(METAL, &sphere_material)); 
                    push_back(&materials, material_sphere);
                    object *sphere_mtl = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(center, 0.2, material_sphere)));
                    list_add(&world, sphere_mtl);
                } else {
                    // glass
                    dielectric sphere_material = make_dielectric(1.5);
                    material *material_sphere = create_material(DIELECTRIC, create_surface(DIELECTRIC, &sphere_material));
                    push_back(&materials, material_sphere); 
                    object *sphere_dlc = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(center, 0.2, material_sphere)));
                    list_add(&world, sphere_dlc);
                }
            }
        }
    }



    camera cam = {.aspect_ratio = 16.0/9.0, .image_width = 1200, .samples_per_pixel = 500, .max_depth = 50, .vfov = 20, .lookfrom = {{13, 2, 3}},
                  .lookat = {{0, 0, 0}}, .vup = {{0, 1, 0}}, .defocus_angle = 0.6, .focus_dist = 10.0};

    render(&cam, &world, file);

    for (int cnt = 0; cnt < world.objects.size; cnt++) {
        free_object((object *)list_get(&world.objects, cnt));
    }
    free_vec(&world.objects);

    for (int cnt = 0; cnt < materials.size; cnt++) {
        free_material((material *)list_get(&materials, cnt));
    }
    free_vec(&materials);

    fclose(file);
}
