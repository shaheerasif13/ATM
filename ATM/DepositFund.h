// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Deposit fund class definition (DepositFund.h)

#pragma once

#include "Transaction.h"
#include <cstdlib>
#include <Windows.h>

class DepositFund : public Transaction {

public:
    DepositFund(Account&);  // Parameterized constructor

    virtual bool performTransaction() override; // Overriding base class function
};