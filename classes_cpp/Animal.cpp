#include "../headers/Animal.h"

string Animal::getName() {
    return name;
}

bool Animal::getFemale() const {
    return female;
}

void Animal::kill(int deathCode) {
    switch (deathCode){
        case 1:
            cout << "*" << name << " died from natural causes*" << endl;
            break;
        case 2:
            cout << "*" << name << " has been eaten by a Tiger*" << endl;
            break;
        case 3:
            cout << "*" << name << " escaped the Zoo*" << endl;
            break;
        default:
            cout << "*" << name << " died*" << endl;
            break;
    }
    delete this;
}

void Animal::updateAge() {
    this->age++;
}

int Animal::getAge() {
    return this->age;
}

bool Animal::everythingok() const {
    if (hungry || sick){
        return false;
    }
    return true;
}


