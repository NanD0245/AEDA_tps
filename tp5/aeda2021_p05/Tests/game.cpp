#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase)
{
    if ( phrase.length() == 0 ) return 0;

    unsigned n=1;
    size_t pos = phrase.find(' ');
    while (pos != string::npos) {
        phrase = phrase.substr(pos+1);
        pos = phrase.find(' ');
        n++;
    }
    return n;
}

// TODO
Game::Game()
{
    kids.clear();
}

// TODO
Game::Game(list<Kid>& l2)
{
    kids = l2;
}

// TODO
void Game::addKid(const Kid &k1)
{
    kids.push_back(k1);
}

// TODO
list<Kid> Game::getKids() const
{
    list<Kid> res;
    res = kids;
    return res;
}

// TODO
string Game::write() const
{
    string res;
    res = "";
    for (auto & kid : kids) {
        res += kid.write() + "\n";
    }
    return res;
}

// TODO
Kid& Game::loseGame(string phrase) {
    list<Kid> kids_copy;
    kids_copy = kids;
    unsigned int numwords;
    Kid *k1 = new Kid();
    auto i = kids_copy.begin();
    while (kids_copy.size() > 1) {
        int j = 0;
        numwords = numberOfWords(phrase);
        while (numwords != 0) {
            numwords--;
            if (j == kids_copy.size() - 1 && numwords != 0) {
                i = kids_copy.begin();
                j = 0;
            } else if (numwords != 0) {
                i++;
                j++;
            }
        }
        auto k = i;
        k++;
        cout << i->getName() << endl;
        kids_copy.erase(i);
        if (j == kids_copy.size()) {
            i = kids_copy.begin();
        }
        else {
            i = k;
        }
        if (kids_copy.size() == 1)
            *k1 = *i;
    }
    return *k1;
}

// TODO
list<Kid>& Game::reverse()
{
    kids.reverse();
    return kids;
}

// TODO
list<Kid> Game::removeOlder(unsigned id)
{
    list<Kid> res;
    for (auto & kid : kids) {
        if (kid.getAge() > id)
            res.push_back(kid);
    }
    return res;
}

// TODO
void Game::setKids(const list<Kid>& l1)
{
    kids = l1;
}

// TODO
bool Game::operator==(Game& g2)
{
    list<Kid> l1 = g2.getKids();
    if (l1.size() == kids.size()) {
        auto p = l1.begin();
        for (auto i = kids.begin(); i != kids.end(); i++) {
            if (i->getName() != p->getName() || i->getAge() != p->getAge())
                return false;
            p++;
        }
        return true;
    }
    return false;
}

// TODO
list<Kid> Game::shuffle() const {
    list<Kid> res, kids_copy;
    kids_copy = kids;
    while (!kids_copy.empty()) {
        int random, size = kids_copy.size();
        random = rand() % size;
        auto i = kids_copy.begin();
        while (random > 0) {
            i++;
            random--;
        }
        res.push_back(*i);
        kids_copy.erase(i);
    }
    return res;
}
