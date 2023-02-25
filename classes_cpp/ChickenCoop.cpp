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
    return {0,0};
}
