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

interval empty = {INFINITY, -INFINITY};
interval universe = {-INFINITY, INFINITY};