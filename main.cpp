#include <iostream>
#include "UserAccount.h"
#include "Transaction.h"
#include "FilePersistence.h"
using namespace std;
int main() {
    using namespace Bank;

    UserAccount user1(123456, "John Doe", 1000.0, 1234);
    UserAccount user2(654321, "Jane Smith", 5000.0, 4321);

    Transaction transaction1("2023-08-10", TransactionType::DEPOSIT, 1000.0);
    Transaction transaction2("2023-08-11", TransactionType::WITHDRAWAL, 500.0);

    std::vector<UserAccount> accounts;
    accounts.push_back(user1);
    accounts.push_back(user2);

    std::vector<Transaction> transactions;
    transactions.push_back(transaction1);
    transactions.push_back(transaction2);

/********************************************************************************/
    // for(auto & user : accounts){
    //     cout<<user.getAccountNumber()<<" "<<user.getAccountUserName()<<" ";
    //     cout<<user.getBalance()<< " "<<user.getPIN()<<endl;
    //     cout<<"----------------------------------------------------"<<endl;
    // }
    // if (FilePersistence::saveUserAccounts(accounts, "user_accounts.dat")) {
    //     std::cout << "User accounts saved successfully." << std::endl;
    // } else {
    //     std::cout << "Failed to save user accounts." << std::endl;
    // }

    // std::vector<UserAccount> loadedAccounts;
    // if (FilePersistence::loadUserAccounts(loadedAccounts, "user_accounts.dat")) {
    //     std::cout << "User accounts  load successfully." << std::endl;

    //     // for (const UserAccount& account : loadedAccounts) {
    //     //     std::cout << account.getAccountUserName() << " - " << account.getBalance() << "\n";
    //     // }
    // } else {
    //     std::cout << "Failed to load user accounts." << std::endl;
    // }
    // cout<<"the loadedAccounts"<<endl;
    // for(auto & user : loadedAccounts){
    //     cout<<user.getAccountNumber()<<" "<<user.getAccountUserName()<<" ";
    //     cout<<user.getBalance()<< " "<<user.getPIN()<<endl;
    //     cout<<"----------------------------------------------------"<<endl;
    // }
/********************************************************************************/

    if (FilePersistence::saveUserAccounts(accounts, "user_accounts.dat")) {
        std::cout << "User accounts saved successfully." << std::endl;
    } else {
        std::cout << "Failed to save user accounts." << std::endl;
    }

    if (FilePersistence::saveTransactions(transactions, "transactions.dat")) {
        std::cout << "Transactions saved successfully." << std::endl;
    } else {
        std::cout << "Failed to save transactions." << std::endl;
    }

    std::vector<UserAccount> loadedAccounts;
    if (FilePersistence::loadUserAccounts(loadedAccounts, "user_accounts.dat")) {
        for (const UserAccount& account : loadedAccounts) {
            std::cout << account.getAccountUserName() << " - " << account.getBalance() << "\n";
        }
    } else {
        std::cout << "Failed to load user accounts." << std::endl;
    }

    std::vector<Transaction> loadedTransactions;
    if (FilePersistence::loadTransactions(loadedTransactions, "transactions.dat")) {
        for (const Transaction& transaction : loadedTransactions) {
            std::cout << transaction.getDate() << " - " << transaction.getAmount() << "\n";
        }
    } else {
        std::cout << "Failed to load transactions." << std::endl;
    }

    return 0;
}
