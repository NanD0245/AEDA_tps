#include "bet.h"
#include <iostream>
#include <sstream>
using namespace std;


bool Bet::contains(unsigned num) const
{
	return numbers.find(num) != numbers.end();
}

void Bet::generateBet(const vector<unsigned>& values, unsigned n)
{
    for (size_t i = 0; numbers.size() < n; i++)
        numbers.insert(values[i]);
}

unsigned Bet::countRights(const tabHInt& draw) const
{
    unsigned count = 0;
    for (unsigned result: draw)
        for (unsigned number: numbers)
            if (number == result)
                count++;
	return count;
}
