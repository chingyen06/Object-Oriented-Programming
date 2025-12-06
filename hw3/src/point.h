#ifndef POINT_H
#define POINT_H

#include <string>
class Point{
public:
    double x;
    double y;
    
    double get_euclidean_distance(Point q);

    std::string get_quadrant();

    bool is_collinear(Point q, Point r);
    
    Point get_midpoint(Point q);
};
#endif