#ifndef FILE_PERSISTENCE_H
#define FILE_PERSISTENCE_H

#include <string>
#include <vector>
#include "UserAccount.h"
#include "Transaction.h"

namespace Bank {
    class FilePersistence {
    public:
        static bool saveUserAccounts(const std::vector<UserAccount>& accounts, const std::string& filename);
        static bool loadUserAccounts(std::vector<UserAccount>& accounts, const std::string& filename);

        static bool saveTransactions(const std::vector<Transaction>& transactions, const std::string& filename);
        static bool loadTransactions(std::vector<Transaction>& transactions, const std::string& filename);
    };
}

#endif // FILE_PERSISTENCE_H
