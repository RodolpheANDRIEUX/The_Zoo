
#include "Habitat.h"
#include "Chicken.h"
#include <vector>
using namespace std;
#ifndef UNTITLED1_CHICKENCOOP_H
#define UNTITLED1_CHICKENCOOP_H


class ChickenCoop : public Habitat{
    vector<Chicken*> chickens;
    int Eggs;
public:
    void show() override;

    int getPlace() override;
};


#endif //UNTITLED1_CHICKENCOOP_H
