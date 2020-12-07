#include "animal.h"
#include <sstream>
#include <iostream>
using namespace std;

Animal::Animal(string name, int age) : name(name), age(age) {
    if (age < youngest)
        youngest = age;
}

string Animal::getName() const {return name;};

int Animal::getAge() const {return age;};

void Animal::setVeterinary(Veterinary *vet) {this->vet = vet;};

Veterinary *Animal::getVeterinary() const {return vet;};

int Animal::getYoungest() {return youngest;};

string Animal::getInfo() const {return name + ", " + to_string(age);};

//------------------------------------------------

Dog::Dog(string name, int age, string breed) : Animal(name,age), breed(breed) {
    //cout << youngest << endl;
}

bool Dog::isYoung() const {return (getAge()<5);};

string Dog::getInfo() const {
    if (getVeterinary() != nullptr) {
        string a = vet->getName();
        //a.resize(9)
        return name + ", " + to_string(age) + ", " + vet->getInfo() + ", " + breed;
    }
    return name + ", " + to_string(age) + ", " + breed;
}

//------------------------------------------------

Flying::Flying(int maxv, int maxa) : maxVelocity(maxv), maxAltitude(maxa) {}

string Flying::getInfo() const {return to_string(maxVelocity) + ", " + to_string(maxAltitude);};

//------------------------------------------------

Bat::Bat(string name, int age, int maxv, int maxa) : Animal(name,age), Flying(maxv,maxa) {}

bool Bat::isYoung() const {return (getAge()<4);};

string Bat::getInfo() const {
    if (getVeterinary() != nullptr)
        return name + ", " + to_string(age) + ", " + vet->getInfo();
    return name + ", " + to_string(age) + ", " + Flying::getInfo();
}

