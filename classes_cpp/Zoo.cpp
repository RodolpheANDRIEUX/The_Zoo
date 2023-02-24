#include "../headers/Zoo.h"
#include "../headers/TigerEnclosure.h"
#include "../headers/ChickenCoop.h"
#include "../headers/EagleAviary.h"

// it's time to pay!
bool Zoo::pay(double price) {
    if (money >= price){
        money -= price;
        return true;
    }
    return false;
}

double Zoo::getMoney() const {
    return money;
}

double Zoo::getGrains() const {
    return grains;
}

double Zoo::getSteaks() const {
    return steaks;
}

// create all new elements (Food, Habitats, Animals) when bought in the store
void Zoo::give(int article, double quantity) {

    switch (article){
        case 1:
            steaks += quantity;
            break;
        case 2:
            grains += quantity;
            break;
        case 101:
            habitats.push_back(new TigerEnclosure);
            break;
        case 102:
            habitats.push_back(new ChickenCoop);
            break;
        case 103:
            habitats.push_back(new EagleAviary);
            break;
        default:
            cout << "error giving due: article doesnt exist!" << endl;
            break;
    }
}

