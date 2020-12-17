#include "Gallery.h"
#include <ostream>
using namespace std;

Gallery::Gallery(vector<Paint*> c): catalog(PaintCatalogItem("", "", 0, 0.00)), collection(c) {

}

vector<Paint*> Gallery::getCollection() const {
    return collection;
}

void Gallery::setCollection(vector<Paint*> c) {
    collection = c;
}

priority_queue<ExhibitionItem> Gallery::getPaintsToShow() const {
    return paintsToShow;
}
HashTableAuthorRecord Gallery::getAuthorRecords () const {
    return  authorRecords;
}

void Gallery::addAuthorRecord(AuthorRecord ar) {
    authorRecords.insert(ar);
}

void Gallery::generateCatalog() {
    catalog.makeEmpty();
    for(int i = 0; i < collection.size(); i++) {
        catalog.insert(collection[i]);
    }
}

BST<PaintCatalogItem> Gallery::getCatalog() const {
    return catalog;
}


void Gallery::prepareExhibition() {
    while( !paintsToShow.empty())
        paintsToShow.pop();
    for(int i = 0; i < collection.size(); i++) {
        ExhibitionItem ei(collection[i]);
        paintsToShow.push(ei);
    }
}

//-------------------------------------------------------------------------------

vector<Paint*> Gallery::getPaintsBy(string a) const {
    vector<Paint*> tmp;
    for (auto it = BSTItrIn<PaintCatalogItem>(catalog); !it.isAtEnd(); it.advance()) {
        if (it.retrieve().getAuthor() == a)
            tmp.push_back(it.retrieve().getPaint());
    }
    return tmp;
}

vector<Paint*> Gallery::getPaintsBetween(int y1, int y2) const {
    vector<Paint*> tmp;
    for (auto it = BSTItrIn<PaintCatalogItem>(catalog); !it.isAtEnd(); it.advance()) {
        if (it.retrieve().getYear() >= y1 && it.retrieve().getYear() <= y2)
            tmp.push_back(it.retrieve().getPaint());
    }
    return tmp;
}

//TODO
bool Gallery::updateTitle(Paint* p, string tnew) {
    for (auto it = BSTItrIn<PaintCatalogItem>(catalog); !it.isAtEnd(); it.advance()) {
        if (*it.retrieve().getPaint() == *p)  {
            it.retrieve().getPaint()->setTitle(tnew);
            return true;
        }
    }
    return false;
}


//TODO
int Gallery::recordAvailablePainters() { //carrega a tabela de dispersao com AuthorRecords
    for (Paint* paint : collection) {
        bool check = false;
        for (auto it = authorRecords.begin(); it != authorRecords.end(); it++) {
            if (it->getAuthor() == paint->getAuthor()) {
                AuthorRecord a = *it;
                authorRecords.erase(it);
                a.addAvaliablePaint();
                authorRecords.insert(a);
                it = authorRecords.find(a);
                check = true;
            }
        }
        if (!check)
            authorRecords.insert(paint->getAuthor());
    }
    return authorRecords.size();
}

//TODO
double Gallery::totalSells() const {
    double sells = 0.0;
    for (auto it = authorRecords.begin(); it != authorRecords.end(); it++) {
        sells += it->getTotalSells();
    }
    return sells;
}

//TODO
#include <algorithm>
/*double Gallery::sellPaint(string a, string t) {
    Paint* p1;
    double price;
    for (Paint* paint : collection) {
        if (paint->getAuthor() == a && paint->getTitle() == t) {
            price = paint->getPrice();
            p1 = paint;
            auto it = authorRecords.begin();
            while (it != authorRecords.end() && it->getAuthor() == paint->getAuthor())
                it++;
            AuthorRecord ar = *it;
            authorRecords.erase(it);
            ar.subAvailablePaint();
            ar.setTotalSells(ar.getTotalSells()+paint->getPrice());
            authorRecords.insert(ar);
            break;
        }
    }
    auto it = find(collection.begin(), collection.end(),p1);
    collection.erase(it);
    return price;
}*/

double Gallery::sellPaint(string a, string t) {
    double price=0;

    for (size_t i = 0; i < collection.size(); i++) {
        if (collection[i]->getAuthor() == a && collection[i]->getTitle() == t) {
            price = collection[i]->getPrice();
            for (auto it = authorRecords.begin(); it != authorRecords.end(); it++) {
                if (it->getAuthor() == a) {
                    AuthorRecord ar = *it;
                    authorRecords.erase(it);
                    ar.subAvailablePaint();
                    ar.setTotalSells(ar.getTotalSells() + collection[i]->getPrice());
                    authorRecords.insert(ar);
                    break;
                }
            }
            collection.erase(collection.begin() + i);
            break;
        }
    }
    return price;
}

//TODO
vector<Paint*> Gallery::nBestExibition(int n, int maxPerYear) {  //escolhe as N mais caras pinturas, dos anos mais antigos, para realizar uma exposição
    vector<Paint*> tmp;
    vector<ExhibitionItem> v1;
    int year, counter = 0;
    while (!paintsToShow.empty()) {
        year = paintsToShow.top().getYear();
        if (tmp.size() == n)
            break;
        if (tmp.empty() || year != tmp[tmp.size()-1]->getYear())
            counter = 0;
        else counter++;
        if (counter < maxPerYear)
            tmp.push_back(paintsToShow.top().getPaint());
        else v1.push_back(paintsToShow.top());
        paintsToShow.pop();
    }
    for (ExhibitionItem a : v1)
        paintsToShow.push(a);
    return tmp;
}

//TODO
int Gallery::itemExibitionOrder(string a, string t) {
    int ordem = 1;
    vector<ExhibitionItem> v1;
    while (!paintsToShow.empty() && !(paintsToShow.top().getAuthor() == a && paintsToShow.top().getTitle() == t)) {
        v1.push_back(paintsToShow.top());
        paintsToShow.pop();
        ordem++;
    }
    if (paintsToShow.empty())
        ordem = 0;
    for (ExhibitionItem a : v1)
        paintsToShow.push(a);
    return ordem;
}

