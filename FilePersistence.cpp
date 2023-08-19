// FilePersistence.cpp

#include "FilePersistence.h"
#include <fstream>
#include <iostream>

namespace Bank {

bool FilePersistence::saveUserAccounts(const std::vector<UserAccount>& accounts, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::out);
    if (!outFile.is_open()) {
        std::cout<<"saveUserAccounts:outFile.is_open() == fail"<<std::endl;
        return false;
    }

    for (const UserAccount& account : accounts) {
        outFile.write(reinterpret_cast<const char*>(&account), sizeof(UserAccount));
    }

    outFile.close();
    return true;
}

bool FilePersistence::loadUserAccounts(std::vector<UserAccount>& accounts, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary | std::ios::in);
    if (!inFile.is_open()) {
        std::cout<<"loadUserAccounts:outFile.is_open() == fail"<<std::endl;  
        return false;
    }

    accounts.clear();
    UserAccount account;

    while (inFile.read(reinterpret_cast<char*>(&account), sizeof(UserAccount))) {
        accounts.push_back(account);
    }

    inFile.close();
    return true;
}

bool FilePersistence::saveTransactions(const std::vector<Transaction>& transactions, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::out);
    if (!outFile.is_open()) {
        std::cout<<"saveTransactions:outFile.is_open() == fail"<<std::endl;  
        return false;
    }

    for (const Transaction& transaction : transactions) {
        outFile.write(reinterpret_cast<const char*>(&transaction), sizeof(Transaction));
    }

    outFile.close();
    return true;
}

bool FilePersistence::loadTransactions(std::vector<Transaction>& transactions, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary | std::ios::in);
    if (!inFile.is_open()) {
        std::cout<<"loadTransactions:outFile.is_open() == fail"<<std::endl;  
        return false;
    }

    transactions.clear();
    Transaction transaction;

    while (inFile.read(reinterpret_cast<char*>(&transaction), sizeof(Transaction))) {
        transactions.push_back(transaction);
    }

    inFile.close();
    return true;
}

} // namespace Bank
