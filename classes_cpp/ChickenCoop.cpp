#include "../headers/ChickenCoop.h"
#include "../headers/Eagle.h"
#include "../headers/Tiger.h"
#include "../headers/Chicken.h"

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
