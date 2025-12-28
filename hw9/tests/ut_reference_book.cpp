#include <gtest/gtest.h>
#include "../src/reference_book.h"

TEST(ReferenceBook, TotalTest) {
    LibraryItem* item = ReferenceBook::make_reference_book("Linear Algebra", "Tseng Ching-Yen");

    EXPECT_EQ("Linear Algebra", item->get_title());
    EXPECT_EQ("Tseng Ching-Yen", item->get_author());
    EXPECT_EQ("ReferenceBook", item->get_type());
    EXPECT_EQ("ReferenceBook: Linear Algebra by Tseng Ching-Yen", item->to_string());
}

TEST(ReferenceBook, ReferenceBookFactoryTest) {
    // return nullptr (title empty)
    LibraryItem* item = ReferenceBook::make_reference_book("", "Tseng Ching-Yen");
    EXPECT_EQ(nullptr, item);

    // return nullptr (author empty)
    item = ReferenceBook::make_reference_book("Linear Algebra", "");
    EXPECT_EQ(nullptr, item);

    // return nullptr (both empty)
    item = ReferenceBook::make_reference_book("", "");
    EXPECT_EQ(nullptr, item);

    // normal case
    item = ReferenceBook::make_reference_book("Linear Algebra", "Tseng Ching-Yen");
    EXPECT_EQ("Linear Algebra", item->get_title());
    EXPECT_EQ("Tseng Ching-Yen", item->get_author());
    EXPECT_EQ("ReferenceBook", item->get_type());
    EXPECT_EQ("ReferenceBook: Linear Algebra by Tseng Ching-Yen", item->to_string());
}