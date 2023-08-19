// UserAccount.h

#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <string>

namespace Bank {

class UserAccount {
public:
    UserAccount();
    UserAccount(int accountNumber, const std::string& accountUserName, double balance, int pin);

    int getAccountNumber() const;
    std::string getAccountUserName() const;
    void setaccountUserName(const std::string& name); // Add this method
    double getBalance() const;
    int getPIN() const;

private:
    int accountNumber;
    //std::string accountUserName; this will make an problem with write/read binary 
    char accountUserName[50];
    double balance;
    int pin;
};

} // namespace Bank

#endif // USERACCOUNT_H
