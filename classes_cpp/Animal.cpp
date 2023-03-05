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
        case 4:
            cout << "*" << name << " died from overcrowding in his habitat*" << endl;
            break;
        default:
            cout << "*" << name << " died*" << endl;
            break;
    }
    delete this;
}

bool Animal::everythingok() const {
    if (hungry || sick){
        return false;
    }
    return true;
}

void Animal::getPregnant() {
    cout << "test ok" << endl;
    pregnancy = 1; // first day
}

void Animal::getsShy(int i) {
    shyCoolDown = i;
}



