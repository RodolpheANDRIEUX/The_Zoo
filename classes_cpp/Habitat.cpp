#include <algorithm>
#include "../headers/Habitat.h"

void Habitat::getAnimals(int code) {
    bool isDead;
    for (auto i = Animals.begin(); i != Animals.end(); i++) {
        if ((*i) == NULL) {
            break;
        }
        switch (code) {
            case 1:
                isDead = (*i)->getOld();
                if (isDead) {
                    Animals.erase(i);
                    nbAnimal--;
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
