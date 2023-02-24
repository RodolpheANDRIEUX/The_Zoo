#include <iostream>
using namespace std;
#include <utility>
#include <vector>
#include "Habitat.h"

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

    [[nodiscard]] double getMoney() const;

    [[nodiscard]] double getSteaks() const;

    [[nodiscard]] double getGrains() const;

    void giveGrains(double quantity);

    void giveSteaks(double quantity);
};


#endif //UNTITLED1_ZOO_H
