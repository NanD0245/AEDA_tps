/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const{
    double funds = 0;
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getCodH() == cod1)
            funds += accounts[i]->getWithdraw();
    }
	return funds;
}


// a alterar

vector<Account *> Bank::removeBankOfficer(string name){
	vector<Account *> res;
	bool check = false;
	int index;
	for (size_t i = 0; i < bankOfficers.size();i++) {
        if (bankOfficers[i].getName() == name) {
            res = bankOfficers[i].getAccounts();
            bankOfficers.erase(bankOfficers.begin() + i);
            break;
        }
	}
	return res;
}


// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    BankOfficer *bo= new BankOfficer();
    bool check = false;
    for (size_t i = 0; i < bankOfficers.size(); i++) {
        if (name == bankOfficers[i].getName()) {
            *bo = bankOfficers[i];
            bo->addAccount(ac);
            check = true;
        }
    }
    if (!check)
        throw NoBankOfficerException(name);
    return *bo;
}


// a alterar
void Bank::sortAccounts() {
    /*vector<Account *> v1;

    while (!accounts.empty()) {
        int min_index = 0;
        for (size_t i = 0; i < accounts.size(); i++) {
            if (accounts[i]->getBalance() < accounts[min_index]->getBalance()) {
                min_index = i;
            }
            else if (accounts[i]->getBalance() == accounts[min_index]->getBalance() && accounts[i]->getCodIBAN() < accounts[min_index]->getCodIBAN())
                min_index = i;
        }
        v1.push_back(accounts[min_index]);
        accounts.erase(accounts.begin()+ min_index);
    }
    accounts = v1;*/
    sort(accounts.begin(),accounts.end(),[](Account *a1, Account  *a2) {
        if (a1->getBalance() < a2->getBalance())
            return true;
        else if (a1->getBalance() == a2->getBalance() && a1->getCodIBAN() < a2->getCodIBAN())
            return true;
        return false;
    });
}

