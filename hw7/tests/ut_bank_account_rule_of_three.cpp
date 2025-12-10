#include <gtest/gtest.h>
#include "../src/bank_account.h"

TEST(RuleOfThree, CopyConstructorTest) {
    BankAccount bank{"Ching", "1234"};
    BankAccount bank2(bank);

    EXPECT_NE(bank.get_id(), bank2.get_id());
    EXPECT_EQ("Ching", bank.get_owner());
    EXPECT_EQ("1234", bank.get_bank_code());
    EXPECT_NEAR(0.0, bank2.get_balance(), 0.001);
    EXPECT_TRUE(bank2.get_history().empty());
}

TEST(RuleOfThree, CopyAssignmentTest) {
    BankAccount bank{"Ching", "1234"};
    BankAccount bank2{"Yen", "8787"};

    bank.deposit(1234.00);

    bank2 = bank;

    std::vector<Transaction*> his = bank2.get_history();

    EXPECT_EQ(bank.get_id(), bank2.get_id());
    EXPECT_EQ("Ching", bank2.get_owner());
    EXPECT_EQ("1234", bank2.get_bank_code());
    EXPECT_NEAR(1234.0, bank2.get_balance(), 0.001);
    EXPECT_EQ("Deposit", his[0]->get_type());
    EXPECT_NEAR(1234.00, his[0]->get_amount(), 0.001);
    EXPECT_NEAR(1234.00, his[0]->get_balance_after(), 0.001);
}