#include "zoo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

unsigned Zoo::numAnimals() const {return animals.size();};

unsigned Zoo::numVeterinarians() const {return veterinarians.size();};

void Zoo::addAnimal(Animal *a1) {
    animals.push_back(a1);
}

string Zoo::getInfo() const {
    string s = "";
    for (size_t i=0; i < animals.size(); i++) {
        s += animals[i]->getInfo() + "\n";
    }
    return s;
}

bool Zoo::isYoung(string nameA) {
    for (size_t i=0; i < animals.size(); i++) {
        if (animals[i]->getName() == nameA)
            return animals[i]->isYoung();
    }
    return false;
}

void Zoo::allocateVeterinarians(ifstream &isV) {
    string line, name;
    int count = 0, code;
    while (getline(isV,line)) {
        count++;
        if (count % 2 == 1) {
            name = line;
            name.resize(name.size()-1);
        }
        else {
            stringstream ss(line);
            ss >> code;
            //cout << code << endl;
            auto *v1 = new Veterinary(name,code);
            veterinarians.push_back(v1);
        }

    }
    for (size_t i = 0; i < animals.size(); i++) {
        size_t numvets = veterinarians.size();
        int count=0;
        if (count == numvets)
            count = 0;
        animals[i]->setVeterinary(veterinarians[count]);
        count++;
    }
}

bool Zoo::removeVeterinary(const string& nameV) {
    bool check = false;
    size_t index;
    for (size_t i=0; i < veterinarians.size(); i++) {
        if (veterinarians[i]->getName() == nameV) {
            check = true;
            index = i;
        }
    }
    if (!check)
        return false;
    for (auto & animal : animals) {
        if (animal->getVeterinary()->getName() == nameV) {
            if (index == veterinarians.size())
                index = 0;
            else
                index++;
            animal->setVeterinary(veterinarians[index]);
        }
    }
    veterinarians.erase(veterinarians.begin()+index -1);
    return true;
}

bool Zoo::operator<(Zoo &zoo2) const {
    int age1=0, age2=0;
    for (auto & animal : animals) {
        age1 += animal->getAge();
    }
    for (auto & animal : zoo2.animals) {
        age2 += animal->getAge();
    }
    if (age1 < age2)
        return true;
    return false;
}

