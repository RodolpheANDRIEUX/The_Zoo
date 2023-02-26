#include "../headers/EagleAviary.h"

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
    return 4 - nbAnimal;
}

pair<int, int> EagleAviary::receive(Animal *newAnimal) {
    Animals.push_back(newAnimal);
    nbAnimal++;
    return {0,0};
}
