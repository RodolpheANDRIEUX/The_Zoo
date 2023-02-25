//
// Created by rodol on 23/02/2023.
//

#include "../headers/EagleAviary.h"

void EagleAviary::show() {

}

int EagleAviary::getPlace() {
    return 4 - nbAnimal;
}

pair<int, int> EagleAviary::receive(Animal *newAnimal) {
    return {0,0};
}
