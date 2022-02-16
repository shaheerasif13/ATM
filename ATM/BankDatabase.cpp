// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Bank database class member funcions definition (BankDatabase.cpp)

#include "BankDatabase.h"

bool BankDatabase::verifyUser(int input_account, int input_pin) {
    fstream ifile;  // File reading object
    string s;
    float n;
    int x = 0;
    bool valid_account = false;
    bool valid_pin = false;

    ifile.open("Accounts.txt", ios::in);    // Opening file containing accounts information

    if (ifile) {    // If file opens successfully

        while (ifile >> s >> n) {

            if (x == 0) {   // If reading first line (Account number)

                if (n == (float)input_account) {
                    valid_account = true;
                }

                else {
                    valid_account = false;
                }

                x = x + 1;
            }

            else if (x == 1) {   // If reading second line (Pin)

                if (n == (float)input_pin) {
                    valid_pin = true;
                }

                else {
                    valid_pin = false;
                }

                x = x + 1;
            }

            else if (x == 2) {       // Ignoring balance (Not required here)

                if (valid_account && valid_pin) {   // If consecutive account number and pin are of same account
                    break;
                }

                ifile.ignore();
                x = 0;
                continue;
            }
        }
    }

    else {
        cout << "Bank database not found." << endl;
    }

    ifile.close();  // Closing file

    if (valid_account && valid_pin) {   // If entered account number and pin are valid
        return true;
    }

    else {  // If entered account number and pin are invalid
        return false;
    }
}

Account BankDatabase::getCurrentAccountInfo(int input_account, int input_pin) {
    Account temp_account;  // Temporary account object to return account information to account object of ATM class
    fstream ifile;  // File reading object
    string s;
    float n;
    int x = 0;
    bool valid_account = false;
    bool valid_pin = false;

    ifile.open("Accounts.txt", ios::in);    // Opening file containing accounts information

    if (ifile) {    // If file opens successfully

        while (ifile >> s >> n) {

            if (x == 0) {   // If reading first line (Account number)

                if (n == (float)input_account) {
                    valid_account = true;
                    temp_account.setAccountNumber(n);
                }

                x = x + 1;
            }

            else if (x == 1) {   // If reading second line (Pin)

                if (n == (float)input_pin) {
                    valid_pin = true;
                    temp_account.setCardPin(n);
                }

                x = x + 1;
            }

            else if (x == 2) {       // Ignoring balance (Not required here)

                if (valid_account && valid_pin) {   // If given account number and pin matches save account balance of current account
                    temp_account.setAccountBalance(n);

                    break;
                }

                x = 0;
            }
        }
    }

    else {
        cout << "Bank database not found." << endl;
    }

    ifile.close();  // Closing file

    return temp_account;
}

void BankDatabase::updateDatabase(Account& c_account) {
    fstream ifile;  // File reading object
    fstream ofile;  // File writing object
    string s;
    float n;
    int x = 0;
    bool valid_account = false;
    bool valid_pin = false;

    /* Current file will be copied to new file with updated account
    information of current transaction performing account */

    ifile.open("Accounts.txt", ios::in);    // Opening database file
    ofile.open("newfile.txt", ios::out);    // Creating a new file

    while (ifile >> s >> n) {   // Reading from current file

        if (x == 0) {

            ofile << s << " " << n << endl; // Writing to new file

            if (n == c_account.getAccountNumber()) {
                valid_account = true;
            }

            x = x + 1;
        }

        else if (x == 1) {

            ofile << s << " " << n << endl; // Writing to new file

            if (n == c_account.getCardPin()) {
                valid_pin = true;
            }

            x = x + 1;
        }

        else if (x == 2) {

            if (valid_account && valid_pin) {
                ofile << s << " " << c_account.getAccountBalance() << "\n\n";   // Writing to new file
                valid_account = false;
                valid_pin = false;
            }

            else {
                ofile << s << " " << n << "\n\n";   // Writing to new file
            }

            x = 0;  // Reset for reading next account information
        }
    }

    ifile.close();  // Closing files
    ofile.close();

    remove("Accounts.txt");
    rename("newfile.txt", "Accounts.txt");  // Renaming new file same as current file (Replacing current file)
}

void BankDatabase::saveTransactionDetails(Account& account, int t_flag) {
    fstream ofile;  // File writing object

    ofile.open("Details.txt", ios::app);    // Opening file

    if (t_flag == 0) {  // If flag is 0, it means amount is withdrawn
        ofile << "Account number: " << account.getAccountNumber() << endl;
        ofile << "Transaction type: Withdrawal" << endl;
        ofile << "Balance before transaction: " << account.getPreviousBalance() << endl;
        ofile << "Balance after transaction: " << account.getAccountBalance() << endl << endl;
    }

    else {  // If flag is 0, it means amount is deposited
        ofile << "Account number: " << account.getAccountNumber() << endl;
        ofile << "Transaction type: Funds deposit" << endl;
        ofile << "Balance before transaction: " << account.getPreviousBalance() << endl;
        ofile << "Balance after transaction: " << account.getAccountBalance() << endl << endl;
    }

    ofile.close();  // Closing file
}