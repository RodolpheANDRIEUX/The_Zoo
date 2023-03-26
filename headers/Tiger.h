#include <utility>
#include "Animal.h"

#ifndef UNTITLED1_TIGER_H
#define UNTITLED1_TIGER_H


class Tiger : public Animal {

public:
    Tiger(string name, int age, bool female) : Animal(std::move(name), age, female){}

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
};


#endif //UNTITLED1_TIGER_H
