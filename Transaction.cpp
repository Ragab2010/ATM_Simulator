#include "Transaction.h"

namespace Bank {

Transaction::Transaction() : date(""), type(TransactionType::DEPOSIT), amount(0.0) {}

Transaction::Transaction(const std::string& date, TransactionType type, double amount)
    : date(""), type(type), amount(amount) {}

std::string Transaction::getDate() const {
    return date;
}

TransactionType Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

} // namespace Bank
