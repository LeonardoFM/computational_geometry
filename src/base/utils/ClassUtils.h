#pragma once

#include<math.h>

#define TOL 0.0000001

static bool isEqual1D(double x, double y) {
    return fabs(x - y) < TOL;
}