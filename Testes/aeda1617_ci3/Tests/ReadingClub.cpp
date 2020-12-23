/*
 * ReadingClub.cpp
 *
 *  Created on: 11/12/2016
 *      Author: RRossetti
 */

#include "ReadingClub.h"

ReadingClub::ReadingClub(): catalogItems(BookCatalogItem("", "", 0)) {
	//do nothing!
}

ReadingClub::ReadingClub(vector<Book*> books): catalogItems(BookCatalogItem("", "", 0)) {
	this->books = books;
}

void ReadingClub::addBook(Book* book) {
	this->books.push_back(book);
}

void ReadingClub::addBooks(vector<Book*> books) {
	this->books = books;
}

vector<Book*> ReadingClub::getBooks() const{
	return this->books;
}

BookCatalogItem ReadingClub::getCatalogItem(string title, string author) {
	BookCatalogItem itemNotFound("", "", 0);
	BSTItrIn<BookCatalogItem> it(catalogItems);
	while (!it.isAtEnd())
	{
		if( it.retrieve().getTitle() == title && it.retrieve().getAuthor() == author) {
			BookCatalogItem bci(it.retrieve().getTitle(), it.retrieve().getAuthor(), 0);
			bci.setItems(it.retrieve().getItems());
			return bci;
		}
		it.advance();
	}
	return itemNotFound;
}

void ReadingClub::addCatalogItem(Book* book) {
	BookCatalogItem itemNotFound("", "", 0);
	BookCatalogItem bci(book->getTitle(), book->getAuthor(), book->getYear());
	BookCatalogItem bciX = catalogItems.find(bci);
	if(bciX == itemNotFound) {
		bci.addItems(book);
		this->catalogItems.insert(bci);
	}
	else {
		this->catalogItems.remove(bciX);
		bciX.addItems(book);
		this->catalogItems.insert(bciX);
	}
	books.push_back(book);
}

BST<BookCatalogItem> ReadingClub::getCatalogItems() const {
	return this->catalogItems;
}

vector<UserRecord> ReadingClub::getUserRecords() const {
	vector<UserRecord> records;
	HashTabUserRecord::const_iterator it1 = this->userRecords.begin();
	HashTabUserRecord::const_iterator it2 = this->userRecords.end();
	for(; it1 != it2; it1++) {
			records.push_back(*it1);
	}
	return records;
}

void ReadingClub::setUserRecords(vector<UserRecord>& urs) {
	for(int i = 0; i < urs.size(); i++) userRecords.insert(urs[i]);
}

priority_queue<User> ReadingClub::getBestReaderCandidates() const {
	return readerCandidates;
}
void ReadingClub::setBestReaderCandidates(priority_queue<User>& candidates) {
	readerCandidates = candidates;
}



//
// TODO: Part I   - BST
//

void ReadingClub::generateCatalog() {
    for (Book* book : books) {
        BookCatalogItem a(book->getTitle(),book->getAuthor(),book->getYear());
        a.addItems(book);
        bool check = false;
        for (auto it = BSTItrIn<BookCatalogItem>(catalogItems); !it.isAtEnd(); it.advance()) {
            if (it.retrieve() == a) {
                it.retrieve().addItems(book);
                check = true;
            }
        }
        if (!check)
            catalogItems.insert(a);
    }
}

vector<Book*> ReadingClub::getAvailableItems(Book* book) const {
	vector<Book*> temp;
	for (Book* bok : books)
	    if (bok->getTitle() == book->getTitle() && bok->getAuthor() == book->getAuthor() && bok->getReader() == nullptr)
	        temp.push_back(bok);
	/*for (auto it = BSTItrIn<BookCatalogItem>(catalogItems); !it.isAtEnd(); it.advance()) {
	    for (Book* bok : it.retrieve().getItems())
            if (bok->getTitle() == book->getTitle() && bok->getAuthor() == book->getAuthor() && bok->getReader() == nullptr)
                temp.push_back(bok);
	}*/
	return temp;
}

bool ReadingClub::borrowBookFromCatalog(Book* book, User* reader) {
    BookCatalogItem a(book->getTitle(),book->getAuthor(), book->getYear());
	for (auto it = BSTItrIn<BookCatalogItem>(catalogItems); !it.isAtEnd(); it.advance()) {
	    if (it.retrieve() == a) {
	        for (Book* bok: it.retrieve().getItems())
	            if (bok->getReader() == nullptr) {
                    bok->setReader(reader);
                    reader->addReading(book->getTitle(), book->getAuthor());
                    return true;
                }
	    }
	}
	return false;
}


//
// TODO: Part II  - Hash Table
//

void ReadingClub::addUserRecord(User* user) {
    userRecords.insert(user);
}

void ReadingClub::changeUserEMail(User* user, const string& newEMail) {
	for (auto it = userRecords.begin(); it != userRecords.end(); it++) {
	    if (it->getEMail() == user->getEMail()) {
	        UserRecord a = *it;
	        a.setEMail(newEMail);
	        userRecords.erase(it);
	        userRecords.insert(a);
	        return;
	    }
	}
}


//
// TODO: Part III - Priority Queue
//

void ReadingClub::addBestReaderCandidates(const vector<User>& candidates, int min) {
	for (const User& user: candidates)
	    if (user.numReadings() >= min)
	        readerCandidates.push(user);
}

int ReadingClub::awardReaderChampion(User& champion) {
	if (readerCandidates.empty())
	    return 0;
	priority_queue<User> rc = readerCandidates;
	User a = rc.top();
	rc.pop();
	if (rc.empty()) {
	    champion = a;
	    return 1;
	}
	if (a.numReadings() == rc.top().numReadings())
	    return 0;
	champion = a;
	return (int)rc.size()+1;
}
























