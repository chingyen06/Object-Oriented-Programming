#include <gtest/gtest.h>
#include "../src/library_management_system.h"
#include "../src/book.h"
#include "../src/ebook.h"
#include "../src/reference_book.h"
#include <fstream>

TEST(LibraryManagementSystemIOTest, RemoveItemTest) {
    LibraryManagementSystem libaray;

    libaray.add_item(new Book(1, "Computer Science", "Kuo Jong-Yih"));
    libaray.add_item(new EBook(2, "Digital Design", "Tan Sun-Yen"));
    libaray.add_item(new ReferenceBook(3, "Linear Algebra and Its Applications", "Yang Shih-Hsuan"));
    libaray.add_item(new Book(4, "How To Solve It?", "Cheng Yu-Chin"));

    EXPECT_EQ(4, libaray.get_total_items());

    libaray.remove_item(1);  //刪掉 book(1, "Computer Science", "Kuo Jong-Yih")
    libaray.remove_item(2);  //刪掉 Ebook(2, "Digital Design", "Tan Sun-Yen")
    libaray.remove_item(3);  //刪掉 ReferenceBook(3, "Linear Algebra and Its Applications", "Yang Shih-Hsuan")

    EXPECT_EQ(1, libaray.get_total_items());

    EXPECT_TRUE(libaray.search_by_author("Kuo Jong-Yih").empty());  //用 empty 代表沒找到
    EXPECT_TRUE(libaray.search_by_author("Tan Sun-Yen").empty());
    EXPECT_TRUE(libaray.search_by_author("Yang Shih-Hsuan").empty());
    
    LibraryItem* item = libaray.search_by_author("Cheng Yu-Chin")[0];
    EXPECT_EQ(item->get_unique_id(), 4);
    EXPECT_EQ(item->get_title(), "How To Solve It?");
    EXPECT_EQ(item->get_author(), "Cheng Yu-Chin");
    EXPECT_EQ(item->get_type(), "Book");
}

TEST(LibraryManagementSystemIOTest, SaveFileTest) {
    LibraryManagementSystem libaray;

    libaray.add_item(new Book(1, "Digital Design", "Tan Sun-Yen"));

    std::filesystem::path output_path = "output.txt";

    libaray.save_to_file(output_path);

    std::ifstream ifs(output_path);
    std::string line;
    int i = 0;

    std::getline(ifs, line);

    EXPECT_EQ("1,Book,Digital Design,Tan Sun-Yen", line);

    std::filesystem::remove(output_path);
}

TEST(LibraryManagementSystemIOTest, LoadFileTest) {
    // 先 save file
    LibraryManagementSystem libaray;

    libaray.add_item(new Book(1, "Digital Design", "Tan Sun-Yen"));

    std::filesystem::path output_path = "output.txt";

    libaray.save_to_file(output_path);

    // 正式 load file
    libaray.load_from_file(output_path);

    LibraryItem* item = libaray.search_by_author("Tan Sun-Yen")[0];
    EXPECT_EQ(item->get_unique_id(), 1);
    EXPECT_EQ(item->get_title(), "Digital Design");
    EXPECT_EQ(item->get_author(), "Tan Sun-Yen");
    EXPECT_EQ(item->get_type(), "Book");

    std::filesystem::remove(output_path);
}

TEST(LibraryManagementSystemIOTest, ClearTest) {
    LibraryManagementSystem libaray;

    libaray.add_item(new Book(1, "Computer Science", "Kuo Jong-Yih"));
    libaray.add_item(new EBook(2, "Digital Design", "Tan Sun-Yen"));
    libaray.add_item(new ReferenceBook(3, "Linear Algebra and Its Applications", "Yang Shih-Hsuan"));
    libaray.add_item(new Book(4, "How To Solve It?", "Cheng Yu-Chin"));

    EXPECT_EQ(4, libaray.get_total_items());

    libaray.clear();

    EXPECT_EQ(0, libaray.get_total_items());
}

// TEST(LibraryManagementSystemIOTest, ClearTest2) {
//     LibraryManagementSystem libaray;

//     Book book(1, "Computer Science", "Kuo Jong-Yih");
//     EBook ebook(2, "Digital Design", "Tan Sun-Yen");
//     ReferenceBook rbook(3, "Linear Algebra and Its Applications", "Yang Shih-Hsuan");
//     Book book2(4, "How To Solve It?", "Cheng Yu-Chin");

//     libaray.add_item(&book);
//     libaray.add_item(&ebook);
//     libaray.add_item(&rbook);
//     libaray.add_item(&book2);

//     EXPECT_EQ(4, libaray.get_total_items());

//     libaray.clear();

//     EXPECT_EQ(0, libaray.get_total_items());
// }
// 這會記憶體洩漏，但先不管