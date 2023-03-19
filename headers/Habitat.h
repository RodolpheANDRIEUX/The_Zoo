#ifndef UNTITLED1_HABITAT_H
#define UNTITLED1_HABITAT_H


#include "Animal.h"
#include <vector>

class Habitat {

protected:
    bool overCrowded = false;
    vector<Animal*> Animals;

public:
    virtual void show() = 0;

    virtual int getPlace() = 0;

    virtual pair<int, int> receive(Animal *newAnimal) = 0;

    int getNbAnimals() const;

    bool checkHabitat();

    void checkReproductions();

    virtual void checkOverCrowding() = 0;

    virtual void dailyRoutine(int date) = 0;

    void steal();

    double meatConsomation();

    double grainsConsomation();
};


#endif //UNTITLED1_HABITAT_H
