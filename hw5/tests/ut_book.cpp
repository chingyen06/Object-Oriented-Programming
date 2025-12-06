#include <gtest/gtest.h>
#include "../src/book.h"

TEST(BookTest, GetTypeTest) {
    Book book{1, "Computer Science", "Tseng Ching-Yen"};


    std::string expected_result = "Book";
    std::string actual_result = book.get_type();

    EXPECT_EQ(expected_result, actual_result);
}

TEST(BookTest, ToStringTest) {
    Book book{1, "Computer Science", "Tseng Ching-Yen"};

    std::string expected_result = "Book: Computer Science by Tseng Ching-Yen";
    std::string actual_result = book.to_string();

    EXPECT_EQ(expected_result, actual_result);
}