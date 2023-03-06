#include <algorithm>
#include "../headers/Habitat.h"

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
