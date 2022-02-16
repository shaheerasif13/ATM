// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Withdraw cash class member functions definition (WithdrawCash.cpp)

#include "WithdrawCash.h"

WithdrawCash::WithdrawCash(Account& a, CashDispenser& c) : Transaction(a), disp(c) {}

bool WithdrawCash::performTransaction() {
    int user_selection;
    int amount = 0;

    do {
        amount = 0;
        user_selection = displayWithdrawalOptions();    // Displaying withdrawal options and taking user choice

        // Setting amount based on user selection

        if (user_selection == 1) {
            amount = 20;
        }

        else if (user_selection == 2) {
            amount = 40;
        }

        else if (user_selection == 3) {
            amount = 60;
        }

        else if (user_selection == 4) {
            amount = 100;
        }

        else if (user_selection == 5) {
            amount = 200;
        }

        else if (user_selection == 6) {
            return false;   // Return to main menu if user cancels transaction
        }

        if (amount > user_account.getAccountBalance()) {    // If user enters amount more than account balance
            cout << "\nNot enough balance!" << endl;
            cout << "Please select a smaller amount!" << endl;
            cout.flush();
            Sleep(1);
        }

        else if (!(disp.isCashAvaliable(amount))) { // If cash dispenser does not have enough cash
            cout << "\nSelection can't be completed!" << endl;
            cout << "Please select another amount!" << endl;
            cout.flush();
            Sleep(1);
        }
    }

    // Continue taking input if user enters amount greater than account balance or if cash dispenser does not have enough cash

    while (amount > user_account.getAccountBalance() || !(disp.isCashAvaliable(amount)));

    disp.dispenseCash(amount);  // Selected amount being taken from cash dispenser
    user_account.setPreviousBalance(user_account.getAccountBalance());  // Setting previous balance as current balance
    user_account.setAccountBalance(user_account.getPreviousBalance() - amount); // Updating user current account balance

    return true;
}

int WithdrawCash::displayWithdrawalOptions() {
    int choice = -1;

    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) {
        system("CLS");

        cout << "Withdrawal options:\n\n";
        cout << "\t1 - $20\t\t4 - $100" << endl;
        cout << "\t2 - $40\t\t5 - $200" << endl;
        cout << "\t3 - $60\t\t6 - Cancel transaction" << endl;
        cout << "\nChoose a withdrawal option (1 - 6): ";
        cin >> choice;

        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) {
            cout << "\nInvalid option. Try again!";
            cout.flush();
            Sleep(1);
        }
    }

    return choice;
}