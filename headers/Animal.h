#include <iostream>
#include <utility>
using namespace std;

#ifndef UNTITLED1_ANIMAL_H
#define UNTITLED1_ANIMAL_H


class Animal {

protected:
    int shyCoolDown = 0;
    bool female;
    int pregnancy = 0;
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

    virtual void getPregnant(Animal* mate) = 0;

    virtual bool isSexuallyPredisposed() = 0;

    void getsShy(int i);

    virtual bool birthDay(int date) = 0;
};


#endif //UNTITLED1_ANIMAL_H
