#include "Paint.h"

Paint::Paint(string a, string t, int y, double p): author(a), title(t), year(y), price(p) {
}
string Paint::getAuthor() const {
    return author;
}
string Paint::getTitle() const {
    return title;
}
int Paint::getYear() const {
    return year;
}
double Paint::getPrice() const {
    return price;
}
ostream& operator<<(ostream& os, const Paint& p) {
    os << p.author << " " << p.title << " " << p.year << " " << p.price;
    return os;
}

/*
 * PaintCatalogItem
 */
PaintCatalogItem::PaintCatalogItem(Paint* paintItem): paintItem(paintItem) {

}
PaintCatalogItem::PaintCatalogItem(string a, string t, int y, double p) {
    paintItem = new Paint(a, t, y, p);
}
Paint* PaintCatalogItem::getPaint() const {
    return paintItem;
}
string PaintCatalogItem::getAuthor() const {
    return paintItem->author;
}
string PaintCatalogItem::getTitle() const {
    return paintItem->title;
}
int PaintCatalogItem::getYear() const {
    return paintItem->year;
}
double PaintCatalogItem::getPrice() const {
    return paintItem->price;
}

bool PaintCatalogItem::operator==(const PaintCatalogItem& pci) const {
    return (paintItem->author == pci.getAuthor() && paintItem->title == pci.getTitle());
}
ostream& operator<<(ostream& os, const PaintCatalogItem& p) {
    os << p.getAuthor() << " " << p.getTitle() << " " << p.getYear() << " " << p.getPrice();
    return os;
}

/*
 * AuthorRecord
 */
AuthorRecord::AuthorRecord(string a): author(a) {
    availablePaints = 1;
    totalSells = 0.0;
}
AuthorRecord::AuthorRecord(string a, int ap, double ts): author(a), availablePaints(ap), totalSells(ts) {

}
string AuthorRecord::getAuthor() const {
    return author;
}
int AuthorRecord::getAvailablePaints() const {
    return availablePaints;
}
double AuthorRecord::getTotalSells() const {
    return totalSells;
}
int AuthorRecord::addAvaliablePaint() {
    return ++availablePaints;
}
int AuthorRecord::subAvailablePaint() {
    return --availablePaints;
}

void AuthorRecord::setTotalSells(double s) {
    totalSells = s;
}


ExhibitionItem::ExhibitionItem(Paint* paint) {
    toShow = paint;
}
ExhibitionItem::ExhibitionItem(string a, string t, int y, double p) {
    toShow = new Paint(a, t, y, p);
}

Paint* ExhibitionItem::getPaint() const {
    return toShow;
}
string ExhibitionItem::getAuthor() const {
    return toShow->getAuthor();
}
string ExhibitionItem::getTitle() const {
    return toShow->getTitle();
}
int ExhibitionItem::getYear() const {
    return toShow->getYear();
}
double ExhibitionItem::getPrice() const {
    return toShow->getPrice();
}

bool ExhibitionItem::operator==(const ExhibitionItem& pci) const {
    return (toShow->getAuthor() == pci.getAuthor() && toShow->getTitle() == pci.getTitle());
}

ostream& operator<<(ostream& os, const ExhibitionItem& p) {
    os << p.getAuthor() << " " << p.getTitle() << " " << p.getYear() << " " << p.getPrice();
    return os;
}


//------------------------------------------------------------------

bool Paint::operator==(const Paint &p1) const {
    return author == p1.getAuthor() && title == p1.getTitle() && year == p1.getYear() && price == p1.getPrice();
}

//TODO
bool PaintCatalogItem::operator<(const PaintCatalogItem& pci) const {
    if (getYear() > pci.getYear())
        return true;
    else if (getYear() == pci.getYear())
        if (getAuthor() < pci.getAuthor())
            return true;
        else if (getAuthor() == pci.getAuthor())
            if (getTitle() < pci.getTitle())
                return true;
    return false;
}


//TODO
bool ExhibitionItem::operator<(const ExhibitionItem& pci) const {
    if (getYear() > pci.getYear())
        return true;
    else if (getYear() == pci.getYear())
        if (getPrice() < pci.getPrice())
            return true;
    return false;
}

