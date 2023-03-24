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

    virtual int sell() = 0;

    virtual string getType() = 0;

    int sellOneAnimal();

    int sellAllAnimal();

    void steal();

    double meatConsumption(double meat);

    double grainsConsumption(double grains);
};


#endif //UNTITLED1_HABITAT_H
