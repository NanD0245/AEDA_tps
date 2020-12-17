/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"


BankOfficer::BankOfficer(): id(0) {}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}


// ----------------------------------------------------------------------------------------------

// a alterar

unsigned int BankOfficer::count = 1;

BankOfficer::BankOfficer(string name) : name(name), id(count) {
    myAccounts.clear();
    count++;
}

bool BankOfficer::operator>(BankOfficer b1) {
    if (myAccounts.size() > b1.getAccounts().size())
        return true;
    else if (myAccounts.size() < b1.getAccounts().size())
        return false;
    else if (name > b1.getName())
        return true;
    else return false;
}



