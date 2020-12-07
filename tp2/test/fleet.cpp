#include "fleet.h"
#include <string>

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
            lower = vehicles[0]->getYear();
    }
    return lower;
}
