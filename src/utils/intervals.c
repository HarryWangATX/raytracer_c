#include "intervals.h"
#include <math.h>
#include <stdbool.h>

interval default_interval() {
    interval iv;
    iv.min = INFINITY;
    iv.max = -INFINITY;
    return iv;
}

interval interval_value(double s, double e) {
    interval iv;
    iv.min = s;
    iv.max = e;
    return iv;
}

interval interval_interval(interval *a, interval *b) {
    interval iv;
    iv.min = fmin(a->min, b->min);
    iv.max = fmax(a->max, b->max);
    return iv;
}

bool contains(interval *iv, double x) {
    return iv->min <= x && x <= iv->max;
}

bool surrounds(interval *iv, double x) {
    return iv->min < x && x < iv->max;
}

double clamp(interval *iv, double x) {
    if (x < iv->min) return iv->min;
    if (x > iv->max) return iv->max;
    return x;
}

interval expand(interval *iv, double delta) {
    interval new_iv;
    new_iv.min = iv->min - delta;
    new_iv.max = iv->max + delta;
    return new_iv;
}

interval empty = {INFINITY, -INFINITY};
interval universe = {-INFINITY, INFINITY};