#include <iostream>
using namespace std;
#include <utility>
#include <vector>
#include "Habitat.h"
#include "Animal.h"

#ifndef UNTITLED1_ZOO_H
#define UNTITLED1_ZOO_H


class Zoo {
    string name;
    double money = 80000;
    vector<Habitat*> habitats;
    int Days = 0;
    double steaks = 0;
    double grains = 0;

public:
    explicit Zoo(string name) : name(std::move(name)){}

    bool pay(double price);

    double getMoney() const;

    double getSteaks() const;

    double getGrains() const;

    void give(int article, double quantity);

    bool checkPlaceForTiger();

    bool checkPlaceForChiken();

    bool checkPlaceForEagle();

    void placeAnimal(Animal *animal);

    void gameOver() const;
};


#endif //UNTITLED1_ZOO_H
