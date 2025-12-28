#include <gtest/gtest.h>
#include "../src/book.h"

TEST(Book, TotalTest) {
    LibraryItem* item = Book::make_book("Computer Science", "Tseng Ching-Yen");

    EXPECT_EQ("Computer Science", item->get_title());
    EXPECT_EQ("Tseng Ching-Yen", item->get_author());
    EXPECT_EQ("Book", item->get_type());
    EXPECT_EQ("Book: Computer Science by Tseng Ching-Yen", item->to_string());
}

TEST(Book, BookFactoryTest) {
    // return nullptr (title empty)
    LibraryItem* item = Book::make_book("", "Tseng Ching-Yen");
    EXPECT_EQ(nullptr, item);

    // return nullptr (author empty)
    item = Book::make_book("Computer Science", "");
    EXPECT_EQ(nullptr, item);

    // return nullptr (both empty)
    item = Book::make_book("", "");
    EXPECT_EQ(nullptr, item);


    // normal case
    item = Book::make_book("Computer Science", "Tseng Ching-Yen");
    EXPECT_EQ("Computer Science", item->get_title());
    EXPECT_EQ("Tseng Ching-Yen", item->get_author());
    EXPECT_EQ("Book", item->get_type());
    EXPECT_EQ("Book: Computer Science by Tseng Ching-Yen", item->to_string());
}