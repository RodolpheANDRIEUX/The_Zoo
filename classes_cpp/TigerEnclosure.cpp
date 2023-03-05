#include "../headers/TigerEnclosure.h"
#include "../headers/Utils.h"

void TigerEnclosure::show() {
    cout << "** TIGER ENCLOSURE **" << endl;
    if (Animals.empty()){
        cout << "2 available places" << endl;
        return;
    }
    for (auto & Animal : Animals){
        Animal->show();
    }
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

void TigerEnclosure::checkOverCrowding() {
    if (Animals.size() > 2){
        if (Utils::tirage(50)){
            Animals[0]->kill(4);
            Animals.erase(Animals.begin());
            return;
        }
        overCrowded = true;
        return;
    }
    overCrowded = false;
}
