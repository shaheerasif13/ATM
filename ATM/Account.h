// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Account class definition (Account.h)

#pragma once

#include <iostream>
using namespace std;

class Account {

private:
    int account_number; // For keeping current user's account number
    int card_pin;   // For keeping current user's atm pin
    float account_balance;    // For keeping user's account balance
    float previous_balance;   // For keeping user's account balance before transaction

public:
    Account();  // Default constructor

    void setAccountNumber(int);  // Setter functions for data members
    void setCardPin(int);
    void setAccountBalance(float);
    void setPreviousBalance(float);

    int getAccountNumber();    // Getter functions for data members
    int getCardPin();
    float getAccountBalance();
    float getPreviousBalance();

    void print();   // Prints current account information
};