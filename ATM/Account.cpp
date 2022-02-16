// Muhammad Shaheer
// 19I-2152
// CS-F
// Project

// Account class member functions definition (Account.cpp)

#include "Account.h"

Account::Account() {
    account_number = 0;
    card_pin = 0;
    account_balance = 0;
    previous_balance = 0;
}

void Account::setAccountNumber(int a_number) {
    account_number = a_number;
}

void Account::setCardPin(int pin) {
    card_pin = pin;
}

void Account::setAccountBalance(float a_balance) {
    account_balance = a_balance;
}

void Account::setPreviousBalance(float p_balance) {
    previous_balance = p_balance;
}

int Account::getAccountNumber() {
    return account_number;
}

int Account::getCardPin() {
    return card_pin;
}

float Account::getAccountBalance() {
    return account_balance;
}

float Account::getPreviousBalance() {
    return previous_balance;
}

void Account::print() {
    cout << "Account number: " << account_number << endl;
    cout << "Account balance: " << account_balance << endl;
    cout << "Previous balance: " << previous_balance << endl;
}