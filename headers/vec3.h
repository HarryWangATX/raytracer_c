#ifndef VEC3_H
#define VEC3_H

struct vec3 {
    double e[3]; // coords
};

typedef struct vec3 point3;
typedef struct vec3 vec3;

vec3 initEmpty();
vec3 initValue(double a, double b, double c);

double x(vec3 *cur);
double y(vec3 *cur);
double z(vec3 *cur);

vec3 neg(vec3 *cur);

vec3 *add_to(vec3 *self, vec3* other);
vec3 *mult_to(vec3 *self, double t);
vec3 *div_to(vec3 *self, double t);

double length_squared(vec3 *vec);
double len(vec3 *vec);

void prt(vec3 *v);

vec3 add(vec3 *self,  vec3* other);
vec3 sub(vec3 *self, vec3* other);
vec3 mult(vec3 *self, vec3* other);
vec3 vec_div(vec3 *self, vec3* other);
vec3 add_num(vec3 *self, double t);
vec3 mult_num(vec3 *self, double t);
vec3 div_num(vec3 *self, double t);


double dot(vec3 *u, vec3 *v);
vec3 cross(vec3 *u, vec3 *v);
vec3 unit(vec3 *v);

vec3 random_vec();
vec3 random_vec_value(double min, double max);
vec3 random_in_unit_sphere();
vec3 random_unit_vector();

vec3 random_on_hemisphere(vec3 *normal);

#endif