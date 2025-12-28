#include <gtest/gtest.h>
#include "../src/library_item.h"
#include "../src/book.h"
#include "../src/reference_book.h"

TEST(LibraryItem, GetTicketToken) {
    LibraryItem::Ticket t(1234);

    EXPECT_EQ(1234, t.get_token());
}

TEST(LibraryItem, BookBasedTest) {
    LibraryItem* item = Book::make_book("Computer Science", "Tseng Ching-Yen");

    EXPECT_EQ("Computer Science", item->get_title());
    EXPECT_EQ("Tseng Ching-Yen", item->get_author());
    EXPECT_EQ("Book", item->get_type());
    EXPECT_EQ("Book: Computer Science by Tseng Ching-Yen", item->to_string());
}

TEST(LibraryItem, ReferenceBookBasedTest) {
    LibraryItem* item = ReferenceBook::make_reference_book("Linear Algebra", "Tseng Ching-Yen");

    EXPECT_EQ("Linear Algebra", item->get_title());
    EXPECT_EQ("Tseng Ching-Yen", item->get_author());
    EXPECT_EQ("ReferenceBook", item->get_type());
    EXPECT_EQ("ReferenceBook: Linear Algebra by Tseng Ching-Yen", item->to_string());
}