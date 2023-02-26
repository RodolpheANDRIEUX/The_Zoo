#include <algorithm>
#include "../headers/Habitat.h"

int Habitat::getLenAnimals() {
    return this->Animals.size();
}

Animal* Habitat::getAnimal(int index) {
    return Animals[index];
}
int Habitat::getNbAnimals() const {
    return nbAnimal;
}

bool Habitat::checkHabitat() {
    return any_of(Animals.begin(), Animals.end(), [](auto animal){
        return !animal->everythingok();
    });
}
