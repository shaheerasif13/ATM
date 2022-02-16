// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// ATM class definition (ATM.h)

#pragma once

#include "CashDispenser.h"
#include "BankDatabase.h"
#include "Account.h"
#include "Transaction.h"
#include "WithdrawCash.h"
#include "DepositFund.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>

class ATM {

private:
    bool logged_in; // True if user is logged in
    bool transaction_canceled;  // True if user cancelled ongoing transaction from amounts menu
    bool user_exited;   // True if user exits from main menu
    CashDispenser dispenser;    // Cash dispenser object (Cash dispenser is part of ATM)
    BankDatabase* database; // Pointer of bank's database (ATM uses bank's database)
    Account current_account;    // For saving current user's account information

    void welcomeScreen();   // Displays and processes welcome screen
    void mainMenu();    // Displays and processes main menu screen
    void userLogin();   // Log in user by verifying user entered information with database
    void startTransaction(int); // Start transaction process by taking user choice as parameter

public:
    ATM();  // Default constructor

    void start();   // Starts the ATM
};