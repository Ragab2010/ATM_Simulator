// UserAccount.cpp

#include "UserAccount.h"
#include <cstring>

namespace Bank {

UserAccount::UserAccount() : accountNumber(0), accountUserName(""), balance(0.0), pin(0) {}

UserAccount::UserAccount(int accountNumber_,  const std::string& accountUserName_, double balance_, int pin_)
    : accountNumber(accountNumber_), accountUserName(""), balance(balance_), pin(pin_) {
        strcpy(accountUserName , accountUserName_.c_str());
    }

int UserAccount::getAccountNumber() const {
    return accountNumber;
}

std::string UserAccount::getAccountUserName() const {
    return accountUserName;
}

void UserAccount::setaccountUserName(const std::string& name) {
    //accountUserName = name;
    strcpy(accountUserName , name.c_str());
}

double UserAccount::getBalance() const {
    return balance;
}

int UserAccount::getPIN() const {
    return pin;
}

} // namespace Bank
