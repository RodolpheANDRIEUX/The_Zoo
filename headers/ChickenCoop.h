
#include "Habitat.h"
#include "Chicken.h"
#include <vector>
using namespace std;
#ifndef UNTITLED1_CHICKENCOOP_H
#define UNTITLED1_CHICKENCOOP_H


class ChickenCoop : public Habitat{
    int eggs= 0;

public:
    void show() override;

    int getPlace() override;

    pair<int, int> receive(Animal *newAnimal) override;

    void checkOverCrowding() override;

    void dailyRoutine(int date) override;
};


#endif //UNTITLED1_CHICKENCOOP_H
