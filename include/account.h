#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

/**
 * @brief Represents a bank account with basic operations
 */
class Account {
private:
    double balance;
    const double overdraftLimit = 500.0;

public:
    /**
     * @brief Construct a new Account object with initial balance
     * @param initialBalance The initial account balance in euros
     */
    explicit Account(double initialBalance);

    /**
     * @brief Get the current account balance
     * @return double The current balance
     */
    double getBalance() const;

    /**
     * @brief Deposit money into the account
     * @param amount The amount to deposit
     * @return true if the deposit was successful
     */
    bool deposit(double amount);

    /**
     * @brief Withdraw money from the account
     * @param amount The amount to withdraw
     * @return true if the withdrawal was successful
     */
    bool withdraw(double amount);

    /**
     * @brief Check if a withdrawal is possible
     * @param amount The amount to check
     * @return true if the withdrawal is within limits
     */
    bool canWithdraw(double amount) const;
};

#endif // ACCOUNT_H