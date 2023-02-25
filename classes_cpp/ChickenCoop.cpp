#include "../headers/ChickenCoop.h"
#include "../headers/Eagle.h"
#include "../headers/Tiger.h"
#include "../headers/Chicken.h"

void ChickenCoop::show() {

}

int ChickenCoop::getPlace() {
    return 10 - nbAnimal;
}

pair<int, int> ChickenCoop::receive(Animal *newAnimal) {

    if (dynamic_cast<Tiger*>(newAnimal)){
        Animals.push_back(newAnimal);
        return {0, 0};
    }
    if (dynamic_cast<Eagle*>(newAnimal)){
        Animals.push_back(newAnimal);
        cout << "OMGGG" << endl;
        return {0, 0};
    }
    if (dynamic_cast<Chicken*>(newAnimal)){
        Animals.push_back(newAnimal);
        cout << "OMGGG" << endl;
        return {0, 0};
    }
}
