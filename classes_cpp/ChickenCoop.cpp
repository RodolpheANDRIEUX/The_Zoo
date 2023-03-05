#include "../headers/ChickenCoop.h"
#include "../headers/Eagle.h"
#include "../headers/Tiger.h"
#include "../headers/Chicken.h"
#include "../headers/Utils.h"

void ChickenCoop::show() {
    cout << "** CHICKEN COOP **" << endl;
    if (Animals.empty()){
        cout << "10 available places" << endl;
        return;
    }
    for (auto & Animal : Animals){
        Animal->show();
    }
}

int ChickenCoop::getPlace() {
    return 10 - nbAnimal;
}

pair<int, int> ChickenCoop::receive(Animal *newAnimal) {
    Animals.push_back(newAnimal);
    nbAnimal++;
    return {0,0};
}

void ChickenCoop::checkOverCrowding() {
    if (Animals.size() > 10){
        if (Utils::tirage(20)){
            Animals[0]->kill(4);
            Animals.erase(Animals.begin());
            return;
        }
        overCrowded = true;
        return;
    }
    overCrowded = false;
}
