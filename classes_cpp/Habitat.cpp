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

int Habitat::sellOneAnimal() {
    string userInput;
    int input;

    while (true) {
        int i = 1;
        for (const auto& animal : Animals) {
            cout << "(" << i << ") " << animal->getName() << " +" << animal->sell() << "euros" << endl;
            ++i;
        }
        cout << "(0) back to menu" << endl;
        cin >> userInput;

        try {
            input = stoi(userInput);
        } catch (...) {
            cout << "*unknown input*" << endl;
            continue;
        }

        if (input > 0 && input <= Animals.size()) {
            int price = Animals[input - 1]->sell();
            cout << "You earn " << price << " euro by selling " << Animals[input - 1]->getName() << endl;
            Animals.erase(Animals.begin() + input - 1);
            return price;
        } else if (input == 0) {
            return 0;
        } else {
            cout << "*unknown input*" << endl;
        }
    }
}

int Habitat::sellAllAnimal() {
    int price = 0;
    for (const auto& animal : Animals) {
        price += animal->sell();
        cout << "You sold " << animal->getName() << endl;
    }
    Animals.clear();
    return price;
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

double Habitat::countIncomes(int days) {
    double incomes = 0;
    for (int i = 0; i < getNbAnimals(); i++) {
        incomes += Animals[i]->getDailyIncomes(days);
    }
    return incomes;
}

Animal* Habitat::habitatMenu() {
    int Input;
    do {
        int index = 1;
        for (auto & Animal : Animals){
            cout << "(" << index << ") ";
            Animal->show();
            index++;
        }
        cout << "(0) Go back" << endl;

        string strInput;
        cin >> strInput;
        try {
            Input = stoi(strInput);
        } catch (...) {
            cout << "*unknown input*" << endl;
            Input = -1;
            continue;
        }

        if (Input > 0 && Input <= Animals.size()){
            auto animal = Animals[Input-1];
            if(animal->menu() == 1){ // 1 is "move"
                Animals.erase(Animals.begin() + Input-1);
                return animal; // we return pointer to the animal to move
            }
        }
    } while (Input != 0);
    return nullptr;
}

