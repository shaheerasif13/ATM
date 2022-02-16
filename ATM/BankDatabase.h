// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Bank database class definition (BankDatabase.h)

#pragma once

#include "Account.h"
#include <iostream>
#include <fstream>

class BankDatabase {

public:
    bool verifyUser(int, int);  // Verify user entered information through back database
    Account getCurrentAccountInfo(int, int);  // Get current user's account information
    void updateDatabase(Account&);  // Update current user's account information after successful transaction
    void saveTransactionDetails(Account&, int); // Save transaction details for ATM users
};