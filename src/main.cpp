#include "atm.h"
#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief Validates if a string is a 6-digit PIN
 * @param pin The PIN to validate
 * @return true if the PIN is valid
 */
bool isValidPin(const std::string& pin) {
    return pin.length() == 6 && 
           std::all_of(pin.begin(), pin.end(), [](char c) { return std::isdigit(c); });
}

/**
 * @brief Validates if a string can be converted to a valid balance
 * @param balanceStr The balance string to validate
 * @return true if the balance is valid
 */
bool isValidBalance(const std::string& balanceStr) {
    try {
        size_t pos;
        double balance = std::stod(balanceStr, &pos);
        return pos == balanceStr.length() && balance >= 0;
    } catch (const std::exception&) {
        return false;
    }
}

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <6-digit PIN> <initial balance>" << std::endl;
        return 1;
    }
    
    std::string pin = argv[1];
    std::string balanceStr = argv[2];
    
    // Validate PIN
    if (!isValidPin(pin)) {
        std::cerr << "Error: PIN must be a 6-digit number" << std::endl;
        return 1;
    }
    
    // Validate initial balance
    if (!isValidBalance(balanceStr)) {
        std::cerr << "Error: Initial balance must be a non-negative number" << std::endl;
        return 1;
    }
    
    double initialBalance = std::stod(balanceStr);
    
    // Create and run the ATM
    ATM atm(pin, initialBalance);
    atm.run();
    
    return 0;
}