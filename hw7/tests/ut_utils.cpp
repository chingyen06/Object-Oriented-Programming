#include <gtest/gtest.h>
#include "../src/utils.h"

TEST(Sort, Intergar) {
    std::vector v{1, 5, 2, 4, 3};

    bubble_sort(v.begin(), v.end());

    EXPECT_EQ((std::vector{1,2,3,4,5}), v);
}

TEST(Sort, Double) {
    std::vector v{1.1, 4.5, 2.7, 4.1, 3.2};

    bubble_sort(v.begin(), v.end());

    EXPECT_EQ((std::vector{1.1,2.7,3.2,4.1,4.5}), v);
}

TEST(Sort, IntergarWithComp) {
    std::vector v{1, 5, 2, 4, 3};

    bubble_sort(v.begin(), v.end(), [](int a, int b){return a > b;});

    EXPECT_EQ((std::vector{5,4,3,2,1}), v);
}

TEST(Sort, DoubleWithComp) {
    std::vector v{1.1, 4.5, 2.7, 4.1, 3.2};

    bubble_sort(v.begin(), v.end(), [](double a, double b){return a > b;});

    EXPECT_EQ((std::vector{4.5,4.1,3.2,2.7,1.1}), v);
}