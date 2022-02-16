// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// ATM class member functions definition (ATM.cpp)

#include "ATM.h"

ATM::ATM() {
    logged_in = false;
    transaction_canceled = false;
    user_exited = false;
}

void ATM::start() {

    do {
        user_exited = false;
        logged_in = false;
        welcomeScreen();

        do {
            transaction_canceled = false;
            mainMenu();
        }

        while (transaction_canceled);   // If user cancelled ongoing transaction take user back to main menu

        system("CLS");

        cout << "Thank you!";   // Displaying message after user exits from main menu
        cout.flush();
        Sleep(2);
    }

    while (user_exited);    // If user exits take user back to welcome screen*/
}

void ATM::mainMenu() {
    int choice = -1;

    // Displaying main menu options to user

    while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        system("CLS");

        cout << "Main Menu:\n\n";
        cout << "\t1 - View my balance" << endl;
        cout << "\t2 - Withdraw cash" << endl;
        cout << "\t3 - Deposit funds" << endl;
        cout << "\t4 - Exit" << endl;
        cout << "\nEnter a choice: ";
        cin >> choice;

        if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
            cout << "\nInvalid choice. Try again!";
            cout.flush();
            Sleep(1);
        }
    }

    startTransaction(choice);   // Start transaction process after taking user's choice from main menu
}

void ATM::startTransaction(int user_choice) {
    Transaction* ongoing_transaction;

    switch (user_choice) {

    case(1):

    {
        int n = -1;

        while (n != 0) {
            system("CLS");

            // Displaying user's account balance

            cout << "Your account balance: " << current_account.getAccountBalance() << "$" << endl;
            cout << "\nPress 0 to continue to main menu. ";
            cin >> n;

            if (n != 0) {   // If user enters number other than 0
                cout << "\nInvalid input. Try again!";
                cout.flush();
                Sleep(1);
            }
        }

        transaction_canceled = true;    // For going back to main menu
    }

    break;

    case(2):    // If user chooses to withdraw cash

    {
        Transaction* ongoing_transaction = new WithdrawCash(current_account, dispenser);
        int success = ongoing_transaction->performTransaction();    // Performing transaction
        delete ongoing_transaction;
        ongoing_transaction = nullptr;
        transaction_canceled = true;    // For going back to main menu

        if (success) {
            database->updateDatabase(current_account);  // Updating database information if transaction successfull
            database->saveTransactionDetails(current_account, 0);   // Saving transaction details of current transaction

            cout << "\nWithdrawal successfully completed!" << endl; // Showing message to user to collect cash
            cout << "Collect cash!";
            cout.flush();
            Sleep(3);
        }
    }

    break;

    case(3):

    {
        Transaction* ongoing_transaction = new DepositFund(current_account);
        int success = ongoing_transaction->performTransaction();    // Performing transaction
        delete ongoing_transaction;
        ongoing_transaction = nullptr;
        transaction_canceled = true;    // For going back to main menu

        if (success) {
            database->updateDatabase(current_account);  // Updating database information if transaction successfull
            database->saveTransactionDetails(current_account, 1);   // Saving transaction details of current transaction

            cout << "\nAmount deposited successfully!"; // Displaying message after successful transaction
            cout.flush();
            Sleep(3);
        }
    }

    break;

    case(4):    // If user exits

    {
        user_exited = true;
        transaction_canceled = false;
    }

    break;
    }
}

void ATM::welcomeScreen() {

    while (!logged_in) {    // Try taking input if user enters invalid information
        system("CLS");

        cout << "Welcome!" << endl;

        userLogin();    // Logging in user by taking account number and pin and verifying through database
    }
}

void ATM::userLogin() {
    int input_account;
    int input_pin;

    cout << "\nPlease enter your account number: ";   // Taking account number as input
    cin >> input_account;

    cout << "\nEnter your pin: "; // Taking ATM pin as input
    cin >> input_pin;

    logged_in = database->verifyUser(input_account, input_pin); // Verifying entered information through back database

    if (!logged_in) {   // If entered information is invalid
        cout << "\nInvalid account number or pin. Try again!";
        cout.flush();
        Sleep(1);
    }

    else {  // If entered information is valid
        current_account = database->getCurrentAccountInfo(input_account, input_pin);    // Get current user's account information if logged in
    }
}