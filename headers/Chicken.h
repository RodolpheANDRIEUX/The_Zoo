#include "Animal.h"

#ifndef UNTITLED1_CHICKEN_H
#define UNTITLED1_CHICKEN_H

class Chicken : public Animal{

public:
    Chicken(string name, int age, bool female) : Animal(std::move(name), age, female){}

    void show() override;

    void getSick();
    bool getOld();
};


#endif //UNTITLED1_CHICKEN_H
