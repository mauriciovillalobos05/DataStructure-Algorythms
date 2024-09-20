#include "Bank.h"
#include <iostream>

void Bank::addAccount(std::string accountNumber, double initialBalance) {
    accounts.push_back({accountNumber, initialBalance});
}

int Bank::findAccountIndex(std::string accountNumber) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

double Bank::getAccount(std::string accountNumber) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        return accounts[index].balance;
    }
    return -1;
}

void Bank::addBalance(std::string accountNumber, double newBalance) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        accounts[index].balance += newBalance;
        std::cout << "La cuenta " << accountNumber << " tiene un nuevo balance de " << accounts[index].balance << std::endl;
    } else {
        std::cout << "La cuenta no existe" << std::endl;
    }
}

void Bank::substractBalance(std::string accountNumber, double newBalance) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        accounts[index].balance -= newBalance;
        std::cout << "La cuenta " << accountNumber << " tiene un nuevo balance de " << accounts[index].balance << std::endl;
    } else {
        std::cout << "La cuenta no existe" << std::endl;
    }
}