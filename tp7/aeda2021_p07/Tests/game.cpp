#include "game.h"
#include <sstream>


ostream &operator << (ostream &os, Circle &c1)
{
	return os;
}


Game::Game(int h, vector<int> &points, vector<bool> &states)
{
    game = *initGame(0,h,points,states);
}


BinaryTree<Circle>* Game::initGame(int pos, int niv, vector<int> points, vector<bool> states) {
    Circle* c1 = new Circle(points[pos],states[pos]);
    if (niv == 0) {
        return new BinaryTree<Circle>(*c1);
    }
    return new BinaryTree<Circle>(*c1,*initGame(2*pos+1,niv-1,points,states),*initGame(2*pos+2,niv-1,points,states));
}


string Game::writeGame()
{
    string s_game,s_bool;
	for (auto it = BTItrLevel<Circle>(game); !it.isAtEnd(); it.advance()) {
	    s_bool = it.retrieve().getState() ? "true": "false";
        s_game += to_string(it.retrieve().getPoints()) + "-" + s_bool + "-" + to_string(it.retrieve().getNVisits()) + "\n";
	}
	return s_game;
}


int Game::move()
{
    int pos = 0, next_pos = 0, points;
    auto it = BTItrLevel<Circle>(game);
    while (true) {
        points = it.retrieve().getPoints();
        if (it.retrieve().getState()) next_pos = 2*pos+2;
        else next_pos = 2*pos+1;
        it.retrieve().changeState();
        while (pos < next_pos && !it.isAtEnd()) {
            it.advance();
            pos++;
        }
        if (it.isAtEnd())
            return points;
        it.retrieve().addVisit();
    }
}


int Game::mostVisited()
{
    int most_visited = 0;
	for (auto it = BTItrLevel<Circle>(game); !it.isAtEnd(); it.advance()) {
	    if (it.retrieve().getNVisits() > most_visited)
	        most_visited = it.retrieve().getNVisits();
	}
	return most_visited;
}
