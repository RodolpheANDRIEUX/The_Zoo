#include "../headers/TigerEnclosure.h"

void TigerEnclosure::show() {

}

int TigerEnclosure::getPlace() {
    return 2 - nbAnimal;
}

pair<int, int> TigerEnclosure::receive(Animal *newAnimal) {
    if (dynamic_cast<Tiger*>(newAnimal)){
        Animals.push_back(newAnimal);
        nbAnimal++;
        return {0, 0};
    }
    if (!Animals.empty()){
        newAnimal->kill(2);
        cout << "The tiger ate well!" << endl;
        return {1, 5};
    }
    newAnimal->kill(3);
    return{2,500};
}
