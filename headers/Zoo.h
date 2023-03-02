#include <iostream>
using namespace std;
#include <utility>
#include <vector>
#include "Habitat.h"
#include "Animal.h"
#include "Tiger.h"
#include "Chicken.h"
#include "Eagle.h"

#ifndef UNTITLED1_ZOO_H
#define UNTITLED1_ZOO_H


class Zoo {
    string name;
    double money = 80000;
    vector<Habitat*> habitats;
    int Days = 0;
    double steaks = 760;
    double grains = 51;

public:
    explicit Zoo(string name) : name(std::move(name)){
        give(101,1);
        habitats[0]->receive(new Tiger("Michel", 180, false));
        habitats[0]->receive(new Tiger("Jackie", 180, true));
        give(102,2);
        for (int i = 0; i < 10 ; i++){
            habitats[1+i%2]->receive(new Chicken("Cocote" + to_string(i) , 6*30, true));
        }
        habitats[1]->receive(new Chicken("GigaChicken", 6*30, false));
        give(103,1);
        habitats[3]->receive(new Eagle("Rakan", 6*30, false));
        habitats[3]->receive(new Eagle("Xayah", 6*30, true));
    }

    bool pay(double price);

    double getMoney() const;

    double getSteaks() const;

    double getGrains() const;

    void give(int article, double quantity);

    bool checkPlaceForTiger();

    bool checkPlaceForChicken();

    bool checkPlaceForEagle();

    void placeAnimal(Animal *animal);

    void show();

    void gameOver() const;

    // Pass time
    void skipMenu();

    void customMenu();

    void passTime(size_t nbDays);

    // Event
    void nextDay();

    void handleSickness();

    void eventOld();
};


#endif //UNTITLED1_ZOO_H
