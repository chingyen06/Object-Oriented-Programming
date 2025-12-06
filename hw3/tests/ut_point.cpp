#include <gtest/gtest.h>
#include <cmath>
#include "../src/point.h"

TEST(PointTest, DistanceTest) {
    Point p = {0.0, 0.0}, q = {2.0, 2.0};

    double expected_result = sqrt(8);
    double actual_result = p.get_euclidean_distance(q);

    EXPECT_NEAR(expected_result, actual_result, 0.001);
}

TEST(PointTest, FirstQuadrantTest) {
    Point p = {1.0, 1.0};

    std::string expected_result = "first";
    std::string actual_result = p.get_quadrant();

    EXPECT_EQ(expected_result, actual_result);
}

TEST(PointTest, SecondQuadrantTest) {
    Point p = {-1.0, 1.0};

    std::string expected_result = "second";
    std::string actual_result = p.get_quadrant();

    EXPECT_EQ(expected_result, actual_result);
}

TEST(PointTest, ThirdQuadrantTest) {
    Point p = {-1.0, -1.0};

    std::string expected_result = "third";
    std::string actual_result = p.get_quadrant();

    EXPECT_EQ(expected_result, actual_result);
}

TEST(PointTest, FourthQuadrantTest) {
    Point p = {1.0, -1.0};

    std::string expected_result = "fourth";
    std::string actual_result = p.get_quadrant();

    EXPECT_EQ(expected_result, actual_result);
}

TEST(PointTest, OnAxisTest) {
    Point p = {0.0, 1.0};

    std::string expected_result = "not in any quadrant";
    std::string actual_result = p.get_quadrant();

    EXPECT_EQ(expected_result, actual_result);
}

TEST(PointTest, CollinearVerticalTest) {
    Point p = {0.0, 0.0}, q = {0.0, 2.0}, r = {0.0, 2.0};

    bool actual_result = p.is_collinear(q, r);

    EXPECT_TRUE(actual_result);
}

TEST(PointTest, CollinearTrueTest) {
    Point p = {0.0, 0.0}, q = {1.0, 1.0}, r = {2.0, 2.0};

    bool actual_result = p.is_collinear(q, r);

    EXPECT_TRUE(actual_result);
}

TEST(PointTest, CollinearFalseTest) {
    Point p = {0.0, 0.0}, q = {1.0, 1.0}, r = {2.0, 3.0};

    bool actual_result = p.is_collinear(q, r);

    EXPECT_FALSE(actual_result);
}

TEST(PointTest, MidpointTest) {
    Point p = {0.0, 0.0}, q = {2.0, 2.0};

    Point expected_result = {1.0, 1.0};
    Point actual_result = p.get_midpoint(q);

    EXPECT_NEAR(expected_result.x, actual_result.x, 0.001);
    EXPECT_NEAR(expected_result.y, actual_result.y, 0.001);
}