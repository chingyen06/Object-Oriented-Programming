#include "point_function.h"
#include <cmath>

double get_euclidean_distance(Point p, Point q)
{
    return std::sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}

std::string get_quadrant(Point p)
{
    if (p.x == 0 || p.y == 0)
        return "not in any quadrant";
    else if (p.x > 0 && p.y > 0)
        return "first";
    else if (p.x < 0 && p.y > 0)
        return "second";
    else if (p.x < 0 && p.y < 0)
        return "third";
    else
        return "fourth";
}

bool is_collinear(Point p, Point q, Point r)
{
    double m1, m2;  //m1 為線段 pq 斜率, m2 為線段 qr 斜率

    if (p.x == q.x || q.x == r.x) {  //避免除以零
        if (p.x == q.x && q.x == r.x)
            return true;

        return false;
    }

    m1 = (p.y - q.y) / (p.x - q.x);
    m2 = (q.y - r.y) / (q.x - r.x);

    if (std::abs(m1-m2) < 0.001)  //避免誤差
        return true;
    
    return false;
}

Point get_midpoint(Point p, Point q)
{
    Point mid;

    mid.x = (p.x + q.x) / 2;
    mid.y = (p.y + q.y) / 2;

    return mid;
}