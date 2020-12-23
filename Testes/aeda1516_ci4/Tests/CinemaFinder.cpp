/*
 * CinemaFinder.cpp
 */

#include "CinemaFinder.h"
#include "Cinema.h"
#include "Film.h"
#include <algorithm>

CinemaFinder::CinemaFinder() { }

CinemaFinder::~CinemaFinder() { }

void CinemaFinder::addFilm(Film *f1) {
	FilmPtr fp1;
	fp1.film = f1;
	films.insert(fp1);
}

void CinemaFinder::addCinema(const Cinema &c1)
{ cinemas.push(c1); }

tabHFilm CinemaFinder::getFilms() const
{ return films; }

priority_queue<Cinema> CinemaFinder::getCinemas() const
{ return cinemas; }


// TODO


//b1
#include <algorithm>
list<string> CinemaFinder::filmsWithActor(string actorName) const {
	list<string> res;

	for (FilmPtr film: films)
	    for (string actor : film.film->getActors())
	        if (actor == actorName)
	            res.push_back(film.film->getTitle());
	/*for (FilmPtr film: films)
	    if (find(film.film->getActors().begin(), film.film->getActors().end(), actorName) != film.film->getActors().end())
	        res.push_back(film.film->getTitle());*/

	return res;
}


//b2
void CinemaFinder::addActor(string filmTitle, string actorName) {
    bool exists = false;
    for (FilmPtr film: films) {
        if (film.film->getTitle() == filmTitle) {
            exists = true;
            bool check = false;
            for (string actor : film.film->getActors()) {
                if (actor == actorName)
                    check = true;
            }
            if (!check)
                film.film->addActor(actorName);
        }
    }
    if (!exists) {
        FilmPtr a;
        a.film = new Film(filmTitle);
        a.film->addActor(actorName);
        films.insert(a);
    }
}


//c1
string CinemaFinder::nearestCinema(string service1) const {
	string cName = "";
	if (cinemas.empty()) return cName;
    unsigned distance = -1;
	priority_queue<Cinema> c = cinemas;
	while (!c.empty()) {
	    cout << c.top().getName() << " - " << c.top().getDistance() << endl;
	    bool check = false;
	    for (string service: c.top().getServices()) {
	        cout << service << endl;
            if (service == service1)
                check = true;
	    }
        if (check && (distance == -1 || c.top().getDistance() < distance)) {
            distance = c.top().getDistance();
            cName = c.top().getName();
        }
        c.pop();
	}

	return cName;
}


//c2
void CinemaFinder::addServiceToNearestCinema(string service1, unsigned maxDistance) {
    if (!cinemas.empty())
        cout << cinemas.top().getDistance() << endl;
    if (cinemas.empty() || cinemas.top().getDistance() > maxDistance)
        throw CinemaNotFound();

    Cinema a = cinemas.top();
    cinemas.pop();
    a.addService(service1);
    cinemas.push(a);
}
