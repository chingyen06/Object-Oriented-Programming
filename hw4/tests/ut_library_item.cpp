#include <gtest/gtest.h>
#include "../src/library_item.h"
#include "../src/book.h"
#include "../src/ebook.h"
#include "../src/reference_book.h"

TEST(LibraryItemTest, BookBasedTest) {
    Book book{1, "Computer Science", "Tseng Ching-Yen"};

    LibraryItem *item = &book;

    EXPECT_EQ(1, item->get_unique_id());
    EXPECT_EQ("Computer Science", item->get_title());
    EXPECT_EQ("Tseng Ching-Yen", item->get_author());
    EXPECT_EQ("Book", item->get_type());
    EXPECT_EQ("Book: Computer Science by Tseng Ching-Yen", item->to_string());
}

TEST(LibraryItemTest, EBookBasedTest) {
    EBook ebook{2, "Digital Design", "Tseng Ching-Yen"};

    LibraryItem *item = &ebook;

    EXPECT_EQ(2, item->get_unique_id());
    EXPECT_EQ("Digital Design", item->get_title());
    EXPECT_EQ("Tseng Ching-Yen", item->get_author());
    EXPECT_EQ("EBook", item->get_type());
    EXPECT_EQ("EBook: Digital Design by Tseng Ching-Yen", item->to_string());
}

TEST(LibraryItemTest, ReferenceBookBasedTest) {
    ReferenceBook rbook{3, "Linear Algebra", "Tseng Ching-Yen"};

    LibraryItem *item = &rbook;

    EXPECT_EQ(3, item->get_unique_id());
    EXPECT_EQ("Linear Algebra", item->get_title());
    EXPECT_EQ("Tseng Ching-Yen", item->get_author());
    EXPECT_EQ("ReferenceBook", item->get_type());
    EXPECT_EQ("ReferenceBook: Linear Algebra by Tseng Ching-Yen", item->to_string());
}