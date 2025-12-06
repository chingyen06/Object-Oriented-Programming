#include <gtest/gtest.h>
#include "../src/ebook.h"

TEST(EBookTest, GetTypeTest) {
    EBook ebook{2, "Digital Design", "Tseng Ching-Yen"};


    std::string expected_result = "EBook";
    std::string actual_result = ebook.get_type();

    EXPECT_EQ(expected_result, actual_result);
}

TEST(EBookTest, ToStringTest) {
    EBook ebook{2, "Digital Design", "Tseng Ching-Yen"};

    std::string expected_result = "EBook: Digital Design by Tseng Ching-Yen";
    std::string actual_result = ebook.to_string();

    EXPECT_EQ(expected_result, actual_result);
}