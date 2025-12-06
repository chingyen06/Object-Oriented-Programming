#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle{
public:
    Point p;
    Point q;
    Point r;

    double perimeter();

    bool is_equilateral();

    bool is_right();
};
#endif