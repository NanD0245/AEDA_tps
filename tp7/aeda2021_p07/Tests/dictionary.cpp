#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"
#include "bst.h"

using namespace std;

BST<WordMeaning> Dictionary::getWords() const {
    return words;
}

bool WordMeaning::operator < (const WordMeaning &wm1) const {
    return word < wm1.getWord();
}

void Dictionary::readDictionary(ifstream &f)
{
    string word, meaning;
    while (getline(f,word)) {
        getline(f,meaning);
        words.insert(WordMeaning(word,meaning));
    }
}

string Dictionary::searchFor(string word) const
{
    for (auto it = BSTItrIn<WordMeaning>(words); !it.isAtEnd(); it.advance()) {
        if (it.retrieve().getWord() == word) {
            return it.retrieve().getMeaning();
        }

        auto it_after = it;
        it_after.advance();
        if (it_after.isAtEnd())
            throw WordInexistent(it.retrieve(), it.retrieve());
        else if ((it_after.retrieve().getWord() > word)) {
            throw WordInexistent(it.retrieve(), it_after.retrieve());
        }
    }
}

bool Dictionary::correct(string word, string newMeaning)
{
    for (auto it = BSTItrIn<WordMeaning>(words); !it.isAtEnd(); it.advance()) {
        if (it.retrieve().getWord() == word) {
            WordMeaning wm = it.retrieve();
            words.remove(it.retrieve());
            wm.setMeaning(newMeaning);
            words.insert(wm);
            return true;
        }
    }
    WordMeaning wm = WordMeaning(word,newMeaning);
    words.insert(wm);
    return false;
}

void Dictionary::print() const
{
    for (auto it = BSTItrIn<WordMeaning>(words); !it.isAtEnd(); it.advance()) {
        cout << it.retrieve().getWord() << endl << it.retrieve().getMeaning() << endl;
    }
}

