
#include "Habitat.h"
#include "Chicken.h"
#include <vector>
using namespace std;
#ifndef UNTITLED1_CHICKENCOOP_H
#define UNTITLED1_CHICKENCOOP_H


class ChickenCoop : public Habitat{
    int Eggs{};

public:
    void show() override;

    int getPlace() override;

    pair<int, int> receive(Animal *newAnimal) override;

    void checkOverCrowding() override;
};


#endif //UNTITLED1_CHICKENCOOP_H
