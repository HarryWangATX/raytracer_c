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

    lambertian mat_ground = make_lambertian(initValue(0.8, 0.8, 0.0));
    lambertian mat_center = make_lambertian(initValue(0.1, 0.2, 0.5)); // make_dielectric(1.5);
    dielectric mat_left = make_dielectric(1.5);
    metal mat_right = make_metal(initValue(0.8, 0.6, 0.2), 0.0);
    material *material_ground = create_material(LAMBERTIAN, create_surface(LAMBERTIAN, &mat_ground)); // make_shared<lambertian>(color(0.8, 0.8, 0.0));
    material *material_center = create_material(LAMBERTIAN, create_surface(LAMBERTIAN, &mat_center));// make_shared<lambertian>(color(0.7, 0.3, 0.3));
    material *material_left   = create_material(DIELECTRIC, create_surface(DIELECTRIC, &mat_left));// make_shared<metal>(color(0.8, 0.8, 0.8));
    material *material_right  = create_material(METAL, create_surface(METAL, &mat_right));// make_shared<metal>(color(0.8, 0.6, 0.2));

    object *s1 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(0.0, -100.5, -1.0), 100.0, material_ground)));
    object *s2 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(0.0,    0.0, -1.0),   0.5, material_center)));
    object *s3 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(-1.0,    0.0, -1.0),   0.5, material_left)));
    object *s5 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(-1.0,    0.0, -1.0),   -0.4, material_left)));
    object *s4 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(1.0,    0.0, -1.0),   0.5, material_right)));


    list_add(&world, s1);
    list_add(&world, s2);
    list_add(&world, s3);
    list_add(&world, s4);
    list_add(&world, s5);

    camera cam = {.aspect_ratio = 16.0/9.0, .image_width = 400, .samples_per_pixel = 100, .max_depth = 10};

    render(&cam, &world, file);

    for (int cnt = 0; cnt < world.objects.size; cnt++) {
        free_object((object *)list_get(&world.objects, cnt));
    }
    free_vec(&world.objects);
    free_material(material_ground);
    free_material(material_center);
    free_material(material_left);
    free_material(material_right);
    fclose(file);
}
