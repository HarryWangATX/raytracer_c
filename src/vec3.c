#include "vec3.h"
#include <math.h>
#include <stdio.h>

vec3 initEmpty() {
    vec3 res = {{0.0, 0.0, 0.0}};
    return res;
}

vec3 initValue(double a, double b, double c) {
    vec3 res = {{a, b, c}};
    return res;
}

double x(vec3 *cur) {
    return cur->e[0];
}

double y(vec3 *cur) {
    return cur->e[1];
}

double z(vec3 *cur) {
    return cur->e[2];
}

vec3 neg(vec3 *cur) {
    vec3 nv = {{-x(cur), -y(cur), -z(cur)}};
    return nv;
}

vec3 *add_to(vec3 *self, vec3* other) {
    self->e[0] += other->e[0];
    self->e[1] += other->e[1];
    self->e[2] += other->e[2];
    return self;
}

vec3 *mult_to(vec3 *self, double t) {
    self->e[0] *= t;
    self->e[1] *= t;
    self->e[2] *= t;
    return self;
}

vec3 *div_to(vec3 *self, double t) {
    return mult_to(self, 1/t);
}

double length_squared(vec3 *vec) {
    return x(vec) * x(vec) + y(vec) * y(vec) + z(vec) * z(vec);
}

double len(vec3 *vec) {
    return sqrt(length_squared(vec));
}

void prt(vec3 *v) {
    printf("%f %f %f", v->e[0], v->e[1], v->e[2]);
}

vec3 add(vec3 *self, vec3* other) {
    vec3 res = {{x(self) + x(other),
                       y(self) + y(other),
                       z(self) + z(other)}};
    return res;
}

vec3 sub(vec3 *self, vec3* other) {
    vec3 res = {{x(self) - x(other),
                       y(self) - y(other),
                       z(self) - z(other)}};
    return res;
}

vec3 add_num(vec3 *self, double t) {
    vec3 res = {{x(self) + t,
                 y(self) + t,
                 z(self) + t}};
    return res;
}

vec3 mult_num(vec3 *self, double t) {
    vec3 res = {{x(self) * t,
                 y(self) * t,
                 z(self) * t}};
    return res;
}
vec3 div_num(vec3 *self, double t) {
    vec3 res = {{x(self) / t,
                 y(self) / t,
                 z(self) / t}};
    return res;
}

vec3 mult(vec3 *self, vec3* other) {
    vec3 res = {{x(self) * x(other),
                       y(self) * y(other),
                       z(self) * z(other)}};
    return res;
}

vec3 vec_div(vec3 *self, vec3* other) {
    vec3 res = {{x(self) / x(other),
                       y(self) / y(other),
                       z(self) / z(other)}};
    return res;
}

double dot(vec3 *u, vec3 *v) {
    return x(u) * x(v) + y(u) * y(v) + z(u) * z(v);
}

vec3 cross(vec3 *u, vec3 *v) {
    return initValue(u->e[1] * v->e[2] - u->e[2] * v->e[1],
                     u->e[2] * v->e[0] - u->e[0] * v->e[2],
                     u->e[0] * v->e[1] - u->e[1] * v->e[0]);
}

vec3 unit(vec3 *v) {
    return div_num(v, len(v));
}