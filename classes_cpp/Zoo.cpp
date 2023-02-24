//
// Created by rodol on 23/02/2023.
//

#include "../headers/Zoo.h"

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

void Zoo::giveGrains(double quantity) {
    grains += quantity;
}

void Zoo::giveSteaks(double quantity) {
    steaks += quantity;
}