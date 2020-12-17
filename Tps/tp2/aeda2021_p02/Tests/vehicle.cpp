#include "vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(string b, int m, int y) : brand(b), month(m), year(y) {}

string Vehicle::getBrand() const {return brand;};

int Vehicle::info() const {
    cout << "b: " << brand << endl;
    cout << "m: " << month << endl;
    cout << "y: " << year << endl;
    return 3;
}

int Vehicle::getYear() const {return year;};

bool Vehicle::operator<(const Vehicle &v) const {
    if (year < v.year)
        return true;
    if (year == v.year && month < v.month)
        return true;
    return false;
}

//----------------------------------------------------------------

MotorVehicle::MotorVehicle(string b, int m, int y, string f, int cyl) : Vehicle(b,m,y), fuel(f), cylinder(cyl) {}

string MotorVehicle::getFuel() const {return fuel;};

int MotorVehicle::info() const {
    cout << "b: " << brand << endl;
    cout << "m: " << month << endl;
    cout << "y: " << year << endl;
    cout << "f: " << fuel << endl;
    cout << "cyl: " << cylinder << endl;
    return 5;
}

//---------------------------------------------------------------

Car::Car(string b, int m, int y, string f, int cyl) : MotorVehicle(b,m,y,f,cyl) {}

int Car::info() const {
    cout << "b: " << brand << endl;
    cout << "m: " << month << endl;
    cout << "y: " << year << endl;
    cout << "f: " << getFuel() << endl;
    cout << "cyl: " << getCyl() << endl;
    return 5;
}

float Car::calculateTax() const {
    if (getFuel() == "gas") {
        if (getCyl() <= 1000) {
            if (getYear() > 1995)
                return 14.56;
            return 8.10;
        }
        else if (getCyl() <= 1300) {
            if (getYear() > 1995)
                return 29.06;
            return 14.56;
        }
        else if (getCyl() <= 1750) {
            if (getYear() > 1995)
                return 45.15;
            return 22.65;
        }
        else if (getCyl() <= 2600) {
            if (getYear() > 1995)
                return 113.98;
            return 54.89;
        }
        else if (getCyl() <= 3500) {
            if (getYear() > 1995)
                return 181.17;
            return 87.13;
        }
        else {
            if (getYear() > 1995)
                return 320.89;
            return 148.37;
        }
    }
    else {
        if (getCyl() <= 1500) {
            if (getYear() > 1995)
                return 14.56;
            return 8.10;
        }
        else if (getCyl() <= 2000) {
            if (getYear() > 1995)
                return 29.06;
            return 14.56;
        }
        else if (getCyl() <= 3000) {
            if (getYear() > 1995)
                return 45.15;
            return 22.65;
        }
        else {
            if (getYear() > 1995)
                return 113.98;
            return 54.89;
        }
    }
}

//---------------------------------------------------------------

Truck::Truck(string b, int m, int y, string f, int cyl, int ml) : MotorVehicle(b,m,y,f,cyl), maximumLoad(ml) {}

int Truck::info() const {
    cout << "b: " << brand << endl;
    cout << "m: " << month << endl;
    cout << "y: " << year << endl;
    cout << "f: " << getFuel() << endl;
    cout << "cyl: " << getCyl() << endl;
    cout << "ml: " << maximumLoad << endl;
    return 6;
}

float Truck::calculateTax() const {
    if (getFuel() == "gas") {
        if (getCyl() <= 1000) {
            if (getYear() > 1995)
                return 14.56;
            return 8.10;
        }
        else if (getCyl() <= 1300) {
            if (getYear() > 1995)
                return 29.06;
            return 14.56;
        }
        else if (getCyl() <= 1750) {
            if (getYear() > 1995)
                return 45.15;
            return 22.65;
        }
        else if (getCyl() <= 2600) {
            if (getYear() > 1995)
                return 113.98;
            return 54.89;
        }
        else if (getCyl() <= 3500) {
            if (getYear() > 1995)
                return 181.17;
            return 87.13;
        }
        else {
            if (getYear() > 1995)
                return 320.89;
            return 148.37;
        }
    }
    else {
        if (getCyl() <= 1500) {
            if (getYear() > 1995)
                return 14.56;
            return 8.10;
        }
        else if (getCyl() <= 2000) {
            if (getYear() > 1995)
                return 29.06;
            return 14.56;
        }
        else if (getCyl() <= 3000) {
            if (getYear() > 1995)
                return 45.15;
            return 22.65;
        }
        else {
            if (getYear() > 1995)
                return 113.98;
            return 54.89;
        }
    }
}

//---------------------------------------------------------------

Bicycle::Bicycle(string b, int m, int y, string t) : Vehicle(b,m,y), type(t) {}

int Bicycle::info() const {
    cout << "b: " << brand << endl;
    cout << "m: " << month << endl;
    cout << "y: " << year << endl;
    cout << "t: " << type << endl;
    return 4;
}

float Bicycle::calculateTax() const {return 0;};

//---------------------------------------------------------------