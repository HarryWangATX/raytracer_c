#ifndef INTERVAL_H
#define INTERVAL_H

#include "math.h"
#include <stdbool.h>

struct interval {
    double min, max;
};

typedef struct interval interval;

extern interval empty, universe;

interval default_interval();
interval interval_value(double s, double e);

bool contains(interval *iv, double x);
bool surrounds(interval *iv, double x);

double clamp(interval *iv, double x);

#endif