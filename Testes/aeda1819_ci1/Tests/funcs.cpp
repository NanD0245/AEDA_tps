#include <vector>
#include <iostream>
using namespace std;

/*template<class T>
unsigned int numberDifferent (const vector<T> & v1) {
    vector<T> v2;
    for (size_t i = 0; i < v1.size(); i++) {
        bool check = false;
        if (v2.empty())
            v2.push_back(v1[i]);
        else {
            for (size_t j = 0; j < v2.size(); j++) {
                if (v1[i] == v2[j])
                    check = true;
            }
            if (!check)
                v2.push_back(v1[i]);
        }
    }
    return v2.size();
}*/

template<class T>
unsigned int numberDifferent (const vector<T> & v1) {
    int counter = 0;
    for (size_t i = 0; i < v1.size(); i++) {
        bool check = false;
        if (counter == 0)
            counter++;
        else {
            for (size_t j = 0; j < i; j++) {
                if (v1[i] == v1[j])
                    check = true;
            }
            if (!check)
                counter++;
        }
    }
    return counter;
}

