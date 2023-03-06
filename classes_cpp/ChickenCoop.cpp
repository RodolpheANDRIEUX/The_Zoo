#include "../headers/ChickenCoop.h"
#include "../headers/Eagle.h"
#include "../headers/Tiger.h"
#include "../headers/Chicken.h"
#include "../headers/Utils.h"

void ChickenCoop::show() {
    cout << "** CHICKEN COOP **" << endl;
    if (Animals.empty()){
        cout << "10 available places" << endl;
        return;
    }
    for (auto & Animal : Animals){
        Animal->show();
    }
}

int ChickenCoop::getPlace() {
    return 10 - int(Animals.size());
}

pair<int, int> ChickenCoop::receive(Animal *newAnimal) {
    Animals.push_back(newAnimal);
    return {0,0};
}

void ChickenCoop::checkOverCrowding() {
    if (Animals.size() > 10){
        if (Utils::tirage(20)){
            Animals[0]->kill(4);
            Animals.erase(Animals.begin());
            return;
        }
        overCrowded = true;
        return;
    }
    overCrowded = false;
}

void ChickenCoop::dailyRoutine(int date) {
    int nbAnimal = int(Animals.size());
    for (int i = 0 ; i < nbAnimal ; i++){
        Animal* chicken = Animals[i];

        //sick
        //chicken->getSick();

        // eggs
        if (chicken->getFemale() && chicken->isSexuallyPredisposed()){
            if (Utils::tirage(1666)){ // 200 fois par an
                eggs++;
            }
        }

        // birth
        if (chicken->birthDay(date) && eggs != 0){
            for (int j = 0 ; j < ((eggs > 8) ? 8 : eggs) ; j++){
                if (Utils::tirage(1500)){
                    receive(new Chicken("Baby chicken" + to_string(date) , 0, Utils::tirage(1500))); // 1/2 chance male/female
                    cout << "An egg has hatched, a chick is born!" << endl;
                    eggs--;
                }
            }
        }

        //old
        if(chicken->getOld()){
            Animals.erase(Animals.begin() + i);
            i--;
        }
    }
}
