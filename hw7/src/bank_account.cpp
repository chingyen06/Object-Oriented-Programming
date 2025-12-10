#include "transaction.h"
#include "bank_account.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

BankAccount::BankAccount(const std::string& owner, const std::string& bank_code): owner(owner), bank_code(bank_code) {}

// Copy constructor
BankAccount::BankAccount(BankAccount& other): owner(), bank_code() {
    owner = other.owner;
    bank_code = other.bank_code;
    balance = 0;
    for (auto his: history) {
        delete his;
    }
    history.clear();
}

// Copy assignment
BankAccount& BankAccount::operator = (const BankAccount& rhs) {
    if (this == &rhs){
        return *this;
    }

    id = rhs.id;
    owner = rhs.owner;
    balance = rhs.balance;
    bank_code = rhs.bank_code;
    
    for (auto his: history) {
        delete his;
    }
    history.clear();

    for (auto his: rhs.history) {
        history.push_back(new Transaction(*his));
        // history.push_back(new Transaction(his->get_type(), his->get_amount(), his->get_balance_after()));
    }

    return *this;
}

// Destructor
BankAccount::~BankAccount() {
    for (auto his: history) {
        delete his;
    }
    history.clear();
}
// Overloaded operator +=
BankAccount& BankAccount::operator += (double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Must deposit a positive amount.");
    }
    else {
        balance += amount;

        history.push_back(new Transaction{"Deposit", amount, balance});  //暫定

        return *this;
    }
}

long BankAccount::get_id() const {
    return id;
}

std::string BankAccount::get_owner() const {
    return owner;
}

std::string BankAccount::get_bank_code() const {
    return bank_code;
}

double BankAccount::get_balance() const {
    return balance;
}

std::vector<Transaction*> BankAccount::get_history() const {
    return history;
}

void BankAccount::deposit(const double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Must deposit a positive amount.");
    }
    else {
        balance += amount;
        
        history.push_back(new Transaction{"Deposit", amount, balance});
    }
}
void BankAccount::withdraw(const double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Must withdraw a positive amount.");
    }
    else {
        if (balance < amount) {
            throw std::invalid_argument("Insufficient balance.");
        }
        else {
            balance -= amount;
            
            history.push_back(new Transaction{"Withdraw", amount, balance});
        }
    }
    
}
    
void BankAccount::export_to_csv(const std::filesystem::path& folder_path) const {
    std::filesystem::create_directories(folder_path);
    std::filesystem::path right_file = "history_" + std::to_string(id) + "_" + owner + "_" + bank_code + ".csv";
    right_file = folder_path / right_file;

    std::ofstream ofs(right_file);

    if (!ofs.is_open())
        throw std::runtime_error("Runtime Error");

    ofs << "Transaction Type,Amount,Balance After" << std::endl;

    for (auto his: history) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        
        oss << his->get_type() << "," << his->get_amount() << "," << his->get_balance_after();

        ofs << oss.str() << std::endl;
    }

    ofs.close();
}