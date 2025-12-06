#include "gtest/gtest.h"
#include "../src/library_management_system.h"
#include "../src/book.h"
#include "../src/ebook.h"
#include "../src/reference_book.h"

TEST(LibraryManagementSystemTest, SearchByTitleTest) {
    LibraryManagementSystem libaray;
    Book book(1, "Computer Science", "Tseng Ching-Yen");
    libaray.add_item(&book);

    std::vector<LibraryItem*> result = libaray.search_by_title("Computer Science");

    EXPECT_EQ(1, result.size());
}

TEST(LibraryManagementSystemTest, SearchByTitleZeroTest) {
    LibraryManagementSystem libaray;
    Book book(1, "Computer Science", "Tseng Ching-Yen");
    libaray.add_item(&book);

    std::vector<LibraryItem*> result = libaray.search_by_title("Digital Design");

    EXPECT_EQ(0, result.size());
}

TEST(LibraryManagementSystemTest, SearchByTitlePartTest) {
    LibraryManagementSystem libaray;
    Book book(3, "Linear Algebra and Its Applications", "Tseng Ching-Yen");
    libaray.add_item(&book);

    std::vector<LibraryItem*> result = libaray.search_by_title("Linear Algebra");

    EXPECT_EQ(1, result.size());
}

TEST(LibraryManagementSystemTest, SearchByAuthorTest) {
    LibraryManagementSystem libaray;
    Book book(1, "Computer Science", "Tseng Ching-Yen");

    libaray.add_item(&book);

    std::vector<LibraryItem*> result = libaray.search_by_author("Tseng Ching-Yen");

    EXPECT_EQ(1, result.size());
}

TEST(LibraryManagementSystemTest, SearchByAuthorZeroTest) {
    LibraryManagementSystem libaray;
    Book book(1, "Computer Science", "Tseng Ching-Yen");

    libaray.add_item(&book);

    std::vector<LibraryItem*> result = libaray.search_by_author("Tan Sun-Yen");

    EXPECT_EQ(0, result.size());
}

TEST(LibraryManagementSystemTest, SearchByAuthorPartTest) {
    LibraryManagementSystem libaray;
    Book book(3, "Linear Algebra and Its Applications", "Tseng Ching-Yen");
    libaray.add_item(&book);

    std::vector<LibraryItem*> result = libaray.search_by_author("Ching-Yen");

    EXPECT_EQ(1, result.size());
}