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


// Next Day
void Zoo::skipMenu() {
    string userInput;
    int Input;

    do {
        cout << "(1) One day" << endl;
        cout << "(2) One month" << endl;
        cout << "(3) One year" << endl;
        cout << "(4) Custom" << endl;
        cout << "(0) back to menu" << endl;
        cin >> userInput;
        Input = (int) userInput[0] - 48;
        switch (Input) {
            case 1:
                passTime(1);
                return;
            case 2:
                passTime(30);
                return;
            case 3:
                passTime(360);
                return;
            case 4:
                customMenu();
                return;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    } while (Input != 0);
}

void Zoo::customMenu() {
    string userInput;
    int Input;

    do {
        cout << "\n**** CUSTOM PASS TIME ****" << endl;
        cout << "(0) back to menu" << endl;
        cout << "How much days to skip ?" << endl;
        cin >> userInput;
        Input = (int) userInput[0] - 48;
        switch (Input) {
            case 0:
                break;
            default:
                passTime(Input);
                return;
        }
    } while (Input != 0);
}

void Zoo::passTime(size_t nbDays) {
    for(size_t i = 0; i < nbDays; i++) {
        nextDay();
    }
};

void Zoo::nextDay() {
    // TODO handleSickness

    // TODO handleReproduction

    // TODO handleBirth

    // TODO checkOvercrowding

    // TODO EventFire

    // TODO EventRob

    // TODO EventPests

    // TODO EventSpoiledMeats

    // TODO Eat

    // TODO Old
}
