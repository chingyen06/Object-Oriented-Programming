#include <gtest/gtest.h>
#include "../src/library_management_system.h"
#include "../src/book.h"
#include "../src/reference_book.h"

TEST(ManagementSystem, AddItemTest) {
    LibraryManagementSystem library;
    // null item
    LibraryItem* item = nullptr;
    EXPECT_EQ(-1, library.add_item(item).get_token());
    EXPECT_EQ(0, library.get_total_items());

    // normal case
    item = Book::make_book("Computer Science", "Tseng Ching-Yen");
    EXPECT_EQ(1, library.add_item(item).get_token());
    EXPECT_EQ(1, library.get_total_items());
}

TEST(ManagementSystem, RemoveItemTest) {
    LibraryManagementSystem library;
    LibraryItem* item = Book::make_book("Computer Science", "Tseng Ching-Yen");
    library.add_item(item);
    
    // token is -1
    EXPECT_FALSE(library.remove_item(LibraryItem::Ticket(-1)));

    // token not exist
    EXPECT_FALSE(library.remove_item(LibraryItem::Ticket(8787)));

    // token checked out
    library.checkout(LibraryItem::Ticket(1));
    EXPECT_FALSE(library.remove_item(LibraryItem::Ticket(1)));

    // normal case
    LibraryItem* item2 = Book::make_book("Linear Algebra", "Tseng Ching-Yen");
    library.add_item(item2);
    EXPECT_EQ(2, library.get_total_items());  // 刪除前有兩個
    EXPECT_TRUE(library.remove_item(LibraryItem::Ticket(2)));

    EXPECT_EQ(1, library.get_total_items());  // 刪除後只剩一個
}

TEST(ManagementSystem, CheckOutTest) {
    LibraryManagementSystem library;
    LibraryItem* item = Book::make_book("Computer Science", "Tseng Ching-Yen");
    library.add_item(item);
    
    // token is -1
    EXPECT_FALSE(library.checkout(LibraryItem::Ticket(-1)));

    // token not exist
    EXPECT_FALSE(library.checkout(LibraryItem::Ticket(8787)));

    // token checked out
    library.checkout(LibraryItem::Ticket(1));
    EXPECT_FALSE(library.checkout(LibraryItem::Ticket(1)));

    // normal case
    LibraryItem* item2 = Book::make_book("Linear Algebra", "Tseng Ching-Yen");
    library.add_item(item2);
    EXPECT_EQ(1, library.get_available_items());  // item2 Check out 前有一個未 Check Out 物件(item2，因為 item 已經被 Check out 了)
    EXPECT_TRUE(library.checkout(LibraryItem::Ticket(2)));
    
    EXPECT_EQ(0, library.get_available_items());  // item2 Check out 後 0 個
    EXPECT_EQ(2, library.get_total_items());  // 總數還是兩個
}

TEST(ManagementSystem, ReturnItemTest) {
    LibraryManagementSystem library;
    LibraryItem* item = Book::make_book("Computer Science", "Tseng Ching-Yen");
    library.add_item(item);
    
    // token is -1
    EXPECT_FALSE(library.return_item(LibraryItem::Ticket(-1)));

    // token not exist
    EXPECT_FALSE(library.return_item(LibraryItem::Ticket(8787)));

    // token not checked out yet
    EXPECT_FALSE(library.return_item(LibraryItem::Ticket(1)));

    // normal case
    library.checkout(1);
    EXPECT_EQ(0, library.get_available_items());  // Return 前沒有未 Check Out 物件
    EXPECT_TRUE(library.return_item(LibraryItem::Ticket(1)));
    EXPECT_EQ(1, library.get_available_items());  // Return 後有一個 Check Out 物件
}

TEST(ManagementSystem, GetTotalItemTest) {
    LibraryManagementSystem library;
    LibraryItem* item = Book::make_book("Computer Science", "Tseng Ching-Yen");
    library.add_item(item);
    LibraryItem* item2 = Book::make_book("Linear Algebra", "Tseng Ching-Yen");
    library.add_item(item2);

    EXPECT_EQ(2, library.get_total_items());
}

TEST(ManagementSystem, GetAvailableItemTest) {
    LibraryManagementSystem library;
    LibraryItem* item = Book::make_book("Computer Science", "Tseng Ching-Yen");
    library.add_item(item);
    LibraryItem* item2 = Book::make_book("Linear Algebra", "Tseng Ching-Yen");
    library.add_item(item2);

    library.checkout(LibraryItem::Ticket(1));

    EXPECT_EQ(1, library.get_available_items());  // 未 Check Out 物件只剩一個
}

TEST(ManagementSystem, ClearTest) {
    LibraryManagementSystem library;
    LibraryItem* item = Book::make_book("Computer Science", "Tseng Ching-Yen");
    library.add_item(item);
    LibraryItem* item2 = Book::make_book("Linear Algebra", "Tseng Ching-Yen");
    library.add_item(item2);

    library.clear();

    EXPECT_EQ(0, library.get_total_items());  // 總數只剩 0 個
}