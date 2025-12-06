#include "triangle.h"
#include <cmath>
#include <algorithm>

double Triangle::perimeter() {
    double distance;

    distance = p.get_euclidean_distance(q) + q.get_euclidean_distance(r) + r.get_euclidean_distance(p);

    return distance;
}

bool Triangle::is_equilateral() {
    double dis_pq = p.get_euclidean_distance(q), dis_qr = q.get_euclidean_distance(r), dis_rp = r.get_euclidean_distance(p);

    if (std::fabs(dis_pq-dis_qr) < 0.001 && std::fabs(dis_qr-dis_rp) < 0.001)
        return true;

    return false;
}

bool Triangle::is_right() {
    double side[3] = {p.get_euclidean_distance(q), q.get_euclidean_distance(r), r.get_euclidean_distance(p)};

    std::sort(side, side + 3);

    if (std::fabs(side[0]*side[0] + side[1]*side[1] - side[2]*side[2]) < 0.001)
        return true;

    return false;
}