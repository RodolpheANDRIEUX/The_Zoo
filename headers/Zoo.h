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
    int age = 0;
    int steaks = 0;
    int grains = 0;

public:
    explicit Zoo(string name) : name(std::move(name)){}

};


#endif //UNTITLED1_ZOO_H
