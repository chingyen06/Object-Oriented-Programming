#include <gtest/gtest.h>
#include <cmath>
#include "../src/triangle.h"

TEST(TriangleTest, PerimeterTest) {
    Triangle t;
    t.p = {0.0, 0.0};
    t.q = {3.0, 0.0};
    t.r = {3.0, 4.0};

    double expected_result = 3 + 4 + std::sqrt(3*3+4*4);
    double actual_result = t.perimeter();

    EXPECT_NEAR(expected_result, actual_result, 0.001);
}

TEST(TriangleTest, NonEquilAteralTest) {
    Triangle t;
    t.p = {0.0, 0.0};
    t.q = {3.0, 0.0};
    t.r = {3.0, 4.0};

    double actual_result = t.is_equilateral();

    EXPECT_FALSE(actual_result);
}

TEST(TriangleTest, EquilAteralTest) {
    Triangle t;
    t.p = {0.0, 0.0};
    t.q = {1.0, 0.0};
    t.r = {0.5, std::sqrt(3.0)/2.0};

    double actual_result = t.is_equilateral();

    EXPECT_TRUE(actual_result);
}

TEST(TriangleTest, NonRightTriangleTest) {
    Triangle t;
    t.p = {0.0, 0.0};
    t.q = {1.0, 0.0};
    t.r = {0.5, std::sqrt(3.0)/2.0};

    double actual_result = t.is_right();

    EXPECT_FALSE(actual_result);
}

TEST(TriangleTest, RightTriangleTest) {
    Triangle t;
    t.p = {0.0, 0.0};
    t.q = {3.0, 0.0};
    t.r = {3.0, 4.0};

    double actual_result = t.is_right();
    
    EXPECT_TRUE(actual_result);
}