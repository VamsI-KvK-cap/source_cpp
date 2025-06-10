#include "account.h"
#include <iostream>

Account::Account(double initialBalance) : balance(initialBalance) {
}

double Account::getBalance() const {
    return balance;
}

bool Account::deposit(double amount) {
    if (amount <= 0) {
        return false;
    }
    
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (!canWithdraw(amount)) {
        return false;
    }
    
    balance -= amount;
    return true;
}

bool Account::canWithdraw(double amount) const {
    if (amount <= 0) {
        return false;
    }
    
    // Check if withdrawal would exceed overdraft limit
    return (balance - amount >= -overdraftLimit);
}