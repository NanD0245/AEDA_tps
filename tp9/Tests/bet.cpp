#include "bet.h"
#include <iostream>
#include <sstream>
using namespace std;


bool Bet::contains(unsigned num) const {return !(numbers.find(num)==numbers.end());}

void Bet::generateBet(const vector<unsigned>& values, unsigned n)
{
    for (unsigned int value : values) {
        if (n == 0) return;
        if (numbers.find(value) == numbers.end()) {
            numbers.insert(value);
            n--;
        }
    }
}

unsigned Bet::countRights(const tabHInt& draw) const
{
    unsigned count = 0;
    for (unsigned int number : numbers)
        if (draw.find(number) != draw.end()) count++;
	return count;
}
