#ifndef CARPARK_H_
#define CARPARK_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ClientDoesNotExist;
class PositionDoesNotExist;

class InfoCard {
public:
    string name;
    bool present;
    int frequency;
};

class CarPark {
    unsigned freePlaces;
    const unsigned  capacity;
    vector<InfoCard> clients;
    const unsigned numMaxClients;
public:
    CarPark(unsigned cap, unsigned nMaxCli);
    unsigned getNumPlaces() const;
    unsigned getNumMaxClients() const;
    unsigned getNumOccupiedPlaces() const;
    vector<InfoCard> getClients() const;
    unsigned getNumClients() const;
    bool addClient(const string & name);
    bool removeClient(const string & name);
    bool enter(const string & name);
    bool leave(const string & name);
    int clientPosition(const string & name) const;
    friend ostream & operator<<(ostream & os, const CarPark & cp);
    int getFrequency(const string &name) const;
    InfoCard getClientAtPos(unsigned p) const;
    void sortClientsByFrequency();
    void sortClientsByName();
    vector<string> clientsBetween(unsigned f1, unsigned f2);
};

class ClientDoesNotExist {
    string false_name;
public:
    ClientDoesNotExist(const string &name_doesnt_exist) : false_name(name_doesnt_exist) {}
    string getName() const {return false_name;};
};

class PositionDoesNotExist {
    unsigned index;
public:
    PositionDoesNotExist(unsigned p) {
        index = p;
    }
    unsigned getPosition() const {return index;};
};

#endif /*CARPARK_H_*/
