#define _USE_MATH_DEFINES
#include "circle.h"
#include <cmath>
#include <sstream>
#include <iomanip>

Circle::Circle(Point c, double r): Shape(), center(c), radius(r) {}

double Circle::area() const{
    return M_PI * radius * radius;
}

double Circle::perimeter() const{
    return 2 * M_PI * radius;
}

std::string Circle::to_string() const {
    std::ostringstream oss;
    
    oss << std::fixed << std::setprecision(2);

    oss << "Circle " << center.x << " " << center.y << " " << radius;

    return oss.str();
}