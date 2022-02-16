// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Cash dispenser class definition (CashDispenser.h)

#pragma once

#include <iostream>
using namespace std;

class CashDispenser {

private:
    int notes;  // Count of 20$ notes
    const static int INITIAL_NOTES = 500;   // Initial count of 20$ notes
    const int NOTE_OF;  // Note is of which amount (20$, 50$ etc)

public:
    CashDispenser();    // Default constructor

    void dispenseCash(int); // Dispenses cash
    bool isCashAvaliable(int);  // Returns true if cash is avaliable
};