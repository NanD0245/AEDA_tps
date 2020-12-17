#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_

#include <vector>
#include <list>

using namespace std;

template <class Chamber>
class Hotel {
	std::vector<Chamber *> chambers;
	const unsigned int maxCapacity;
	const std::string city;
    std::list<Chamber> reservationsDone;
public:
	Hotel(int size, std::string municipality);
	~Hotel();
	std::vector<Chamber *> getChambers() const;
	void setChambers(std::vector<Chamber *> chambers);
	int getCapacity() const;
    std::list<Chamber> getReservationsDone() const;
	bool addChamber(Chamber *chamber);
    void addReservationDone(Chamber chamber);
    Chamber* removeChamber(std::string code, int floor);
	float avgArea(int floor) const;
	void sortChambers();
	bool doReservation(std::string code, int floor);
    std::list<Chamber> roomsNeverReserved() const;
};

class NoSuchChamberException {
public:
	NoSuchChamberException() { }
};

template <class Chamber>
Hotel<Chamber>::Hotel(int size, std::string municipality) : maxCapacity(size), city(municipality) {
}

template <class Chamber>
Hotel<Chamber>::~Hotel(){
	typename std::vector<Chamber *>::const_iterator it;
	for (it=chambers.begin(); it!=chambers.end(); it++) {
		delete *it;
	}
}

template<class Chamber>
std::vector<Chamber *> Hotel<Chamber>::getChambers() const {
	return chambers;
}

template<class Chamber>
void Hotel<Chamber>::setChambers(std::vector<Chamber*> chambers) {
	this->chambers = chambers;
}

template<class Chamber>
int Hotel<Chamber>::getCapacity() const {
	return maxCapacity;
}

template<class Chamber>
void Hotel<Chamber>::addReservationDone(Chamber chamber) {
    reservationsDone.push_back(chamber);
}

template<class Chamber>
std::list<Chamber> Hotel<Chamber>::getReservationsDone() const {
    return reservationsDone;
}

//------------------------------------------------------
//------------------------------------------------------

//TODO
template<class Chamber>
bool Hotel<Chamber>::addChamber(Chamber *chamber) {
    if (chambers.size() == maxCapacity)
        return false;
    for (size_t i = 0; i < chambers.size(); i++) {
        if (*chambers[i] == *chamber)
            return false;
    }
    chambers.push_back(chamber);
    return true;
}


//TODO
template<class Chamber>
void Hotel<Chamber>::sortChambers() {
    vector<Chamber *> v1;
    while (!chambers.empty()) {
        int index_min = 0;
        for (size_t i = 0; i < chambers.size(); i++) {
            if (chambers[i]->getCode() < chambers[index_min]->getCode())
                index_min = i;
            else if (chambers[i]->getCode() == chambers[index_min]->getCode() && chambers[i]->getFloor() > chambers[index_min]->getFloor())
                index_min = i;
        }
        v1.push_back(chambers[index_min]);
        chambers.erase(chambers.begin()+index_min);
    }
    chambers = v1;
}

//TODO
template<class Chamber>
Chamber* Hotel<Chamber>::removeChamber(std::string code, int floor) {
    for (size_t i = 0; i < chambers.size(); i++) {
        if (chambers[i]->getCode() == code && chambers[i]->getFloor() == floor) {
            Chamber *a1 = chambers[i];
            chambers.erase(chambers.begin()+i);
            return a1;
        }
    }
    throw NoSuchChamberException();
}

//TODO
class NoSuchFloorException {
    int floor;
public:
    NoSuchFloorException(int floor) : floor(floor) {}
    int getFloor() { return floor;}
};

//TODO
template<class Chamber>
float Hotel<Chamber>::avgArea(int floor) const {
    float area, total_area, counter = 0;
    for (size_t i = 0; i < chambers.size(); i++) {
        area = chambers[i]->getArea();
        if (chambers[i]->getFloor() == floor) {
            total_area += area;
            counter++;
        }
    }
    if (counter != 0) {
        cout << total_area << " " << counter << " " << total_area / counter << endl;
        return total_area / counter;
    }
    else throw NoSuchFloorException(floor);
}

//TODO
template<class Chamber>
bool Hotel<Chamber>::doReservation(std::string code, int floor){
    for (size_t i = 0; i < chambers.size(); i++) {
        if (chambers[i]->getCode() == code && chambers[i]->getFloor() == floor) {
            if (chambers[i]->getReservation())
                return false;
            reservationsDone.push_back(*chambers[i]);
            chambers[i]->setReservation(true);
            return true;
        }
    }
    return false;
}

//TODO
template<class Chamber>
std::list<Chamber> Hotel<Chamber>::roomsNeverReserved() const {
    std::list<Chamber> res;
    for (size_t i = 0; i < chambers.size(); i++) {
        bool check = false;
        for (auto j = reservationsDone.begin(); j != reservationsDone.end(); j++) {
            if (j->getFloor() == chambers[i]->getFloor() && j->getCode() == chambers[i]->getCode())
                check = true;
        }
        if (!check) {
            res.push_back(*chambers[i]);
        }
    }
    return res;
}






#endif /* SRC_HOTEL_H_ */
