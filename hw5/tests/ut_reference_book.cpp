#include <gtest/gtest.h>
#include "../src/reference_book.h"

TEST(ReferenceBookTest, GetTypeTest) {
    ReferenceBook rbook{3, "Linear Algebra", "Tseng Ching-Yen"};


    std::string expected_result = "ReferenceBook";
    std::string actual_result = rbook.get_type();

    EXPECT_EQ(expected_result, actual_result);
}

TEST(ReferenceBookTest, ToStringTest) {
    ReferenceBook rbook{3, "Linear Algebra", "Tseng Ching-Yen"};

    std::string expected_result = "ReferenceBook: Linear Algebra by Tseng Ching-Yen";
    std::string actual_result = rbook.to_string();

    EXPECT_EQ(expected_result, actual_result);
}