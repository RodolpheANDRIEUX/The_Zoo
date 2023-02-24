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
        case 201:
        case 202:
        case 203:
        case 204:
        case 205:
        case 206:
        case 207:
            placeTiger(article);
            break;
        case 208:
        case 209:
            placeChicken(article);
            break;
        case 210:
        case 211:
        case 212:
        case 213:
        case 214:
            placeEagle(article);
            break;
        default:
            cout << "error giving due: article doesnt exist!" << endl;
            break;
    }
}

bool Zoo::checkPlaceForTiger() {
    for ( auto habitat : habitats){
        if (dynamic_cast<TigerEnclosure*>(habitat) && habitat->getPlace() > 0){
            return true;
        }
    }
    return false;
}

bool Zoo::checkPlaceForChiken() {
    for ( auto habitat : habitats){
        if (dynamic_cast<ChickenCoop*>(habitat) && habitat->getPlace() > 0){
            return true;
        }
    }
    return false;
}

bool Zoo::checkPlaceForEagle() {
    for ( auto habitat : habitats){
        if (dynamic_cast<EagleAviary*>(habitat) && habitat->getPlace() > 0){
            return true;
        }
    }
    return false;
}

void Zoo::placeTiger(int article) {
    // TODO selectionner un habitat et y creer un tigre
}

void Zoo::placeChicken(int article) {
    // TODO selectionner un habitat et y creer un Poulet
}

void Zoo::placeEagle(int article) {
    // TODO selectionner un habitat et y creer un Aigle
}
