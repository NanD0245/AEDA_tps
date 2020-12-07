#include "fleet.h"
#include <string>
#include <iostream>

using namespace std;

vector<Vehicle *> Fleet::getVehicles() const {
    return vehicles;
}

void Fleet::addVehicle(Vehicle *v1) {vehicles.push_back(v1);};

int Fleet::numVehicles() const {return vehicles.size();};

int Fleet::lowestYear() const {
    int lower;
    if (vehicles.size() == 0)
        return 0;
    lower = vehicles[0]->getYear();
    for (size_t y=1; y < vehicles.size(); y++) {
        if (vehicles[0]->getYear() < lower)
            lower = vehicles[y]->getYear();
    }
    return lower;
}

vector<Vehicle *> Fleet::operator()(int yearM) const {
    vector<Vehicle *> v1;
    for (size_t i=0; i < vehicles.size(); i++)
        if (vehicles[i]->getYear() == yearM)
            v1.push_back(vehicles[i]);
    return v1;
}

float Fleet::totalTax() const {
    float total = 0.0;
    for (size_t i = 0; i < vehicles.size(); i++) {
        total += vehicles[i]->calculateTax();
    }
    return total;
}

unsigned Fleet::removeOldVehicles(int y1) {
    unsigned removed = 0;
    bool check1 = true;
    bool check2;
    while (check1) {
        check2 = true;
        for (size_t i = 0; i < vehicles.size(); i++) {
            if (vehicles[i]->getYear() <= y1) {
                vehicles.erase(vehicles.begin() + i);
                removed++;
                check2 = false;
                break;
            }
        }
        if (check2)
            check1 = false;
    }
    return removed;
}

//----------------------------------------------------

ostream & operator<<(ostream & o, const Fleet & f) {
    for (size_t i=0; i<f.vehicles.size();i++) {
        o << f.vehicles[i]->info() << endl;
    }
    return o;
}

