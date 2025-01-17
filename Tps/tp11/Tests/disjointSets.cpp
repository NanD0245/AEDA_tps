#include "disjointSets.h"

DisjointSets::DisjointSets()
{}

// create n disjoint sets (one for each item)
DisjointSets::DisjointSets(int n)
{
   for (int i=0 ; i<n; i++)
        set.push_back(-1);
}

// Find the root of the set in which element v belongs
int DisjointSets::find(int v) const
{
    if (set[v] <0)
        return v;
    return find(set[v]);
}

// Perform Union of two subsets
void DisjointSets::unionSets(int root1, int root2)
{
    set[root2] = root1;
}

void DisjointSets::unionSetsImproved(int root1, int root2) {
    if ( set[root2] < set[root1] )
        set[root1] = root2;
    else {
        if ( set[root1] == set[root2] )
            --set[root1];
        set[root2] = root1;
    }
}

#include <algorithm>
int DisjointSets::getNumberOfSets() const
{
    return count(set.begin(), set.end(),-1);

}

