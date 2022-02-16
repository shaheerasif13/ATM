// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Cash dispenser class member functions definition (CashDispenser.cpp)

#include "CashDispenser.h"

CashDispenser::CashDispenser() : NOTE_OF(20) {
    this->notes = this->INITIAL_NOTES;  // Initializing number of notes
}

void CashDispenser::dispenseCash(int amount) {
    int notes_required; // Given amount in notes

    notes_required = amount / this->NOTE_OF;    // Converting given amount to notes
    this->notes = this->notes - notes_required; // Subtracting required notes from total notes
}

bool CashDispenser::isCashAvaliable(int amount) {
    int notes_required; // Given amount in notes

    notes_required = amount / this->NOTE_OF;    // Converting given amount to notes

    if (this->notes >= notes_required) {    // If there are enough notes
        return true;
    }

    else {  // If there are not enough notes
        return false;
    }
}