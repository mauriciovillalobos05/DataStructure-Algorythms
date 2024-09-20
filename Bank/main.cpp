#include "Bank.h"
#include <iostream>

int main() {
    Bank bank;
    bank.addAccount("aaa12", 1000);
    std::cout << "El balance de la cuenta aaa12 es: " << bank.getAccount("aaa12") << std::endl;
    bank.addBalance("aaa12", 500);
    bank.substractBalance("aaa12", 250);
}
