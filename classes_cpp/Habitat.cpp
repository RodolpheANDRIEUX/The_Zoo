#include <algorithm>
#include "../headers/Habitat.h"
#include "../headers/Utils.h"

int Habitat::getNbAnimals() const {
    return int(Animals.size());
}

bool Habitat::checkHabitat() {
    return any_of(Animals.begin(), Animals.end(), [](auto animal){
        return !animal->everythingok();
    });
}

void Habitat::checkReproductions() {
    if (overCrowded){
        return;
    }
    for(auto & male : Animals) { // if there is a valid male
        if (!male->getFemale() && male->isSexuallyPredisposed()){

            for(auto & female : Animals) { // and a valid female
                if (female->getFemale() && female->isSexuallyPredisposed()){


                    female->getPregnant(male);
                    return;
                }
            }
        }
    }
}

void Habitat::steal() {
    if(getNbAnimals() == 0) {
        cout << "Some thieves broke into the zoo but found no animals." << endl;
    } else {
        int animal = Utils::randomInt(getNbAnimals()-1);
        if(Animals[animal] == nullptr) {
            return;
        }
        Animals[animal]->kill(6);
        Animals.erase(Animals.begin() + animal);
    }
}

double Habitat::meatConsumption(double meat) {
    for (int i = 0; i < getNbAnimals(); i++) {
        double conso = Animals[i]->eatMeat(meat);
        if (conso == -1){
            Animals.erase(Animals.begin() + i);
        } else {
            meat -= conso;
        }
    }
    return meat;
}

double Habitat::grainsConsumption(double grains) {
    for (int i = 0; i < getNbAnimals(); i++) {
        double conso = Animals[i]->eatGrains(grains);
        if (conso == -1){
            Animals.erase(Animals.begin() + i);
        } else {
            grains -= conso;
        }
    }
    return grains;
}