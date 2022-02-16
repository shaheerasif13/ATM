// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Transaction class definition (Transaction.h)

#pragma once

#include "Account.h"

class Transaction {

protected:
    Account& user_account;

public:
    Transaction(Account&);  // Parameterized constructor

    virtual bool performTransaction() = 0;  // Pure virtual function which performs transaction in derived classes
};