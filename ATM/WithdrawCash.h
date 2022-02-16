// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Withdraw cash class definition (WithdrawCash.h)

#pragma once

#include "Transaction.h"
#include "CashDispenser.h"
#include <cstdlib>
#include <Windows.h>

class WithdrawCash : public Transaction {

private:
    CashDispenser& disp;

public:
    WithdrawCash(Account&, CashDispenser&); // Parameterized constructor

    int displayWithdrawalOptions(); // To display cash withdrawal options (Returns user choice)
    virtual bool performTransaction() override; // Function from base class transaction
};