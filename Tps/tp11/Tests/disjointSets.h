#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

#include <vector>
#include <unordered_set>
using namespace std;

class DisjointSets
{
public:
    vector<int> set;

    DisjointSets();
    DisjointSets(int n);
    int find(int v) const;
    void unionSets(int root1, int root2);
    void unionSetsImproved(int root1, int root2);
    int getNumberOfSets() const;
};

#endif
