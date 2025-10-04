#include <gtest/gtest.h>
#include <string>

TEST(StringTest, LengthTest) {
    std::string str = "Hello World";

    int expected_result = 11;
    int actual_result = str.length();

    EXPECT_EQ(expected_result, actual_result);
}

TEST(StringTest, EmptyTest) {
    std::string str = "";

    bool actual_result = str.empty();

    EXPECT_TRUE(actual_result);
}

TEST(StringTest, ClearTest) {
    std::string str = "Hello World";
    str.clear();

    bool actual_result = str.empty();

    EXPECT_TRUE(actual_result);
}

TEST(StringTest, InsertTest) {
    std::string str = "Hello World";
    str.insert(5, ",");

    std::string expected_result = "Hello, World";
    std::string actual_result = str;

    EXPECT_EQ(expected_result, actual_result);
}

TEST(StringTest, CopyTest) {
    std::string str = "Hello World";
    char buffer[6];
    str.copy(buffer, 5, 0);
    buffer[5] = '\0';

    std::string expected_result = "Hello";
    std::string actual_result = buffer;

    EXPECT_EQ(expected_result, actual_result);
}

TEST(StringTest, CompareSameTest) {
    std::string str1 = "Hello";
    std::string str2 = "Hello";

    int result = str1.compare(str2);

    EXPECT_EQ(result, 0);
}

TEST(StringTest, CompareBiggerTest) {
    std::string str1 = "Helloooooo";
    std::string str2 = "Hello";

    int result = str1.compare(str2);

    EXPECT_GT(result, 0);
}

TEST(StringTest, CompareSmallerTest) {
    std::string str1 = "Hello";
    std::string str2 = "Helloooooo";

    int result = str1.compare(str2);

    EXPECT_LT(result, 0);
}

TEST(StringTest, SwapTest) {
    std::string str1 = "Hello";
    std::string str2 = "World";

    str1.swap(str2);

    EXPECT_EQ("World", str1);
    EXPECT_EQ("Hello", str2);
}

TEST(StringTest, FindFoundTest) {
    std::string str = "Hello World";

    size_t expected_result = 6;
    size_t actual_result = str.find("World");

    EXPECT_EQ(expected_result, actual_result);
}

TEST(StringTest, FindNotFoundTest) {
    std::string str = "Hello World";

    size_t expected_result = std::string::npos;
    size_t actual_result = str.find("abc");

    EXPECT_EQ(expected_result, actual_result);
}