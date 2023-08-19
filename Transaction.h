#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

namespace Bank {

enum class TransactionType {
    DEPOSIT,
    WITHDRAWAL
};

class Transaction {
public:
    Transaction();
    Transaction(const std::string& date, TransactionType type, double amount);

    std::string getDate() const;
    TransactionType getType() const;
    double getAmount() const;

private:
/*
std::string date; 
it will cause problem at loadTransactions because read binary ,
mean (copy binary from file  and past it at memory location  of Transaction object), 
the problem that there an dynamic allocation for std::string date at Transaction object
and this is the problem we need dynamic allocation first then assing it by binary 
*/
    //std::string date; 
    const char  date[50];
    TransactionType type;
    double amount;
};

} // namespace Bank

#endif // TRANSACTION_H
