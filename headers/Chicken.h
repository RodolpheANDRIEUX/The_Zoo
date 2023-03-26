#include "Animal.h"
#include "../headers/Utils.h"

#ifndef UNTITLED1_CHICKEN_H
#define UNTITLED1_CHICKEN_H

class Chicken : public Animal{

public:
    Chicken(string name, int age, bool female) : Animal(std::move(name), age, female){}

    void show() override;

    bool handleSickness() override;

    bool getOlder() override;

    bool isSexuallyPredisposed() override;

    void getPregnant(Animal *mate) override;

    bool birthDay(int date) override;

    double eatMeat(double meat);

    double eatGrains(double grains);

    int sell() override;

    double getDailyIncomes(int days) override;

    void interact() override;
};


#endif //UNTITLED1_CHICKEN_H
