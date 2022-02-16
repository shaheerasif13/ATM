// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Deposit fund class member function definitions (DepositFund.cpp)

#include "DepositFund.h"

DepositFund::DepositFund(Account& a) : Transaction(a) {}

bool DepositFund::performTransaction() {
    float amount;
    int n = -1;

    system("CLS");

    cout << "Enter deposit amount in cents (0 to cancel): ";
    cin >> amount;

    if (amount == 0) {
        return false;
    }

    amount = amount / 100;  // Converting cents to dollars

    user_account.setPreviousBalance(user_account.getAccountBalance());  // Setting current balance as previous balance
    user_account.setAccountBalance(user_account.getPreviousBalance() + amount); // Updating user's current account balance

    cout << "\nVerifying ..." << endl;
    cout.flush();
    Sleep(2);

    return true;
}