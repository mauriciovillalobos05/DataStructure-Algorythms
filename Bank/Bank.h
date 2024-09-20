#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>

class Bank {
    private:
        struct BankAccount {
            std::string accountNumber;
            double balance;
        };
        std::vector<BankAccount> accounts;

    public:
        void addAccount(std::string accountNumber, double initialBalance);
        double getAccount(std::string accountNumber);
        int findAccountIndex(std::string accountNumber);
        void addBalance(std::string accountNumber, double newBalance);
        void substractBalance(std::string accountNumber, double newBalance);
};

#endif // BANK_H
