#include <iostream>
#include <utility>
using namespace std;

#ifndef UNTITLED1_ANIMAL_H
#define UNTITLED1_ANIMAL_H


class Animal {
    string name;
    int age; // day
    bool hungry;
    bool sick;
    bool female;
    int ShyCoolDown = 30;

public:
    Animal(string name, int age) : name(std::move(name)), age(age){}

};


#endif //UNTITLED1_ANIMAL_H
