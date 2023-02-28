#include <algorithm>
#include "../headers/Habitat.h"

void Habitat::getAnimals(int code) {
    for(int i = 0; i < Animals.size(); i++) {
        switch(code)
        {
            case 1:
                if(Animals[i] != nullptr) {
                    Animals[i]->getOld();
                }
                break;
            case 2:
                break;
            default:
                cout << "*Préciser un 'code' pour la méthode 'getAnimals'*" << endl;
                break;
        }
    }
}
int Habitat::getNbAnimals() const {
    return nbAnimal;
}

bool Habitat::checkHabitat() {
    return any_of(Animals.begin(), Animals.end(), [](auto animal){
        return !animal->everythingok();
    });
}
