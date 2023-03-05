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
    int sickCoolDown;
    bool hungry = false;

public:
    Animal(string name, int age, bool female) : name(std::move(name)), age(age), female(female){}

    void kill(int deathCode);

    string getName();

    bool getFemale() const;

    virtual void show() = 0;

    bool everythingok() const;

    virtual bool getOld() = 0;

    virtual void getSick() = 0;
};


#endif //UNTITLED1_ANIMAL_H
