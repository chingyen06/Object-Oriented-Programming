#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include "convex_polygon.h"
#include "triangle.h"

ConvexPolygon::ConvexPolygon() : vertices_() {}

ConvexPolygon::ConvexPolygon(std::vector<Point*> vertices) : vertices_(){
    for (auto vertex: vertices){
        vertices_.push_back(new Point(*vertex));
    }
}

ConvexPolygon::ConvexPolygon(const ConvexPolygon& other) : vertices_(){
    for (auto vertex: other.vertices_){
        vertices_.push_back(new Point(*vertex));
    }
}

ConvexPolygon::~ConvexPolygon(){
    for (auto vertex: vertices_){
        delete vertex;
    }
}

ConvexPolygon& ConvexPolygon::operator = (const ConvexPolygon& rhs){
    if (this == &rhs){
        return *this;
    }
    for (auto vertex: vertices_){
        delete vertex;
    }
    vertices_.clear();
    for (auto vertex: rhs.vertices_){
        vertices_.push_back(new Point(*vertex));
    }
    return *this;
}

double ConvexPolygon::area() const {
    double ans = 0;

    for (int i=1;i<vertices_.size()-1;i++) {
        ans += Triangle(*vertices_[0], *vertices_[i], *vertices_[i+1]).area();
    }

    return ans;
}

double ConvexPolygon::perimeter() const {
    double ans = 0;
    for (int i=0;i<vertices_.size();i++) {
        ans += distance(*vertices_[i], *vertices_[(i+1)%vertices_.size()]);
    }

    return ans;
}

bool ConvexPolygon::isConvexPolygon() const {
    if (vertices_.size() < 3)
        return false;

    double previous = 0, current = 0;

    for (int i=0;i<vertices_.size();i++) {
        Point A = *vertices_[i];
        Point B = *vertices_[(i + 1) % vertices_.size()];
        Point C = *vertices_[(i + 2) % vertices_.size()];

        double cross = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);

        if (cross != 0) {
            current = cross;

            if (current != 0 && current * previous < 0)  //方向改變
                return false;

            previous = current;
        }
    }

    return true;
}

std::string ConvexPolygon::to_string() const {
    std::ostringstream oss;

    oss << std::fixed << std::setprecision(2);

    oss << "ConvexPolygon " << vertices_[0]->x << " " << vertices_[0]->y;

    for (int i=1;i<vertices_.size();i++) {
        oss << " " << vertices_[i]->x << " " << vertices_[i]->y;
    }

    return oss.str();
}