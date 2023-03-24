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

int Habitat::sellAnimal() {
    string userInput;
    int Input;

    do {
        int i = 1;
        for(auto animal : Animals) {
            cout << "(" << i << ") " << animal->getName() << endl;
            i++;
        }
        cout << "(0) back to menu" << endl;
        cin >> userInput;
        Input = (int) userInput[0] - 48;

        if(Input <= Animals.size() && Input != 0) {
            int price = Animals[Input-1]->sell();
            if(price > 0) {
                cout << "You earn " << price << " euro by selling " << Animals[Input-1]->getName() << endl;
                Animals.erase(Animals.begin() + Input-1);
                return price;
            } else {
                cout << "You cannot sell." << endl;
                return -1;
            }
        } else if(Input == 0) {
            break;
        } else {
            cout << "*unknown input*" << endl;
        }
    } while (Input != 0);
    return -2;
}

void Habitat::steal() {
    if(getNbAnimals() == 0) {
        cout << "Some thieves broke into the zoo but found no animals." << endl;
    } else {
        int animal = Utils::randomInt(getNbAnimals()-1);
        if(Animals[animal] == nullptr) {
            return;
        }
        Animals[animal]->kill(6);
        Animals.erase(Animals.begin() + animal);
    }
}

double Habitat::meatConsumption(double meat) {
    for (int i = 0; i < getNbAnimals(); i++) {
        double conso = Animals[i]->eatMeat(meat);
        if (conso == -1){
            Animals.erase(Animals.begin() + i);
        } else {
            meat -= conso;
        }
    }
    return meat;
}

double Habitat::grainsConsumption(double grains) {
    for (int i = 0; i < getNbAnimals(); i++) {
        double conso = Animals[i]->eatGrains(grains);
        if (conso == -1){
            Animals.erase(Animals.begin() + i);
        } else {
            grains -= conso;
        }
    }
    return grains;
}