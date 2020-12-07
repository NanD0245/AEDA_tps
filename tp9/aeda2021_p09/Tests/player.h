#ifndef PLAYER_H_
#define PLAYER_H_

#include "bet.h"
#include <string>
#include <iostream>
using namespace std;

//TODO
struct betHash
{
	int operator() (const Bet& b) const
	{
	    unsigned v = 0;
	    tabHInt numbers = b.getNumbers();
	    for (unsigned int number : numbers) {
	        v = 37*v + number;
	    }
	    cout << v << endl;
		return (int)v;
	}
	
	bool operator() (const Bet& b1, const Bet& b2) const
	{
		return b1.getNumbers() == b2.getNumbers();
	}
};


typedef unordered_set<Bet, betHash, betHash> tabHBet;

class Player
{
	tabHBet bets;
	string name;
public:
	Player(string nm="anonymous") { name=nm; }
    unsigned getNumBets() const { return bets.size(); }
	void addBet(const Bet & ap);
	unsigned betsInNumber(unsigned num) const;
	tabHBet drawnBets(const tabHInt& draw) const;
	Bet getBet(int hash) {
        auto it = bets.begin();
	    for (int i = 0; i < hash; i++) {
	        it++;
	    }
	    return *it;
	}
};

#endif 
