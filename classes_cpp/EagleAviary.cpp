#include "../headers/EagleAviary.h"
#include "../headers/Utils.h"

void EagleAviary::show() {
    cout << "** EAGLE AVIARY **" << endl;
    if (Animals.empty()){
        cout << "4 available places" << endl;
        return;
    }
    for (auto & Animal : Animals){
        Animal->show();
    }
}

int EagleAviary::getPlace() {
    return 4 - int(Animals.size());
}

pair<int, int> EagleAviary::receive(Animal *newAnimal) {
    Animals.push_back(newAnimal);
    return {0,0};
}

void EagleAviary::checkOverCrowding() {
    if (Animals.size() > 4){
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

void EagleAviary::dailyRoutine(int date) {
    int nbAnimal = int(Animals.size());
    for (int i = 0; i < nbAnimal; i++){
        Animal* eagle = Animals[i];

        //sick
        //(*eagle)->getSick();

        // birth
        if (eagle->birthDay(date)){
            for (int j = 0 ; j < 2 ; j++){
                if (Utils::tirage(1500)){ // = 2 chance sur 3
                    Animals.push_back(new Eagle("Baby eagle", 0, Utils::tirage(1500))); // 1/2 chance male/female
                    cout << "A baby eagle is born!\n you should check if he has the place to live here!" << endl;
                }
            }
        }

        // old
        if (eagle->getOlder()) {
            Animals.erase(Animals.begin() + i);
            i--; // update iterator
            nbAnimal--;
        }
    }
}
