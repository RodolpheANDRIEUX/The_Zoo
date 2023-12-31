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
    int sickCoolDown = 0;
    bool hungry = false;
    int hungerCoolDown = 0;

public:
    Animal(string name, int age, bool female) : name(std::move(name)), age(age), female(female){}

    void kill(int deathCode);

    string getName();

    bool getFemale() const;

    virtual void show() = 0;

    bool everythingok() const;

    virtual bool getOlder() = 0;

    virtual bool handleSickness() = 0;

    virtual void getPregnant(Animal* mate) = 0;

    virtual bool isSexuallyPredisposed() = 0;

    void getsShy(int i);

    virtual bool birthDay(int date) = 0;

    virtual double eatMeat(double meat) = 0;

    virtual double eatGrains(double grains) = 0;

    virtual double getDailyIncomes(int days) = 0;

    virtual int sell() = 0;

    int menu();

    void rename();

    virtual void interact() = 0;
};


#endif //UNTITLED1_ANIMAL_H
