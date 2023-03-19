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
        cout << "Des voleurs sont rentrées dans le zoo mais n'ont pas trouvé d'animaux." << endl;
    } else {
        int animal = Utils::randomInt(getNbAnimals()-1);
        if(Animals[animal] == nullptr) {
            return;
        }
        cout << "Des voleurs ont emportés un animal !" << endl;
        Animals.erase(Animals.begin() + animal);
    }
}