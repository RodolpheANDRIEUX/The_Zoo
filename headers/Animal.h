#include <iostream>
#include <utility>
using namespace std;

#ifndef UNTITLED1_ANIMAL_H
#define UNTITLED1_ANIMAL_H


class Animal {
    string name;
    int age; // days
    bool hungry = false;
    bool sick = false;
    int ShyCoolDown = 30;

protected:
    bool female;
public:
    Animal(string name, int age, bool female) : name(std::move(name)), age(age), female(female){}

    void kill(int deathCode);

    string getName();

    virtual void sayHi() = 0;
};


#endif //UNTITLED1_ANIMAL_H
