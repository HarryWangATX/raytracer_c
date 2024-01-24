#include "rt_utils.h"
#include "camera.h"
#include "color.h"
#include "hittables_list.h"
#include "sphere.h"

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
    object *s1 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(0, 0, -1), 0.5)));
    object *s2 = create_object(SPHERE_TYPE, create_shape(SPHERE_TYPE, (void *) makeSphere(initValue(0, -100.5, -1), 100)));

    list_add(&world, s1);
    list_add(&world, s2);

    camera cam = {.aspect_ratio = 16.0/9.0, .image_width = 400, .samples_per_pixel = 100, .max_depth = 10};

    render(&cam, &world, file);

    for (int cnt = 0; cnt < world.objects.size; cnt++) {
        free_object((object *)list_get(&world.objects, cnt));
    }
    free_vec(&world.objects);

    fclose(file);
}
