/*
 * Account.cpp
 */
#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(string hold, string codeH, string codeA, double bal): holder(hold), codeHolder(codeH), codeIBAN(codeA), balance(bal) {}

Account::~Account(){ }

string Account::getCodH() const {
	return codeHolder;
}

string Account::getCodIBAN() const {
	return codeIBAN;
}

double Account::getBalance() const {
	return balance;
}

SavingsAccount::SavingsAccount (string hold, string codeH, string codeA, double bal, double pct):
		Account(hold, codeH, codeA, bal), rate(pct/100)
{ }

double SavingsAccount::getCharge() const {
    return rate * 100 > 2 ? 0.8 : 0;
}

double SavingsAccount::getWithdraw() const {
    return balance;
}

CheckingAccount::CheckingAccount(string hold, string codeH, string codeA, double bal,double lim):
			Account(hold, codeH, codeA, bal) {
	limit = lim;
}

double CheckingAccount::getCharge() const {
    if (limit <= 500)
        return 0.50;
    else if (limit <= 1000)
        return 0.25;
    else return 0;
}

double CheckingAccount::getWithdraw() const {
    return balance;
}

TimeAccount::TimeAccount(string hold, string codeH, string codeA, double bal, double pct):
			SavingsAccount(hold, codeH, codeA, bal, pct) {
	funds_avail = balance*rate;
}

double TimeAccount::getCharge() const {
    return rate * 100 > 2 ? 0.8 : 0;
}

double TimeAccount::getWithdraw() const {
    return funds_avail;
}




