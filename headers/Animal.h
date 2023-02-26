#include <iostream>
#include <utility>
using namespace std;

#ifndef UNTITLED1_ANIMAL_H
#define UNTITLED1_ANIMAL_H


class Animal {
    int ShyCoolDown = 30;

protected:
    bool female;
    string name;
    int age; // days
    bool sick = false;
    bool hungry = false;

public:
    Animal(string name, int age, bool female) : name(std::move(name)), age(age), female(female){}

    void kill(int deathCode);

    string getName();

    bool getFemale() const;

    virtual void show() = 0;

    bool everythingok() const;
};


#endif //UNTITLED1_ANIMAL_H
