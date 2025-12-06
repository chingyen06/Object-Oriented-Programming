#include "transaction.h"

Transaction::Transaction(const std::string& type, double amount, double balance_after): type(type), amount(amount), balance_after(balance_after) {}

std::string Transaction::get_type() const {
    return type;
}

double Transaction::get_amount() const {
    return amount;
}

double Transaction::get_balance_after() const {
    return balance_after;
}