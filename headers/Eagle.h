#include "Animal.h"

#ifndef UNTITLED1_EAGLE_H
#define UNTITLED1_EAGLE_H


class Eagle : public Animal {
    Eagle* mate = nullptr;

public:
    Eagle(string name, int age, bool female) : Animal(std::move(name), age, female){}

    void show() override;

    bool handleSickness() override;

    bool getOlder() override;

    bool isSexuallyPredisposed() override;

    void marry(Eagle* newMate);

    void getPregnant(Animal *withMate) override;

    bool birthDay(int date) override;

    double eatMeat(double meat);

    double eatGrains(double grains);

    int sell() override;

    double getDailyIncomes(int days) override;

    void interact() override;
};


#endif //UNTITLED1_EAGLE_H
