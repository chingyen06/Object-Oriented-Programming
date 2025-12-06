#include <gtest/gtest.h>
#include "../src/triangle.h"

TEST(TriangleTest, AreaTest) {
    Triangle t{{0.0, 0.0}, {3.0, 0.0}, {3.0, 4.0}};

    double result = t.area();

    EXPECT_NEAR(6.0, result, 0.001);
}

TEST(TriangleTest, PerimeterTest) {
    Triangle t{{0.0, 0.0}, {3.0, 0.0}, {3.0, 4.0}};

    double result = t.perimeter();

    EXPECT_NEAR(12.0, result, 0.001);
}

TEST(TriangleTest, ToStringTest) {
    Triangle t{{0.0, 0.0}, {3.0, 0.0}, {3.0, 4.0}};

    std::string result = t.to_string();

    EXPECT_EQ("Triangle 0.00 0.00 3.00 0.00 3.00 4.00", result);
}