#include "maze.h"
#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>

using namespace std;

DisjointSets Maze::getSets() const {
    return maze;
}

void Maze::printMaze() const
{
    cout << setw(3) << " ";
    for (int j=0; j<ncols; j++) {
        cout << setw(6) << "______";
    }
    for (int i=0; i<nrows; i++) {
        cout << endl;
        cout << setw(3) << "|";
        for (int j=0; j<ncols-1; j++) {
            int val = i*nrows+j;
            cout << setw(3) << val<<setw(3);
            if (noWalls.empty() ||
                (find(noWalls.begin(),noWalls.end(),pair<int,int>(val,val+1)) == noWalls.end() &&
                 find(noWalls.begin(),noWalls.end(),pair<int,int>(val+1,val)) == noWalls.end())
                    )
                cout << "|";
            else
                cout <<" ";
        }
        int val = i*nrows+ncols-1;
        cout << setw(3) << val<<setw(3) << "|";
        cout <<endl;
        cout << setw(3) << " ";
        for (int j=0; j<ncols; j++) {
            int val = i*nrows+j;
            if (i<nrows-1) {
                if ( noWalls.empty() ||
                     (find(noWalls.begin(), noWalls.end(), pair<int, int>(val, val + ncols)) == noWalls.end()
                      && find(noWalls.begin(), noWalls.end(), pair<int, int>(val+ncols, val)) == noWalls.end())
                        )
                    cout << setw(6) << "______";
                else
                    cout << setw(6) << " ";
            } else
                cout << setw(6) << "______";
        }

    }
    cout <<endl << endl;
}

Maze::Maze(int rows, int cols) : nrows(rows), ncols(cols){
    noWalls.clear();
    DisjointSets temp(rows*cols);
    maze = temp;
}

vector<int> Maze::getNeighbours(int x) const {
    vector<int> res;
    int col = x % nrows,row = 0,x_copy = x;
    while (x_copy > ncols) {
        x_copy -= ncols;
        row++;
    }
    if (col + 1 != ncols) res.push_back(x+1);
    if (col != 0) res.push_back(x-1);
    if (row + 1 != nrows) res.push_back(x+ncols);
    if (row != 0) res.push_back(x-ncols);
    return res;
}

void Maze::buildRandomMaze() {
    vector<int> neighbours;
    int size = ncols*nrows;
    srand(time(NULL));
    while (maze.getNumberOfSets() != 1) {
        int x = rand() % size;
        neighbours = getNeighbours(x);
        int y = neighbours[rand() % neighbours.size()];
        if (maze.find(x) != maze.find(y)) {
            noWalls.emplace_back(x, y);
            x = maze.find(x);
            y = maze.find(y);
            maze.unionSets(x, y);
        }
    }
}

