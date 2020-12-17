#include "carPark.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>
using namespace std;

CarPark::CarPark(unsigned cap, unsigned nMaxCli): capacity(cap), numMaxClients(nMaxCli)
{
    freePlaces=cap;
}

vector<InfoCard> CarPark::getClients() const
{
    return clients;
}

unsigned CarPark::getNumPlaces() const
{
    return capacity;
}

unsigned CarPark::getNumOccupiedPlaces() const
{
    return capacity-freePlaces;
}

unsigned CarPark::getNumMaxClients() const
{
    return numMaxClients;
}

unsigned CarPark::getNumClients() const
{
    return clients.size();
}

// TODO
int CarPark::clientPosition(const string & name) const
{
    for (size_t i = 0; i < clients.size(); i++) {
        if (clients[i].name == name) {
            return i;
        }
    }
    return -1;
}

// TODO
int CarPark::getFrequency(const string &name) const {
    for (const auto & client : clients) {
        if (client.name == name) {
            return client.frequency;
        }
    }
    throw ClientDoesNotExist(name);
}

// TODO: to modify
bool CarPark::addClient(const string & name)
{
    if (clients.size() == numMaxClients) return false;
    if (clientPosition(name) != -1) return false;
    InfoCard info;
    info.name=name;
    info.present=false;
    info.frequency = 0;
    clients.push_back(info);
    return true;
}

// TODO: to modify
bool CarPark::removeClient(const string & name)
{
    for (vector<InfoCard>::iterator it = clients.begin(); it != clients.end(); it++)
        if ( (*it).name == name ) {
            if ( (*it).present == false ) {
                clients.erase(it);
                return true;
            }
            else return false;
        }
    return false;
}

// TODO: to modify
bool CarPark::enter(const string & name)
{
    if (freePlaces == 0) return false;
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == true) return false;
    clients[pos].present = true;
    freePlaces--;
    clients[pos].frequency++;
    return true;
}

// TODO: to modify
bool CarPark::leave(const string & name)
{
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == false) return false;
    clients[pos].present = false;
    freePlaces++;
    return true;
}


// TODO
InfoCard CarPark::getClientAtPos(unsigned p) const
{
    //InfoCard info;
    if (p <= clients.size())
        return clients[p];
    throw PositionDoesNotExist(p);
    //return info;
}

// TODO
void CarPark::sortClientsByFrequency()
{
    for (size_t i = 1; i < clients.size(); i++) {
        InfoCard tpm = clients[i];
        int j;
        for (j = i; (j > 0 && tpm.frequency > clients[j-1].frequency) || (j > 0 && tpm.frequency == clients[j-1].frequency && tpm.name < clients[j-1].name); j--)
                clients[j] = clients[j-1];
        clients[j] = tpm;
    }
}

// TODO
void CarPark::sortClientsByName()
{
    for (size_t i = 1; i < clients.size(); i++) {
        InfoCard tpm = clients[i];
        int j;
        for (j = i; j > 0 && tpm.name < clients[j-1].name; j--)
            clients[j] = clients[j-1];
        clients[j] = tpm;
    }
}

// TODO
vector<string> CarPark::clientsBetween(unsigned f1, unsigned f2)
{
    vector<string> names;
    sortClientsByFrequency();
    for (auto & client : clients) {
        if (client.frequency >= f1 && client.frequency <= f2)
            names.push_back(client.name);
    }
    return names;
}


// TODO
ostream & operator<<(ostream & os, const CarPark & cp)
{
    for (size_t i = 0; i < cp.clients.size(); i++) {
        bool check = false;
        string pres;
        InfoCard p1 = cp.getClientAtPos(i);
        if (p1.present)
            pres = "presente";
        else
            pres = "falta";
        os << p1.name << " " << pres << " " << p1.frequency << endl;
    }
    return os;
}

/*
2)
 a) ntabs * largura * altura (N^3)

 b) log(N)
*/
