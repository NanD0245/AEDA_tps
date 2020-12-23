/*
 * Cinema.cpp
 */
#include "Cinema.h"

Cinema::Cinema(string nm, unsigned d, unsigned nr): name(nm), distance(d),
		numberOfRooms(nr),timetable(FilmTime(0,NULL, 0))
{}

Cinema::Cinema(string nm, unsigned d, unsigned nr, list<string> ls): name(nm), distance(d),
		numberOfRooms(nr),services(ls), timetable(FilmTime(0,NULL,0))
{}

Cinema::~Cinema() { }

string Cinema::getName() const
{ return name; }

unsigned Cinema::getDistance() const
{ return distance; }

list<string> Cinema::getServices() const
{ return services; }

BST<FilmTime> Cinema::getTimetable() const
{ return timetable; }

void Cinema::addService(string service1)
{ services.push_back(service1); }

void Cinema::addFilmTime(const FilmTime &ft1)
{ timetable.insert(ft1); }


// TODO

bool Cinema::operator<(const Cinema & cr) const
{
	if (distance > cr.getDistance())
	    return true;
	else if (distance == cr.getDistance() && services.size() < cr.services.size() )
	    return true;
	return false;
}


//a1
Film *Cinema::filmAtHour(unsigned &h1) const {
	Film *res = NULL;
	unsigned hours;
    auto it = BSTItrIn<FilmTime>(timetable);
    if (it.isAtEnd() || it.retrieve().getHour() > h1)
        return res;
    while (!it.isAtEnd() && it.retrieve().getHour() < h1) {
        res = it.retrieve().getFilm();
        hours = it.retrieve().getHour();
        it.advance();
    }
    if (it.isAtEnd()) {
        h1 = hours;
        return res;
    }
    if (it.retrieve().getHour() == h1) {
        res = it.retrieve().getFilm();
        return res;
    }
    h1 = hours;
	return res;
}


//a2
bool Cinema::modifyHour(unsigned h1, unsigned room1, unsigned h2) {
    //pouco eficiente
    for (auto it = BSTItrIn<FilmTime>(timetable); !it.isAtEnd(); it.advance()) {
        if (it.retrieve().getRoomID() == room1 && it.retrieve().getHour() == h2) {
            return false;
        }
    }
	for (auto it = BSTItrIn<FilmTime>(timetable); !it.isAtEnd(); it.advance()) {
	    if (it.retrieve().getRoomID() == room1 && it.retrieve().getHour() == h1) {
	        FilmTime a = it.retrieve();
	        timetable.remove(a);
	        a.setHour(h2);
	        timetable.insert(a);
	        return true;
	    }
	}
	return false;
}


//a3
unsigned Cinema::addFilm(Film *f1, unsigned h1) {
	unsigned roomToUse = 0;
    for (auto it = BSTItrIn<FilmTime>(timetable); !it.isAtEnd(); it.advance()) {
        if (it.retrieve().getHour() == h1) {
            roomToUse = it.retrieve().getRoomID();
        }
    }
    if (roomToUse+1>numberOfRooms)
        return 0;
    roomToUse++;
    timetable.insert(FilmTime(h1,f1,roomToUse));
	return roomToUse;
}






