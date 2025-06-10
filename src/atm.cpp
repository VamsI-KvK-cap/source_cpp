#include "atm.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <sstream>
#include <iomanip>

std::string formatCurrency(double amount) {
    std::ostringstream oss;
    oss << "EUR " << std::fixed << std::setprecision(2) << amount;
    return oss.str();
}

ATM::ATM(const std::string& pin, double initialBalance) 
    : account(initialBalance), pin(pin) {
}

void ATM::run() {
    std::cout << "Welcome to ACME Bank ATM" << std::endl;
    
    if (!authenticate()) {
        std::cout << "Goodbye. Your card has been retained for security reasons." << std::endl;
        return;
    }
    
    showMenu();
}

bool ATM::authenticate() {
    std::string enteredPin;
    int attempts = 0;
    
    while (attempts < maxPinAttempts) {
        std::cout << "Please enter your 6-digit PIN: ";
        std::cin >> enteredPin;
        
        if (enteredPin == pin) {
            std::cout << "PIN accepted. Welcome to your account." << std::endl;
            return true;
        }
        
        attempts++;
        std::cout << "Incorrect PIN. " << (maxPinAttempts - attempts) << " attempts remaining." << std::endl;
    }
    
    return false;
}

void ATM::showMenu() {
    bool continueSession = true;
    
    while (continueSession) {
        std::cout << "\n=== ACME Bank ATM Menu ===" << std::endl;
        std::cout << "1. Check Balance" << std::endl;
        std::cout << "2. Deposit Money" << std::endl;
        std::cout << "3. Withdraw Money" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice (1-4): ";
        
        int choice;
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            continue;
        }
        
        continueSession = processCommand(choice);
    }
    
    std::cout << "Thank you for using ACME Bank ATM. Goodbye!" << std::endl;
}

bool ATM::processCommand(int command) {
    switch (command) {
        case 1:
            checkBalance();
            return true;
        case 2:
            handleDeposit();
            return true;
        case 3:
            handleWithdrawal();
            return true;
        case 4:
            return false;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            return true;
    }
}

void ATM::checkBalance() {
    std::cout << "Your current balance is: " << formatCurrency(account.getBalance()) << std::endl;
}

void ATM::handleDeposit() {
    std::cout << "Enter amount to deposit (EUR): ";
    double amount;
    std::cin >> amount;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid amount. Deposit cancelled." << std::endl;
        return;
    }
    
    if (account.deposit(amount)) {
        std::cout << "Successfully deposited " << formatCurrency(amount) << std::endl;
        std::cout << "New balance: " << formatCurrency(account.getBalance()) << std::endl;
    } else {
        std::cout << "Deposit failed. Please enter a positive amount." << std::endl;
    }
}

void ATM::handleWithdrawal() {
    std::cout << "Enter amount to withdraw (EUR): ";
    double amount;
    std::cin >> amount;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid amount. Withdrawal cancelled." << std::endl;
        return;
    }
    
    if (account.withdraw(amount)) {
        std::cout << "Please take your cash: " << formatCurrency(amount) << std::endl;
        std::cout << "New balance: " << formatCurrency(account.getBalance()) << std::endl;
    } else {
        std::cout << "Withdrawal failed. The amount exceeds your available balance plus overdraft limit (EUR 500)." << std::endl;
        std::cout << "Your current balance is: " << formatCurrency(account.getBalance()) << std::endl;
    }
}

bool ATM::isNumeric(const std::string& str) const {
    return !str.empty() && 
           std::all_of(str.begin(), str.end(), [](char c) { return std::isdigit(c); });
}