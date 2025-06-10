#ifndef ATM_H
#define ATM_H

#include "account.h"
#include <string>

/**
 * @brief Simulates an ATM machine for ACME Bank
 */
class ATM {
private:
    Account account;
    std::string pin;
    const int maxPinAttempts = 3;

public:
    /**
     * @brief Construct a new ATM object
     * @param pin The 6-digit PIN for authentication
     * @param initialBalance The initial account balance
     */
    ATM(const std::string& pin, double initialBalance);

    /**
     * @brief Run the ATM interface
     */
    void run();

private:
    /**
     * @brief Authenticate the user with PIN
     * @return true if authentication is successful
     */
    bool authenticate();

    /**
     * @brief Display the main menu and handle commands
     */
    void showMenu();

    /**
     * @brief Process a command entered by the user
     * @param command The command number
     * @return true if the session should continue, false to exit
     */
    bool processCommand(int command);

    /**
     * @brief Handle the balance inquiry command
     */
    void checkBalance();

    /**
     * @brief Handle the deposit command
     */
    void handleDeposit();

    /**
     * @brief Handle the withdrawal command
     */
    void handleWithdrawal();

    /**
     * @brief Validate if a string contains only digits
     * @param str The string to validate
     * @return true if the string contains only digits
     */
    bool isNumeric(const std::string& str) const;
};

#endif // ATM_H