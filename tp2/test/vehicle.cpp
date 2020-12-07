#include "vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(string b, int m, int y) : brand(b), month(m), year(y) {}

string Vehicle::getBrand() const {return brand;};
int Vehicle::getYear() const {return year;};

MotorVehicle::MotorVehicle(string b, int m, int y, string f, int cyl) : Vehicle(b,m,y), fuel(f), cylinder(cyl) {}

string MotorVehicle::getFuel() const {return fuel;};

Car::Car(string b, int m, int y, string f, int cyl) : MotorVehicle(b,m,y,f,cyl) {}

Truck::Truck(string b, int m, int y, string f, int cyl, int ml) : MotorVehicle(b,m,y,f,cyl), maximumLoad(ml) {}

Bicycle::Bicycle(string b, int m, int y, string t) : Vehicle(b,m,y), type(t) {}