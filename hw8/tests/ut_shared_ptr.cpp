#include <gtest/gtest.h>
#include <string>
#include "../src/shared_ptr.h"

TEST(SharePointTest, CreateSharedPtr) {
    SharedPtr<std::string> sp(new std::string("Ching-Yen"));

    EXPECT_EQ(1, sp.reference_count());
    EXPECT_EQ("Ching-Yen", *sp);
}

TEST(SharePointTest, ShareAfterCreation) {
    SharedPtr<std::string> sp(new std::string("Ching-Yen"));

    SharedPtr<std::string> sp2(sp);
    
    // 測試 copy constructor 是否正確
    EXPECT_EQ(&(*sp), &(*sp2));
    EXPECT_EQ(2, sp.reference_count());
    EXPECT_EQ(2, sp2.reference_count());

    SharedPtr<std::string> sp3;

    sp3 = sp2;

    // 測試 copy assignment 是否正確
    EXPECT_EQ(&(*sp2), &(*sp3));
    EXPECT_EQ(3, sp2.reference_count());
    EXPECT_EQ(3, sp3.reference_count());

    // 更改指標內容後是否仍一致
    *sp3 = "YenYen";
    EXPECT_EQ("YenYen", *sp);
    EXPECT_EQ("YenYen", *sp2);
    EXPECT_EQ("YenYen", *sp3);
}

TEST(SharePointTest, ShareAndResetAfterCreation) {
    SharedPtr<std::string> sp(new std::string("Ching-Yen"));

    SharedPtr<std::string> sp2(sp);

    // 測試複製是否正確
    EXPECT_EQ(&(*sp), &(*sp2));
    EXPECT_EQ(2, sp.reference_count());
    EXPECT_EQ(2, sp2.reference_count());

    sp.reset();

    // 測試 reset 後是否正確
    EXPECT_EQ(1, sp2.reference_count());

    // 測試 reset 後 dereference 失敗的錯誤訊息
    EXPECT_THROW(*sp, std::bad_optional_access);

    sp2.reset();

    // 測試第二個也 reset 後是否完全被釋放
    EXPECT_EQ(0, sp.reference_count());
    EXPECT_EQ(0, sp2.reference_count());
}

TEST(SharePointTest, ResetAnAlreadyResetPointer) {
    SharedPtr<std::string> sp(new std::string("Ching-Yen"));

    SharedPtr<std::string> sp2(sp);

    sp.reset();

    // 測試 reset 後是否正確
    EXPECT_EQ(1, sp2.reference_count());

    // 第二次重複 reset sp
    sp.reset();

    // 測試第二次 reset 後是否依舊正確
    EXPECT_EQ(1, sp2.reference_count());
}

TEST(SharePointTest, AssignmentChain) {
    SharedPtr<std::string> sp(new std::string("Ching-Yen"));
    SharedPtr<std::string> sp2, sp3;
    SharedPtr<std::string> d(new std::string("YenYen"));

    sp3 = sp2 = sp;

    // 測試 assignment chain 是否正常
    EXPECT_EQ(&(*sp), &(*sp2));
    EXPECT_EQ(&(*sp2), &(*sp3));
    EXPECT_EQ(3, sp.reference_count());
    EXPECT_EQ(3, sp2.reference_count());
    EXPECT_EQ(3, sp3.reference_count());

    // 測試 d 是否不受影響
    EXPECT_EQ(1, d.reference_count());
    EXPECT_EQ("YenYen", *d);
}

TEST(SharePointTest, RaceCondition) {
    std::vector<std::thread> threads;
    SharedPtr<int> ptr6(new int(1));
    std::vector<SharedPtr<int>> vec(10);
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&vec, i, ptr6](){vec[i]=ptr6;});
    }

    for (auto& t : threads) {
        t.join();
    }
    assert(ptr6.reference_count()==11);
}
