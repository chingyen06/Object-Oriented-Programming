#include <gtest/gtest.h>
#include "../src/bank_account.h"
#include <fstream>

TEST(Bank, GetID) {
    BankAccount bank1{"Ching", "1234"};
    BankAccount bank2{"Yen", "5678"};

    EXPECT_GT(bank1.get_id(), 0);
    EXPECT_GT(bank2.get_id(), 0);

    EXPECT_NE(bank1.get_id(), bank2.get_id());
}


TEST(Bank, GetCode) {
    BankAccount bank{"Ching", "1234"};

    EXPECT_EQ("1234", bank.get_bank_code());
}

TEST(Bank, GetOwner) {
    BankAccount bank{"Ching", "1234"};

    EXPECT_EQ("Ching", bank.get_owner());
}

TEST(Bank, GetBalance) {
    BankAccount bank{"Ching", "1234"};

    bank.deposit(1234.00);
    bank.withdraw(234.00);

    EXPECT_NEAR(1000.00, bank.get_balance(), 0.001);
}

TEST(Bank, GetHistory) {
    BankAccount bank{"Ching", "1234"};

    bank.deposit(1234.00);

    std::vector<Transaction*> his = bank.get_history();

    EXPECT_EQ("Deposit", his[0]->get_type());
    EXPECT_NEAR(1234.00, his[0]->get_amount(), 0.001);
    EXPECT_NEAR(1234.00, his[0]->get_balance_after(), 0.001);
}

TEST(Bank, GetDeposit) {
    BankAccount bank{"Ching", "1234"};

    bank.deposit(1234.00);

    EXPECT_NEAR(1234.00, bank.get_balance(), 0.001);
}

TEST(Bank, GetWithdraw) {
    BankAccount bank{"Ching", "1234"};

    bank.deposit(1234.00);
    bank.withdraw(34.00);

    EXPECT_NEAR(1200.00, bank.get_balance(), 0.001);
}

TEST(Bank, OperatorPlusEqual) {
    BankAccount bank{"Ching", "1234"};

    bank += 1200.00;

    EXPECT_NEAR(1200.00, bank.get_balance(), 0.001);
}

TEST(Bank, ToCSV) {
    BankAccount bank{"Ching", "1234"};

    bank.deposit(1234.00);
    bank.withdraw(34.00);

    bank.export_to_csv("test");

    std::ifstream ifs("test/history_" + std::to_string(bank.get_id()) + "_" + bank.get_owner() + "_" + bank.get_bank_code() + ".csv");

    std::string line;
    std::getline(ifs, line);
    EXPECT_EQ("Transaction Type,Amount,Balance After", line);
    std::getline(ifs, line);
    EXPECT_EQ("Deposit,1234.00,1234.00", line);
    std::getline(ifs, line);
    EXPECT_EQ("Withdraw,34.00,1200.00", line);
}
