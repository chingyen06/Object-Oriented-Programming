#include <gtest/gtest.h>
#include <vector>
#include "../src/point.h"
#include "../src/convex_polygon.h"

TEST(ConvexPolygonTest, AreaTest) {
    std::vector<Point *> vertices{
        new Point{0.0, 0.0},
        new Point{3.0, 0.0},
        new Point{3.0, 4.0},
        new Point{0.0, 4.0}
    };

    ConvexPolygon cp(vertices);

    double result = cp.area();

    EXPECT_NEAR(12.0, result, 0.001);

    for (auto vertex: vertices) 
        delete vertex;
}

TEST(ConvexPolygonTest, PerimeterTest) {
    std::vector<Point *> vertices{
        new Point{0.0, 0.0},
        new Point{3.0, 0.0},
        new Point{3.0, 4.0},
        new Point{0.0, 4.0}
    };

    ConvexPolygon cp(vertices);

    double result = cp.perimeter();

    EXPECT_NEAR(14.0, result, 0.001);

    for (auto vertex: vertices) 
        delete vertex;
}

TEST(ConvexPolygonTest, ToStringTest) {
    std::vector<Point *> vertices{
        new Point{0.0, 0.0},
        new Point{3.0, 0.0},
        new Point{3.0, 4.0},
        new Point{0.0, 4.0}
    };

    ConvexPolygon cp(vertices);

    std::string result = cp.to_string();

    EXPECT_EQ("ConvexPolygon 0.00 0.00 3.00 0.00 3.00 4.00 0.00 4.00", result);

    for (auto vertex: vertices) 
        delete vertex;
}