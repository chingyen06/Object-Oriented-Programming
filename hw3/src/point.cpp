#include "point.h"
#include <cmath>

double Point::get_euclidean_distance(Point q)
{
    return std::sqrt((x-q.x)*(x-q.x)+(y-q.y)*(y-q.y));
}

std::string Point::get_quadrant()
{
    if (x == 0 || y == 0)
        return "not in any quadrant";
    else if (x > 0 && y > 0)
        return "first";
    else if (x < 0 && y > 0)
        return "second";
    else if (x < 0 && y < 0)
        return "third";
    else
        return "fourth";
}

bool Point::is_collinear(Point q, Point r)
{
    double m1, m2;  //m1 為線段 pq 斜率, m2 為線段 qr 斜率

    if (x == q.x || q.x == r.x) {  //避免除以零
        if (x == q.x && q.x == r.x)
            return true;

        return false;
    }

    m1 = (y - q.y) / (x - q.x);
    m2 = (q.y - r.y) / (q.x - r.x);

    if (std::abs(m1-m2) < 0.001)  //避免誤差
        return true;
    
    return false;
}

Point Point::get_midpoint(Point q)
{
    Point mid;

    mid.x = (x + q.x) / 2;
    mid.y = (y + q.y) / 2;

    return mid;
}