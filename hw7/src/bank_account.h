#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>
#include <filesystem>
#include "transaction.h"

class BankAccount {
private:
    long id;
    std::string owner;
    std::string bank_code;
    double balance = 0;
    std::vector<Transaction*> history;

public:
    BankAccount(const std::string& owner, const std::string& bank_code);
    // Copy constructor
    BankAccount(BankAccount& other);
    // Copy assignment
    BankAccount& operator = (const BankAccount&);
    // Destructor
    ~BankAccount();
    // Overloaded operator +=
    BankAccount& operator += (double amount);

    long get_id() const;
    std::string get_owner() const;
    std::string get_bank_code() const;
    double get_balance() const;
    std::vector<Transaction*> get_history() const;

    void deposit(const double amount);
    void withdraw(const double amount);
    void export_to_csv(const std::filesystem::path& folder_path) const;
};

#endif // BANK_ACCOUNT_H