#include "player.h"
#include <iostream>

//TODO
void Player::addBet(const Bet& b)
{
    pair<unordered_set<Bet, betHash, betHash>::iterator,bool> res = bets.insert(b);
    if (res.second)
        cout << "Inserido com sucesso!!" << endl;
    else
        cout << "Não Inserido!!" << endl;
}

//TODO
unsigned Player::betsInNumber(unsigned num) const
{
    unsigned count = 0;
	for (const auto & bet : bets) {
	    tabHInt numbers = bet.getNumbers();
	    for(unsigned int number : numbers) {
	        if (number == num)
	            count++;
	    }
	}
	return count;
}

//TODO
tabHBet Player::drawnBets(const tabHInt& draw) const
{
	tabHBet res;
    for (const auto & bet : bets) {
        if (bet.countRights(draw) > 3)
            res.insert(bet);
    }
	return res;
}
