#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include <cmath>
#include "../src/circle.h"

TEST(CircleTest, AreaTest) {
    Circle c{{0.0, 0.0}, 5.0};

    double result = c.area();

    EXPECT_NEAR(5.0 * 5.0 * M_PI, result, 0.001);
}

TEST(CircleTest, PerimeterTest) {
    Circle c{{0.0, 0.0}, 5.0};

    double result = c.perimeter();

    EXPECT_NEAR(2.0 * 5.0 * M_PI, result, 0.001);
}

TEST(CircleTest, ToStringTest) {
    Circle c{{0.0, 0.0}, 5.0};

    std::string result = c.to_string();

    EXPECT_EQ("Circle 0.00 0.00 5.00", result);
}