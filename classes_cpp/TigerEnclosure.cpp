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
    return 2 - int(Animals.size());
}

pair<int, int> TigerEnclosure::receive(Animal *newAnimal) {
    if (dynamic_cast<Tiger*>(newAnimal)){
        Animals.push_back(newAnimal);
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

void TigerEnclosure::dailyRoutine(int date) {
    int nbAnimal = int(Animals.size());
    for (int i = 0; i < nbAnimal; i++) {
        Animal *tiger = Animals[i];

        //sick
        tiger->handleSickness();

        // birth
        if (tiger->birthDay(date)) {
            for (int j = 0; j < 3; j++) {
                if (Utils::tirage(2000)) { // = 2 chance sur 3
                    Animals.push_back(new Tiger("Baby tiger", 0, Utils::tirage(1500))); // 1/2 chance male/female
                    cout << "A baby tiger is born!\n You should put him in a new habitat with his mother." << endl;
                }
            }
            tiger->getsShy(510);
        }

        // old
        if (tiger->getOlder()) {
            Animals.erase(Animals.begin() + i);
            i--; // update iterator
            nbAnimal--;
        }


    }
}
